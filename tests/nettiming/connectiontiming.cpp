/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/


#include "connect.h"

#include "doctest/doctest.h"

#include <deque>
#include <string>
#include <utility>
#include <vector>


namespace
{
	class TestClock final : public NetTiming::MillisecondClock
	{
		public:
			NetTiming::Milliseconds Now(void) const override {return(Current);}
			NetTiming::Milliseconds Current = 0;
	};


	class TestTransport
	{
		public:
			explicit TestTransport(TestClock const & clock) : Clock(clock) {}

			void Send(ConnectionClass * destination, char const * buffer, int length)
			{
				if (Connected) {
					Packets.push_back({destination, {buffer, buffer + length}, Clock.Now() + OneWayDelay});
				}
			}

			void Deliver(void)
			{
				while (!Packets.empty() && Packets.front().Arrival <= Clock.Now()) {
					Packet packet = std::move(Packets.front());
					Packets.pop_front();
					packet.Destination->Receive_Packet(packet.Bytes.data(), static_cast<int>(packet.Bytes.size()));
				}
			}

			bool Connected = true;
			NetTiming::Milliseconds OneWayDelay = 5;

		private:
			struct Packet
			{
				ConnectionClass * Destination;
				std::vector<char> Bytes;
				NetTiming::Milliseconds Arrival;
			};

			TestClock const & Clock;
			std::deque<Packet> Packets;
	};


	class TestConnection final : public ConnectionClass
	{
		public:
			TestConnection(TestClock const & clock, TestTransport & transport, int capacity)
				: ConnectionClass(capacity, capacity, sizeof(int), 1234, 6, -1, 120, 0, &clock), Transport(transport)
			{
				Init();
			}

			void Read(void)
			{
				int payload;
				int length;
				while (Get_Packet(&payload, sizeof(payload), &length)) {
					Received.push_back(payload);
				}
			}

			NetTiming::RttEstimator const & Rtt(void) const {return(RoundTripEstimator);}

			ConnectionClass * Remote = nullptr;
			std::vector<int> Received;

		private:
			int Send(char * buffer, int length, void *, int) override
			{
				Transport.Send(Remote, buffer, length);
				return(1);
			}

			TestTransport & Transport;
	};


	class ConnectionFixture
	{
		public:
			explicit ConnectionFixture(int capacity) : Transport(Clock), First(Clock, Transport, capacity), Second(Clock, Transport, capacity)
			{
				First.Remote = &Second;
				Second.Remote = &First;
			}

			void Service(void)
			{
				Transport.Deliver();
				First.Service();
				Second.Service();
				First.Read();
				Second.Read();
			}

			void Advance_To(NetTiming::Milliseconds time)
			{
				while (Clock.Current < time) {
					Clock.Current++;
					Service();
				}
			}

			TestClock Clock;
			TestTransport Transport;
			TestConnection First;
			TestConnection Second;
	};


	void Establish_Rtt(ConnectionFixture & fixture)
	{
		int payload = 0;
		CHECK_MESSAGE(fixture.First.Send_Packet(&payload, sizeof(payload), true) != 0, "first peer queues its initial packet");
		CHECK_MESSAGE(fixture.Second.Send_Packet(&payload, sizeof(payload), true) != 0, "second peer queues its initial packet");
		fixture.Service();
		fixture.Advance_To(10);
		CHECK_MESSAGE(fixture.First.Rtt().Smoothed_Rtt() == 10, "both connections measure the initial round trip");
		CHECK_MESSAGE(fixture.Second.Rtt().Smoothed_Rtt() == 10, "both connections measure the initial round trip");
	}


	TEST_CASE("a connection without an RTT sample keeps the legacy retry delay, and a retry alone does not sample")
	{
		ConnectionFixture fixture(2);
		fixture.Transport.Connected = false;
		int payload = 0;
		fixture.First.Send_Packet(&payload, sizeof(payload), true);
		fixture.Service();
		CHECK_MESSAGE(fixture.First.Queue->Get_Send(0)->SendCount == 1, "initial send needs no elapsed clock time");
		fixture.Advance_To(99);
		CHECK_MESSAGE(fixture.First.Queue->Get_Send(0)->SendCount == 1, "unsampled connection retains its legacy retry delay");
		fixture.Advance_To(100);
		CHECK_MESSAGE(fixture.First.Queue->Get_Send(0)->SendCount == 2, "unsampled connection retries after six engine ticks");
		CHECK_MESSAGE(!fixture.First.Rtt().Has_Sample(), "retry alone does not establish RTT");
	}


	void Check_Saturated_Outage_Recovery(int capacity)
	{
		ConnectionFixture fixture(capacity);
		Establish_Rtt(fixture);
		CHECK_MESSAGE(fixture.First.Queue->Num_Receive() == 1, "read packets retain the latest sequence entry");
		CHECK_MESSAGE(fixture.Second.Queue->Num_Receive() == 1, "read packets retain the latest sequence entry");
		fixture.Advance_To(100);
		fixture.Transport.Connected = false;
		for (int payload = 1; payload <= capacity; payload++) {
			CHECK_MESSAGE(fixture.First.Send_Packet(&payload, sizeof(payload), true) != 0, "first peer fills its send queue");
			CHECK_MESSAGE(fixture.Second.Send_Packet(&payload, sizeof(payload), true) != 0, "second peer fills its send queue");
		}
		fixture.Service();
		fixture.Advance_To(3000);
		CHECK_MESSAGE(fixture.First.Is_Bad(), "the outage times out both peers");
		CHECK_MESSAGE(fixture.Second.Is_Bad(), "the outage times out both peers");
		fixture.Transport.Connected = true;
		fixture.Advance_To(8000);

		std::vector<int> expected;
		for (int payload = 0; payload <= capacity; payload++) {
			expected.push_back(payload);
		}
		CHECK_MESSAGE(fixture.First.Received == expected, "first peer receives the complete ordered backlog");
		CHECK_MESSAGE(fixture.Second.Received == expected, "second peer receives the complete ordered backlog");
		CHECK_MESSAGE(fixture.First.Queue->Num_Send() == 0, "restored connectivity drains both send queues");
		CHECK_MESSAGE(fixture.Second.Queue->Num_Send() == 0, "restored connectivity drains both send queues");
		CHECK_MESSAGE(!fixture.First.Is_Bad(), "both connections recover from timeout");
		CHECK_MESSAGE(!fixture.Second.Is_Bad(), "both connections recover from timeout");
	}


	TEST_CASE("after a full outage, both peers time out, then recover and receive the complete ordered backlog")
	{
		SUBCASE("with two-packet queues") { Check_Saturated_Outage_Recovery(2); }
		SUBCASE("with 32-packet queues") { Check_Saturated_Outage_Recovery(32); }
	}


	TEST_CASE("a link that slows down becomes measurable through the production retry capture and delivers every packet")
	{
		ConnectionFixture fixture(2);
		Establish_Rtt(fixture);
		fixture.Transport.OneWayDelay = 300;
		for (int payload = 1; payload <= 12; payload++) {
			CHECK_MESSAGE(fixture.First.Send_Packet(&payload, sizeof(payload), true) != 0, "slower link accepts another packet");
			fixture.Service();
			fixture.Advance_To(fixture.Clock.Now() + 1000);
		}
		CHECK_MESSAGE(fixture.First.Rtt().Smoothed_Rtt() > 100, "production retry capture lets the slower link become measurable");
		CHECK_MESSAGE(fixture.First.Rtt().Has_Sample(), "slower link obtains an unambiguous estimate");
		CHECK_MESSAGE(!fixture.First.Rtt().Is_Provisional(), "slower link obtains an unambiguous estimate");
		CHECK_MESSAGE(fixture.Second.Received.size() == 13, "slower link delivers every packet");
		CHECK_MESSAGE(fixture.First.Queue->Num_Send() == 0, "slower link completes its acknowledgements");
	}
}

