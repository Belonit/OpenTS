/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/


#include "nettiming.h"

#include "doctest/doctest.h"

#include <algorithm>
#include <cstdint>
#include <initializer_list>
#include <limits>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


namespace
{
	class FakeClock final : public NetTiming::MillisecondClock
	{
		public:
			NetTiming::Milliseconds Now(void) const override {return(Current);}
			void Set(NetTiming::Milliseconds now) {Current = now;}

		private:
			NetTiming::Milliseconds Current = 0;
	};


	class FakeTransport
	{
		public:
			void Send(NetTiming::Milliseconds now)
			{
				Clock.Set(now);
				FirstSend = now;
				LastSend = now;
				TransmissionCount = 1;
				BaseRto = NetTiming::Initial_Retry_Timeout(Estimator.Retransmit_Timeout(), Timeout());
			}

			bool Retry(NetTiming::Milliseconds now)
			{
				Clock.Set(now);
				NetTiming::RetransmitState const state{FirstSend, LastSend, BaseRto, TransmissionCount};
				if (!NetTiming::Evaluate_Retry(state, now, BaseRto, Timeout(), true, true).Send) {
					return(false);
				}
				LastSend = now;
				TransmissionCount++;
				Estimator.Note_Retransmit(BaseRto);
				return(true);
			}

			bool Acknowledge(NetTiming::Milliseconds now)
			{
				Clock.Set(now);
				return(Estimator.Acknowledge(FirstSend, TransmissionCount, Clock));
			}

			NetTiming::RttEstimator const & Rtt(void) const {return(Estimator);}
			NetTiming::Milliseconds Base_Rto(void) const {return(BaseRto);}
			NetTiming::Milliseconds Timeout(void) const
			{
				return(NetTiming::Connection_Timeout(Estimator.Smoothed_Rtt(), Estimator.Retransmit_Timeout()));
			}

		private:
			FakeClock Clock;
			NetTiming::RttEstimator Estimator;
			NetTiming::Milliseconds FirstSend = 0;
			NetTiming::Milliseconds LastSend = 0;
			NetTiming::Milliseconds BaseRto = NetTiming::MINIMUM_RTO;
			unsigned int TransmissionCount = 0;
	};


	TEST_CASE("the RTT estimator smooths samples by an eighth and a quarter, keeps out a retransmitted one, and resets")
	{
		using namespace NetTiming;

		RttEstimator estimator;
		CHECK_MESSAGE(!estimator.Has_Sample(), "estimator starts empty");
		CHECK_MESSAGE(estimator.Add_Sample(100), "first sample accepted");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 100u, "first smoothed RTT");
		CHECK_MESSAGE(estimator.Rtt_Variation() == 50u, "first variation");
		CHECK_MESSAGE(estimator.Retransmit_Timeout() == 300u, "first RTO");

		CHECK_MESSAGE(estimator.Add_Sample(140), "second sample accepted");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 105u, "alpha one eighth");
		CHECK_MESSAGE(estimator.Rtt_Variation() == 48u, "beta one quarter");
		CHECK_MESSAGE(estimator.Retransmit_Timeout() == 297u, "updated RTO");

		CHECK_MESSAGE(!estimator.Add_Sample(900, true), "retransmitted sample rejected");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 105u, "Karn keeps smoothed RTT");
		CHECK_MESSAGE(estimator.Retransmit_Timeout() == 297u, "Karn keeps RTO");

		estimator.Reset();
		CHECK_MESSAGE(!estimator.Has_Sample(), "reset clears estimator");
		CHECK_MESSAGE(estimator.Retransmit_Timeout() == MINIMUM_RTO, "reset restores RTO");
	}


	TEST_CASE("the RTO clamps to its minimum and maximum")
	{
		using namespace NetTiming;

		RttEstimator minimum;
		minimum.Add_Sample(0);
		CHECK_MESSAGE(minimum.Retransmit_Timeout() == MINIMUM_RTO, "minimum RTO clamp");

		RttEstimator maximum;
		maximum.Add_Sample(2000);
		CHECK_MESSAGE(maximum.Retransmit_Timeout() == MAXIMUM_RTO, "maximum RTO clamp");
	}


	TEST_CASE("unequal links keep independent RTOs")
	{
		using namespace NetTiming;

		RttEstimator fast_link;
		RttEstimator slow_link;
		fast_link.Add_Sample(50);
		slow_link.Add_Sample(300);
		CHECK(fast_link.Retransmit_Timeout() < slow_link.Retransmit_Timeout());
	}


	TEST_CASE("an acknowledgement and a retry are timed across the clock wrap")
	{
		using namespace NetTiming;

		FakeClock clock;
		clock.Set(0x00000020u);
		RttEstimator estimator;
		CHECK_MESSAGE(estimator.Acknowledge(0xfffffff0u, 1, clock), "wrap sample accepted");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 48u, "wrap elapsed");
		CHECK_MESSAGE(!estimator.Acknowledge(0, 2, clock), "retransmitted acknowledgement ignored");

		CHECK_MESSAGE(Retransmit_Is_Due(0xfffffff0u, 0x00000054u, 100, 0), "wrapped retry due");
		CHECK_MESSAGE(!Retransmit_Is_Due(0xfffffff0u, 0x00000040u, 100, 0), "wrapped retry not early");
	}


	TEST_CASE("the retransmit delay doubles per retry, clamped to the RTO range and the connection timeout")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Retransmit_Delay(100, 0) == 100u, "base retry");
		CHECK_MESSAGE(Retransmit_Delay(100, 1) == 200u, "first backoff");
		CHECK_MESSAGE(Retransmit_Delay(100, 2) == 400u, "second backoff");
		CHECK_MESSAGE(Retransmit_Delay(100, 3) == 800u, "third backoff");
		CHECK_MESSAGE(Retransmit_Delay(100, 4) == 1600u, "fourth backoff");
		CHECK_MESSAGE(Retransmit_Delay(100, 20) == MAXIMUM_RTO, "backoff saturation");
		CHECK_MESSAGE(Retransmit_Delay(1, 0) == MINIMUM_RTO, "base clamp");
		CHECK_MESSAGE(Retransmit_Delay(500, 8, 4250) == 4250u, "backoff reaches connection timeout");
	}


	TEST_CASE("the connection timeout follows the RTT between its minimum and ceiling")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Connection_Timeout(0, MINIMUM_RTO) == 2000u, "connection timeout minimum");
		CHECK_MESSAGE(Connection_Timeout(500, MINIMUM_RTO) == 4250u, "connection timeout follows RTT");
		CHECK_MESSAGE(Connection_Timeout(10000, MAXIMUM_RTO) == 30000u, "connection timeout ceiling");
	}


	TEST_CASE("the first retry keeps a small RTO, bounded by a quarter of the timeout")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Initial_Retry_Timeout(300, 2000) == 300u, "first retry keeps a small RTO");
		CHECK_MESSAGE(Initial_Retry_Timeout(1600, 2000) == 500u, "first retry is bounded by a quarter of the timeout");
		CHECK_MESSAGE(Initial_Retry_Timeout(1600, 300) == MINIMUM_RTO, "first retry bound keeps the floor");
		CHECK_MESSAGE(Initial_Retry_Timeout(2055, Connection_Timeout(2015, 2055)) == 2055u, "slow link keeps its RTO under a long timeout");
		CHECK_MESSAGE(Retransmit_Delay(500, 0) + Retransmit_Delay(500, 1) == 1500u, "bounded first retry allows three sends before the timeout");
	}


	TEST_CASE("a backed off RTO extends the connection timeout under its hard ceiling")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Connection_Timeout(10, 800) == 3200u, "backed off RTO extends the timeout");
		CHECK_MESSAGE(Connection_Timeout(10, MAXIMUM_RTO) == 16000u, "maximum RTO fits below the timeout ceiling");
		CHECK_MESSAGE(Connection_Timeout(10, 0xffffffffu) == MAXIMUM_CONNECTION_TIMEOUT, "large RTO calculation keeps the hard ceiling");
	}


	TEST_CASE("a packet captures the full backed off RTO and sends twice more before the extended timeout")
	{
		using namespace NetTiming;

		for (Milliseconds rto : {100u, 500u, 800u, 1600u, MAXIMUM_RTO}) {
			INFO("RTO ", rto);
			Milliseconds const timeout = Connection_Timeout(10, rto);
			Milliseconds const initial_retry = Initial_Retry_Timeout(rto, timeout);
			CHECK_MESSAGE(initial_retry == rto, "packet captures the full backed off RTO");

			RetransmitState state{1000, 1000, initial_retry, 1};
			RetryDecision decision = Evaluate_Retry(state, 1000 + rto, rto, timeout, true, true);
			CHECK_MESSAGE(decision.Send, "second transmission precedes the extended timeout");
			CHECK_MESSAGE(!decision.TimedOut, "second transmission precedes the extended timeout");
			state.LastSend += rto;
			state.TransmissionCount++;
			decision = Evaluate_Retry(state, 1000 + 3 * rto, rto, timeout, true, true);
			CHECK_MESSAGE(decision.Send, "third transmission precedes the extended timeout");
			CHECK_MESSAGE(!decision.TimedOut, "third transmission precedes the extended timeout");
			CHECK_MESSAGE(Evaluate_Retry(state, 1000 + timeout, rto, timeout, true, true).TimedOut, "extended timeout still expires");
		}
	}


	TEST_CASE("a link that slows down still produces a clean sample, with a bounded timeout")
	{
		using namespace NetTiming;

		for (Milliseconds round_trip : {600u, 1500u}) {
			INFO("round trip ", round_trip);
			FakeTransport transport;
			transport.Send(0);
			CHECK_MESSAGE(transport.Acknowledge(10), "latency increase starts from a measured fast link");

			bool measured = false;
			for (unsigned int packet = 0; packet < 10 && !measured; packet++) {
				Milliseconds const sent_at = 1000 + packet * (round_trip + 1000);
				transport.Send(sent_at);
				for (Milliseconds elapsed = 1; elapsed < round_trip; elapsed++) {
					transport.Retry(sent_at + elapsed);
				}
				measured = transport.Acknowledge(sent_at + round_trip);
			}

			CHECK_MESSAGE(measured, "slower link eventually produces a clean sample");
			CHECK_MESSAGE(transport.Rtt().Smoothed_Rtt() > 10, "clean sample updates the stale fast-link RTT");
			CHECK_MESSAGE(transport.Base_Rto() > round_trip, "clean sample arrives before the captured retry");
			CHECK_MESSAGE(transport.Timeout() <= MAXIMUM_CONNECTION_TIMEOUT, "recovery keeps the connection timeout bounded");
		}
	}


	TEST_CASE("a new packet sends at once, and an adaptive one waits its captured RTO and then its backoff")
	{
		using namespace NetTiming;

		RetransmitState state;
		RetryDecision decision = Evaluate_Retry(state, 1000, 800, 2000, true, true);
		CHECK_MESSAGE(decision.Send, "new packet sends immediately");
		CHECK_MESSAGE(!decision.TimedOut, "new packet sends immediately");

		state = {1000, 1000, 100, 1};
		CHECK_MESSAGE(!Evaluate_Retry(state, 1099, 800, 2000, true, true).Send, "adaptive packet keeps captured RTO");
		CHECK_MESSAGE(Evaluate_Retry(state, 1100, 800, 2000, true, true).Send, "adaptive packet sends at captured RTO");

		state = {1000, 1100, 100, 2};
		CHECK_MESSAGE(!Evaluate_Retry(state, 1299, 800, 2000, true, true).Send, "adaptive retry waits through backoff");
		CHECK_MESSAGE(Evaluate_Retry(state, 1300, 800, 2000, true, true).Send, "adaptive retry sends after backoff");
	}


	TEST_CASE("a fixed channel uses the current retry delay and does not back off")
	{
		using namespace NetTiming;

		RetransmitState const state{1000, 1000, 100, 4};
		CHECK_MESSAGE(!Evaluate_Retry(state, 1399, 400, 2000, true, false).Send, "fixed channel uses current retry delay");
		RetryDecision const decision = Evaluate_Retry(state, 1400, 400, 2000, true, false);
		CHECK_MESSAGE(decision.Send, "fixed channel does not back off");
		CHECK_MESSAGE(!decision.TimedOut, "fixed channel does not back off");
	}


	TEST_CASE("a connection timeout flags the link, but a packet still retries when its backoff allows")
	{
		using namespace NetTiming;

		RetransmitState state{1000, 1900, 100, 1};
		RetryDecision decision = Evaluate_Retry(state, 3000, 100, 2000, true, true);
		CHECK_MESSAGE(decision.TimedOut, "connection timeout flags the link");
		CHECK_MESSAGE(decision.Send, "timed-out packet still retries when due");
		decision = Evaluate_Retry(state, 3000, 100, 2000, false, true);
		CHECK_MESSAGE(!decision.TimedOut, "disabled connection timeout still retries");
		CHECK_MESSAGE(decision.Send, "disabled connection timeout still retries");

		state = {1000, 2950, 100, 1};
		decision = Evaluate_Retry(state, 3000, 100, 2000, true, true);
		CHECK_MESSAGE(decision.TimedOut, "timed-out packet waits for its backoff");
		CHECK_MESSAGE(!decision.Send, "timed-out packet waits for its backoff");
	}


	TEST_CASE("a timed-out packet waits for the connection timeout cap")
	{
		using namespace NetTiming;

		RetransmitState const state{1000, 5000, 100, 6};
		CHECK_MESSAGE(!Evaluate_Retry(state, 6999, 100, 2000, true, true).Send, "timed-out packet waits for the connection timeout cap");
		CHECK_MESSAGE(Evaluate_Retry(state, 7000, 100, 2000, true, true).Send, "timed-out packet retries at the connection timeout cap");
	}


	TEST_CASE("a retry decision handles the clock wrap")
	{
		using namespace NetTiming;

		RetransmitState const state{0xffffff00u, 0xfffffff0u, 100, 1};
		CHECK(Evaluate_Retry(state, 0x00000054u, 800, 2000, true, true).Send);
	}


	TEST_CASE("reordered acknowledgements both sample, and a duplicate ambiguous one is excluded")
	{
		using namespace NetTiming;

		FakeClock clock;
		RttEstimator reordered;
		clock.Set(1200);
		CHECK_MESSAGE(reordered.Acknowledge(1100, 1, clock), "newer packet ACK samples first");
		clock.Set(1300);
		CHECK_MESSAGE(reordered.Acknowledge(1000, 1, clock), "older packet ACK can sample after reordering");
		CHECK_MESSAGE(reordered.Smoothed_Rtt() == 125u, "reordered samples keep alpha filter");
		CHECK_MESSAGE(reordered.Rtt_Variation() == 88u, "reordered samples keep beta filter");

		clock.Set(2000);
		CHECK_MESSAGE(!reordered.Acknowledge(1500, 2, clock), "duplicate ambiguous ACK is excluded by Karn");
		CHECK_MESSAGE(reordered.Smoothed_Rtt() == 125u, "ambiguous ACK leaves SRTT unchanged");
	}


	TEST_CASE("jitter raises the variation and keeps the RTO bounded")
	{
		using namespace NetTiming;

		RttEstimator jitter;
		for (Milliseconds sample : {20u, 400u, 35u, 350u, 40u}) {
			jitter.Add_Sample(sample);
		}
		CHECK_MESSAGE(jitter.Rtt_Variation() > 0, "jitter raises variation");
		CHECK_MESSAGE(jitter.Retransmit_Timeout() >= MINIMUM_RTO, "jittered RTO remains bounded");
		CHECK_MESSAGE(jitter.Retransmit_Timeout() <= MAXIMUM_RTO, "jittered RTO remains bounded");
	}


	TEST_CASE("a lost packet retransmits at the base RTO, then after exponential backoff")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(!Retransmit_Is_Due(1000, 1099, 100, 0, 2000), "loss does not retransmit before the base RTO");
		CHECK_MESSAGE(Retransmit_Is_Due(1000, 1100, 100, 0, 2000), "first loss retransmits at the base RTO");
		CHECK_MESSAGE(!Retransmit_Is_Due(1100, 1299, 100, 1, 2000), "second loss waits for exponential backoff");
		CHECK_MESSAGE(Retransmit_Is_Due(1100, 1300, 100, 1, 2000), "second loss retransmits at doubled RTO");
	}


	TEST_CASE("a clean acknowledgement publishes its RTT")
	{
		using namespace NetTiming;

		FakeTransport clean_transport;
		clean_transport.Send(1000);
		CHECK_MESSAGE(clean_transport.Acknowledge(1080), "fake transport accepts a clean ACK sample");
		CHECK_MESSAGE(clean_transport.Rtt().Smoothed_Rtt() == 80u, "fake transport publishes clean RTT");
	}


	TEST_CASE("an ambiguous first acknowledgement seeds a provisional sample that a clean one replaces")
	{
		using namespace NetTiming;

		FakeTransport lossy_transport;
		lossy_transport.Send(1000);
		CHECK_MESSAGE(lossy_transport.Retry(1100), "fake transport retries a lost packet");
		CHECK_MESSAGE(lossy_transport.Acknowledge(1180), "ambiguous first ACK seeds a provisional sample");
		CHECK_MESSAGE(lossy_transport.Rtt().Smoothed_Rtt() == 180u, "provisional seed is the elapsed upper bound");
		CHECK_MESSAGE(lossy_transport.Rtt().Is_Provisional(), "provisional seed is the elapsed upper bound");
		lossy_transport.Send(2000);
		CHECK_MESSAGE(lossy_transport.Base_Rto() == 540u, "provisional seed paces the next packet");
		CHECK_MESSAGE(lossy_transport.Acknowledge(2080), "clean sample replaces the provisional seed");
		CHECK_MESSAGE(lossy_transport.Rtt().Smoothed_Rtt() == 80u, "replaced smoothed RTT");
		CHECK_MESSAGE(lossy_transport.Rtt().Rtt_Variation() == 40u, "replaced variation");
		CHECK_MESSAGE(lossy_transport.Rtt().Retransmit_Timeout() == 240u, "replaced RTO");
		CHECK_MESSAGE(!lossy_transport.Rtt().Is_Provisional(), "replaced estimate is measured");
	}


	TEST_CASE("the RTO backs off once per packet until a clean sample gets through")
	{
		using namespace NetTiming;

		FakeTransport transport;
		transport.Send(0);
		CHECK_MESSAGE(transport.Acknowledge(10), "fast link samples cleanly");
		CHECK_MESSAGE(transport.Rtt().Retransmit_Timeout() == MINIMUM_RTO, "fast link floors the RTO");

		// The link now takes 500 ms, so every packet is retransmitted before its ACK arrives.
		transport.Send(1000);
		CHECK_MESSAGE(transport.Retry(1100), "first era retransmits at the floor RTO");
		CHECK_MESSAGE(transport.Rtt().Retransmit_Timeout() == 200u, "first era doubles the RTO");
		CHECK_MESSAGE(transport.Retry(1300), "same era retransmits again");
		CHECK_MESSAGE(transport.Rtt().Retransmit_Timeout() == 200u, "same era does not double twice");
		CHECK_MESSAGE(!transport.Acknowledge(1500), "ambiguous ACK is excluded");

		transport.Send(2000);
		CHECK_MESSAGE(transport.Base_Rto() == 200u, "new packet captures the backed off RTO");
		CHECK_MESSAGE(transport.Retry(2200), "second era retransmits");
		CHECK_MESSAGE(transport.Rtt().Retransmit_Timeout() == 400u, "second era doubles the RTO");

		transport.Send(3000);
		CHECK_MESSAGE(transport.Base_Rto() == 400u, "third packet captures the backed off RTO");
		CHECK_MESSAGE(transport.Retry(3400), "third era retransmits");
		CHECK_MESSAGE(transport.Rtt().Retransmit_Timeout() == 800u, "third era doubles the RTO");

		// The RTO now exceeds the real round trip, so a first transmission is acknowledged.
		transport.Send(4000);
		CHECK_MESSAGE(transport.Acknowledge(4500), "backed off RTO lets a clean sample through");
		CHECK_MESSAGE(transport.Rtt().Smoothed_Rtt() == 71u, "recovered smoothed RTT");
		CHECK_MESSAGE(transport.Rtt().Rtt_Variation() == 126u, "recovered variation");
		CHECK_MESSAGE(transport.Rtt().Retransmit_Timeout() == 575u, "recovered RTO covers the slower link");
		CHECK_MESSAGE(transport.Rtt().Has_Sample(), "recovered estimate is measured");
		CHECK_MESSAGE(!transport.Rtt().Is_Provisional(), "recovered estimate is measured");
	}


	TEST_CASE("a provisional seed waits for a clean sample, which replaces it rather than blending")
	{
		using namespace NetTiming;

		FakeClock clock;
		RttEstimator estimator;
		CHECK_MESSAGE(!estimator.Acknowledge(0, 0, clock), "unsent packet never samples");
		CHECK_MESSAGE(!estimator.Has_Sample(), "unsent acknowledgement leaves the estimator empty");

		clock.Set(2000);
		CHECK_MESSAGE(estimator.Acknowledge(0, 2, clock), "two-second link seeds through a retransmitted ACK");
		CHECK_MESSAGE(estimator.Has_Sample(), "seed is provisional");
		CHECK_MESSAGE(estimator.Is_Provisional(), "seed is provisional");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 2000u, "seed smoothed RTT");
		CHECK_MESSAGE(estimator.Retransmit_Timeout() == MAXIMUM_RTO, "seed RTO reaches the ceiling");

		clock.Set(4500);
		CHECK_MESSAGE(!estimator.Acknowledge(1000, 3, clock), "second ambiguous ACK does not move a provisional seed");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 2000u, "seed unchanged by a second ambiguous ACK");

		clock.Set(6900);
		CHECK_MESSAGE(estimator.Acknowledge(5000, 1, clock), "clean sample replaces the seed");
		CHECK_MESSAGE(estimator.Smoothed_Rtt() == 1900u, "clean sample replaces rather than blends");
		CHECK_MESSAGE(!estimator.Is_Provisional(), "replaced seed is measured");

		clock.Set(9000);
		CHECK_MESSAGE(!estimator.Acknowledge(7000, 2, clock), "Karn applies once the estimate is measured");
	}


	TEST_CASE("a provisional estimate backs off like a measured one, and a reset clears it")
	{
		using namespace NetTiming;

		FakeClock clock;
		RttEstimator backed_off;
		clock.Set(300);
		backed_off.Acknowledge(0, 2, clock);
		CHECK_MESSAGE(backed_off.Retransmit_Timeout() == 900u, "provisional RTO");
		backed_off.Note_Retransmit(900);
		CHECK_MESSAGE(backed_off.Retransmit_Timeout() == 1800u, "provisional estimate backs off like a measured one");

		backed_off.Reset();
		CHECK_MESSAGE(!backed_off.Is_Provisional(), "reset clears the provisional flag");
		CHECK_MESSAGE(!backed_off.Has_Sample(), "reset clears the provisional flag");
	}


	TEST_CASE("a retransmission does not invent a sample")
	{
		using namespace NetTiming;

		RttEstimator unsampled;
		unsampled.Note_Retransmit(MINIMUM_RTO);
		CHECK_MESSAGE(!unsampled.Has_Sample(), "retransmission does not invent a sample");
		CHECK_MESSAGE(unsampled.Retransmit_Timeout() == MINIMUM_RTO, "unsampled RTO is unchanged");
	}


	TEST_CASE("the backoff doubles the RTO up to its ceiling")
	{
		using namespace NetTiming;

		RttEstimator ceiling;
		ceiling.Add_Sample(300);
		CHECK_MESSAGE(ceiling.Retransmit_Timeout() == 900u, "sampled RTO");
		ceiling.Note_Retransmit(900);
		CHECK_MESSAGE(ceiling.Retransmit_Timeout() == 1800u, "backoff doubles below the ceiling");
		ceiling.Note_Retransmit(1800);
		CHECK_MESSAGE(ceiling.Retransmit_Timeout() == 3600u, "backoff doubles again below the ceiling");
		ceiling.Note_Retransmit(3600);
		CHECK_MESSAGE(ceiling.Retransmit_Timeout() == MAXIMUM_RTO, "backoff clamps at the ceiling");
		ceiling.Note_Retransmit(MAXIMUM_RTO);
		CHECK_MESSAGE(ceiling.Retransmit_Timeout() == MAXIMUM_RTO, "backoff stays at the ceiling");
	}


	// A packet captured during backoff can double a freshly lowered RTO once.
	TEST_CASE("a packet captured during backoff doubles a freshly lowered RTO once")
	{
		using namespace NetTiming;

		RttEstimator recovered;
		recovered.Add_Sample(300);
		recovered.Note_Retransmit(900);
		recovered.Add_Sample(300);
		CHECK_MESSAGE(recovered.Retransmit_Timeout() == 752u, "clean sample lowers the RTO");
		recovered.Note_Retransmit(1800);
		CHECK_MESSAGE(recovered.Retransmit_Timeout() == 1504u, "stale capture doubles the RTO once");
	}


	TEST_CASE("each network game speed has its frame rate, and an unknown one is held to the fastest")
	{
		using namespace NetTiming;

		unsigned int const expected[] = { 60u, 45u, 30u, 20u, 15u, 12u, 10u };
		for (int speed = 0; speed < 7; speed++) {
			CHECK_MESSAGE(Game_Speed_Frame_Rate(speed) == expected[speed], ("speed " + std::to_string(speed) + " frame rate"));
		}
		CHECK_MESSAGE(Game_Speed_Frame_Rate(7) == 60u, "an unknown speed is held to the fastest rate");
		CHECK_MESSAGE(Game_Speed_Frame_Rate(-1) == 60u, "a negative speed is held to the fastest rate");
	}


	TEST_CASE("each solo game speed has its frame rate, and an unknown one runs unlimited")
	{
		using namespace NetTiming;

		// Zero is no limit at all.
		unsigned int const expected[] = { 0u, 60u, 45u, 30u, 20u, 15u, 10u };
		for (int speed = 0; speed < 7; speed++) {
			CHECK_MESSAGE(Solo_Game_Speed_Frame_Rate(speed) == expected[speed], ("solo speed " + std::to_string(speed) + " frame rate"));
		}
		CHECK_MESSAGE(Solo_Game_Speed_Frame_Rate(7) == 0u, "an unknown solo speed runs unlimited");
		CHECK_MESSAGE(Solo_Game_Speed_Frame_Rate(-1) == 0u, "a negative solo speed runs unlimited");
	}


	TEST_CASE("the frame pacer spreads a second over the frames of each rate, a millisecond apart at most")
	{
		using namespace NetTiming;

		for (unsigned int rate : { 60u, 45u, 30u, 20u, 15u, 12u, 10u, 7u }) {
			INFO("rate ", rate);
			FramePacer pacer;
			Milliseconds total = 0;
			Milliseconds shortest = 1000;
			Milliseconds longest = 0;
			for (unsigned int frame = 0; frame < rate; frame++) {
				Milliseconds const wait = pacer.Next_Wait(rate);
				total += wait;
				shortest = std::min(shortest, wait);
				longest = std::max(longest, wait);
			}
			CHECK_MESSAGE(total == 1000u, (std::to_string(rate) + " frames last a second"));
			CHECK_MESSAGE(longest - shortest <= 1, (std::to_string(rate) + " frames differ by a millisecond at most"));
		}
	}


	TEST_CASE("the frame pacer waits for no rate, and starts its average again on a change of rate")
	{
		using namespace NetTiming;

		FramePacer pacer;

		CHECK_MESSAGE(pacer.Next_Wait(0) == 0u, "no rate means no wait");
		pacer.Next_Wait(60);
		CHECK_MESSAGE(pacer.Next_Wait(45) == 22u, "a change of rate starts the average again");
	}


	TEST_CASE("the census tracks active peers, keeps their freshest reports, and lets reports expire")
	{
		using namespace NetTiming;

		TimingReportCensus census;
		CHECK_MESSAGE(census.Set_Player_Active(1, true, 100), "activate first peer");
		CHECK_MESSAGE(census.Set_Player_Active(2, true, 100), "activate second peer");
		CHECK_MESSAGE(!census.Set_Player_Active(MAX_TIMING_PLAYERS, true, 100), "reject out of range peer");
		CHECK_MESSAGE(census.Is_Player_Active(1), "active membership is queryable");
		CHECK_MESSAGE(!census.Is_Player_Active(MAX_TIMING_PLAYERS), "out of range membership is inactive");
		CHECK_MESSAGE(census.Record_Report(1, 12, 80, 100), "record first peer");
		CHECK_MESSAGE(census.Record_Report(2, 20, 180, 100), "record second peer");
		CHECK_MESSAGE(census.Record_Report(2, 20, MAXIMUM_RTO + 1, 100), "accept RTT above retransmit clamp");
		CHECK_MESSAGE(!census.Record_Report(2, MAXIMUM_PROCESS_MILLISECONDS + 1, 100, 150), "reject process time beyond engine range");
		CHECK_MESSAGE(!census.Record_Report(2, 1, MAXIMUM_REPORTED_RTT + 1, 150), "reject RTT beyond wire range");

		TimingCensus result = census.Inspect(200);
		CHECK_MESSAGE(result.ActivePlayers == 2u, "active peer count");
		CHECK_MESSAGE(result.FreshProcessReports == 2u, "fresh process report count");
		CHECK_MESSAGE(result.FreshRoundTripReports == 2u, "fresh RTT report count");
		CHECK_MESSAGE(result.WorstProcessMilliseconds == 20u, "worst process time");
		CHECK_MESSAGE(result.WorstRoundTrip == MAXIMUM_RTO + 1, "unequal links publish worst");
		CHECK_MESSAGE(result.ProcessComplete, "fresh process census complete");
		CHECK_MESSAGE(result.RoundTripComplete, "fresh RTT census complete");
		CHECK_MESSAGE(!result.RequiresConservativeTiming, "fresh census is not conservative");
		BalancedTimingPolicy aggregate;
		TimingEvaluation const guest_degradation = aggregate.Evaluate(result, 60, 200);
		CHECK_MESSAGE(guest_degradation.Changed, "a guest-to-guest slow path worsens the master policy");
		CHECK_MESSAGE(guest_degradation.Rung == MAXIMUM_TIMING_RUNG, "a guest-to-guest slow path worsens the master policy");

		result = census.Inspect(100 + REPORT_EXPIRY);
		CHECK_MESSAGE(!result.ProcessComplete, "process reports expire on boundary");
		CHECK_MESSAGE(!result.RoundTripComplete, "RTT reports expire on boundary");
		CHECK_MESSAGE(!result.RequiresConservativeTiming, "expired established RTT holds instead of forcing conservative timing");
		CHECK_MESSAGE(result.FreshProcessReports == 0u, "expired process reports not fresh");
		CHECK_MESSAGE(result.FreshRoundTripReports == 0u, "expired RTT reports not fresh");
		CHECK_MESSAGE(result.WorstProcessMilliseconds == 0u, "expired process time excluded");

		CHECK_MESSAGE(census.Set_Player_Active(2, false, 700), "departed peer removed");
		CHECK_MESSAGE(census.Record_Report(1, 15, 90, 700), "remaining peer refreshed");
		result = census.Inspect(700);
		CHECK_MESSAGE(result.ProcessComplete, "departure restores complete process census");
		CHECK_MESSAGE(result.RoundTripComplete, "departure restores complete RTT census");
		CHECK_MESSAGE(result.ActivePlayers == 1u, "departed peer excluded");
		CHECK_MESSAGE(result.WorstRoundTrip == 90u, "remaining peer wins census");

		CHECK_MESSAGE(census.Record_Report(1, 16, std::nullopt, 701), "established unavailable RTT report accepted");
		result = census.Inspect(701);
		CHECK_MESSAGE(result.ProcessComplete, "unavailable RTT retains fresh process time");
		CHECK_MESSAGE(result.FreshProcessReports == 1, "unavailable RTT retains fresh process time");
		CHECK_MESSAGE(!result.RoundTripComplete, "established unavailable RTT is incomplete");
		CHECK_MESSAGE(!result.RequiresConservativeTiming, "established unavailable RTT is not conservative");
	}


	TEST_CASE("a peer that never reports an RTT is tolerated until its report expires, then forces conservative timing")
	{
		using namespace NetTiming;

		TimingReportCensus grace;
		CHECK_MESSAGE(grace.Set_Player_Active(3, true, 1000), "activate grace peer");
		CHECK_MESSAGE(grace.Record_Report(3, 30, std::nullopt, 1000), "process-only initial report is accepted");
		TimingCensus result = grace.Inspect(1000 + REPORT_EXPIRY - 1);
		CHECK_MESSAGE(result.ProcessComplete, "process-only report remains complete before expiry");
		CHECK_MESSAGE(!result.RequiresConservativeTiming, "missing initial RTT is tolerated before expiry");
		result = grace.Inspect(1000 + REPORT_EXPIRY);
		CHECK_MESSAGE(result.RequiresConservativeTiming, "never-valid RTT becomes conservative at exact expiry");
		CHECK_MESSAGE(!result.RoundTripComplete, "never-valid RTT remains incomplete");
		CHECK_MESSAGE(!result.ProcessComplete, "process data expires with its report");
		CHECK_MESSAGE(Select_Desired_Frame_Rate(result, 42, 60) == 42u, "stale process data retains synchronized FPS");
	}


	TEST_CASE("fresh process data sets the frame rate, held to the game speed")
	{
		using namespace NetTiming;

		TimingCensus fresh_process;
		fresh_process.WorstProcessMilliseconds = 50;
		CHECK_MESSAGE(Select_Desired_Frame_Rate(fresh_process, 42, 15) == 15u, "fresh process data respects game-speed FPS");
		fresh_process.WorstProcessMilliseconds = 0;
		CHECK_MESSAGE(Select_Desired_Frame_Rate(fresh_process, 42, 60) == 60u, "zero process time permits 60 FPS");
	}


	TEST_CASE("an invalid report is rejected whole, and a peer removed and reactivated starts clean")
	{
		using namespace NetTiming;

		TimingReportCensus atomic;
		atomic.Set_Player_Active(4, true, 0);
		CHECK_MESSAGE(atomic.Record_Report(4, 25, 125, 10), "atomic baseline report accepted");
		CHECK_MESSAGE(!atomic.Record_Report(4, MAXIMUM_PROCESS_MILLISECONDS + 1, 200, 20), "invalid process report rejected atomically");
		CHECK_MESSAGE(!atomic.Record_Report(4, 50, MAXIMUM_REPORTED_RTT + 1, 20), "invalid RTT report rejected atomically");
		TimingCensus result = atomic.Inspect(20);
		CHECK_MESSAGE(result.WorstProcessMilliseconds == 25u, "invalid report preserves process time");
		CHECK_MESSAGE(result.WorstRoundTrip == 125u, "invalid report preserves RTT");
		CHECK_MESSAGE(atomic.Set_Player_Active(4, false, 30), "removing a peer clears its complete report");
		CHECK_MESSAGE(atomic.Inspect(30).ActivePlayers == 0u, "removed peer no longer contributes");
		CHECK_MESSAGE(atomic.Set_Player_Active(4, true, 40), "reactivated peer starts with a clean report");
		result = atomic.Inspect(40);
		CHECK_MESSAGE(!result.ProcessComplete, "reactivated peer has no inherited process report");
		CHECK_MESSAGE(!result.RequiresConservativeTiming, "reactivated peer receives fresh RTT grace");
	}


	TEST_CASE("each rung has aligned settings, starting from the bootstrap rung")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Settings_For_Rung(INITIAL_TIMING_RUNG).FrameSendRate == 2u, "initial FSR");
		CHECK_MESSAGE(Settings_For_Rung(INITIAL_TIMING_RUNG).MaxAhead == 6u, "initial MaxAhead");
		CHECK_MESSAGE(TimingSettings{} == Settings_For_Rung(INITIAL_TIMING_RUNG), "default settings match the bootstrap rung");
		CHECK_MESSAGE(Settings_For_Rung(1).MaxAhead == 4u, "best rung MaxAhead");
		CHECK_MESSAGE(Settings_For_Rung(10).MaxAhead == 30u, "worst rung MaxAhead");
		CHECK_MESSAGE(Timing_Settings_Are_Valid(Settings_For_Rung(10)), "rung settings valid");
		CHECK_MESSAGE(!Timing_Settings_Are_Valid({3, 6}), "below-rung minimum invalid");
		CHECK_MESSAGE(Timing_Transition_Source_Is_Valid({3, 6}), "legacy two-period horizon can source a transition");
		CHECK_MESSAGE(!Timing_Settings_Are_Valid({3, 10}), "unaligned settings invalid");
	}


	TEST_CASE("the RTT selects the rung, and the highest one carries the horizon the RTT needs, up to its cap")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Select_Timing_Settings(0, 60).FrameSendRate == 1u, "zero RTT selects best rung");
		CHECK_MESSAGE(Select_Timing_Settings(100, 60).FrameSendRate == 1u, "100 ms fits best rung");
		CHECK_MESSAGE(Select_Timing_Settings(101, 60).FrameSendRate == 2u, "101 ms advances a rung");
		CHECK_MESSAGE(Select_Timing_Settings(300, 60).FrameSendRate == 5u, "300 ms selects balanced rung");
		TimingSettings const high_rtt = Select_Timing_Settings(2000, 60);
		CHECK_MESSAGE(high_rtt.FrameSendRate == 10u, "two-second RTT selects highest FSR");
		CHECK_MESSAGE(high_rtt.MaxAhead == 70u, "two-second RTT carries needed aligned MaxAhead");
		TimingSettings const capped = Select_Timing_Settings(MAXIMUM_REPORTED_RTT, 60);
		CHECK_MESSAGE(capped.FrameSendRate == 10u, "wire-maximum RTT selects highest FSR");
		CHECK_MESSAGE(capped.MaxAhead == 250u, "highest rung caps at largest aligned horizon");
	}


	TEST_CASE("a horizon aligns up to a whole period under its cap")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(!Align_Max_Ahead(10, 0), "alignment rejects zero period");
		CHECK_MESSAGE(*Align_Max_Ahead(249, 10) == 250u, "alignment reaches cap");
		CHECK_MESSAGE(!Align_Max_Ahead(250, 9), "alignment rejects over cap");
	}


	TEST_CASE("the connection quality follows the rung, and settings off the rungs report bad")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(1)) == ConnectionQuality::Fast, "rung one reports fast");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(2)) == ConnectionQuality::Fast, "rung two reports fast");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(3)) == ConnectionQuality::Normal, "rung three reports normal");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(5)) == ConnectionQuality::Normal, "rung five reports normal");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(6)) == ConnectionQuality::Poor, "rung six reports poor");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(8)) == ConnectionQuality::Poor, "rung eight reports poor");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(9)) == ConnectionQuality::Bad, "rung nine reports bad");
		CHECK_MESSAGE(Connection_Quality_For_Settings(Settings_For_Rung(10)) == ConnectionQuality::Bad, "rung ten reports bad");
		CHECK_MESSAGE(Connection_Quality_For_Settings({2, 6}) == ConnectionQuality::Fast, "bootstrap settings report fast");
		CHECK_MESSAGE(Connection_Quality_For_Settings({3, 9}) == ConnectionQuality::Normal, "fallback settings report normal");
		CHECK_MESSAGE(Connection_Quality_For_Settings({10, 250}) == ConnectionQuality::Bad, "extended conservative settings report bad");
		CHECK_MESSAGE(Connection_Quality_For_Settings({0, 0}) == ConnectionQuality::Bad, "invalid settings report bad");
		CHECK_MESSAGE(Connection_Quality_For_Settings({2, 8}) == ConnectionQuality::Bad, "extended fast-rung horizon reports bad");
	}


	void Record_One(NetTiming::TimingReportCensus & census, NetTiming::Milliseconds rtt, std::uint32_t frame)
	{
		census.Record_Report(1, 10, rtt, frame);
	}


	TEST_CASE("timing reports come at frames 32 and 64, then every 128 frames")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(!Report_Is_Due(0), "frame zero does not report");
		CHECK_MESSAGE(Report_Is_Due(32), "bootstrap reports at frame 32");
		CHECK_MESSAGE(Report_Is_Due(64), "bootstrap reports at frame 64");
		CHECK_MESSAGE(!Report_Is_Due(96), "bootstrap does not add a frame 96 report");
		CHECK_MESSAGE(Report_Is_Due(128), "normal reports start at frame 128");
		CHECK_MESSAGE(Report_Is_Due(256), "normal reports continue at frame 256");
		CHECK_MESSAGE(!Report_Is_Due(385), "off-cadence reports remain disabled");
	}


	TEST_CASE("timing evaluations come at frames 64 and 128, then every 256 frames")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(!Evaluation_Is_Due(0), "frame zero does not evaluate");
		CHECK_MESSAGE(!Evaluation_Is_Due(32), "reports alone do not evaluate at frame 32");
		CHECK_MESSAGE(Evaluation_Is_Due(64), "bootstrap evaluates at frame 64");
		CHECK_MESSAGE(Evaluation_Is_Due(128), "bootstrap evaluates again at frame 128");
		CHECK_MESSAGE(Evaluation_Is_Due(256), "normal evaluations start at frame 256");
		CHECK_MESSAGE(!Evaluation_Is_Due(384), "frame 384 is not an evaluation");
		CHECK_MESSAGE(Evaluation_Is_Due(512), "normal evaluations continue at frame 512");
	}


	TEST_CASE("a new policy bootstraps at 2/6, and a low-latency census at frame 64 takes it straight to 1/4")
	{
		using namespace NetTiming;

		TimingReportCensus low_reports;
		low_reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy low;
		CHECK_MESSAGE(low.Is_Bootstrapping(), "new policy starts in bootstrap");
		CHECK_MESSAGE(low.Current_Settings() == (TimingSettings{2, 6}), "bootstrap starts at 2/6");
		TimingEvaluation result = low.Evaluate(low_reports.Inspect(32), 60, 32);
		CHECK_MESSAGE(!result.Evaluated, "bootstrap does not evaluate before frame 64");
		Record_One(low_reports, 0, 38);
		result = low.Evaluate(low_reports.Inspect(64), 60, 64);
		CHECK_MESSAGE(result.Evaluated, "complete low-latency census finishes at frame 64");
		CHECK_MESSAGE(result.Changed, "complete low-latency census finishes at frame 64");
		CHECK_MESSAGE(!low.Is_Bootstrapping(), "complete low-latency census finishes at frame 64");
		CHECK_MESSAGE(low.Current_Settings() == (TimingSettings{1, 4}), "low-latency bootstrap jumps directly to 1/4");
		result = low.Evaluate(low_reports.Inspect(255), 60, 255);
		CHECK_MESSAGE(!result.Evaluated, "steady evaluation remains anchored before frame 256");
		Record_One(low_reports, 0, 256);
		result = low.Evaluate(low_reports.Inspect(256), 60, 256);
		CHECK_MESSAGE(result.Evaluated, "steady evaluation is anchored at frame 256");
		CHECK_MESSAGE(!result.Changed, "steady evaluation is anchored at frame 256");
	}


	TEST_CASE("the bootstrap keeps headroom, so a marginal census completes it without leaving 2/6")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Select_Timing_Settings(100, 60, false) == (TimingSettings{1, 4}), "100 ms would select 1/4 without bootstrap headroom");
		CHECK_MESSAGE(Select_Timing_Settings(100, 60, true) == (TimingSettings{2, 6}), "100 ms retains 2/6 with bootstrap headroom");
		TimingReportCensus marginal_reports;
		marginal_reports.Set_Player_Active(1, true, 0);
		Record_One(marginal_reports, 100, 38);
		BalancedTimingPolicy marginal;
		TimingEvaluation const result = marginal.Evaluate(marginal_reports.Inspect(64), 60, 64);
		CHECK_MESSAGE(result.Evaluated, "marginal bootstrap completes without changing 2/6");
		CHECK_MESSAGE(!result.Changed, "marginal bootstrap completes without changing 2/6");
		CHECK_MESSAGE(!marginal.Is_Bootstrapping(), "marginal bootstrap completes without changing 2/6");
	}


	TEST_CASE("a high-latency bootstrap worsens at once, then cools down before the normal hysteresis resumes, and a reset bootstraps again")
	{
		using namespace NetTiming;

		TimingReportCensus high_reports;
		high_reports.Set_Player_Active(1, true, 0);
		Record_One(high_reports, 2000, 38);
		BalancedTimingPolicy high;
		TimingEvaluation result = high.Evaluate(high_reports.Inspect(64), 60, 64);
		CHECK_MESSAGE(result.Changed, "high-latency bootstrap worsens directly");
		CHECK_MESSAGE(high.Current_Settings() == (TimingSettings{10, 90}), "high-latency bootstrap worsens directly");

		for (std::uint32_t frame : {256u, 512u, 768u}) {
			Record_One(high_reports, 0, frame);
			result = high.Evaluate(high_reports.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(!result.Changed, "bootstrap cooldown leaves only two good evaluations by frame 768");
		CHECK_MESSAGE(high.Good_Evaluations() == 2, "bootstrap cooldown leaves only two good evaluations by frame 768");
		Record_One(high_reports, 0, 1024);
		result = high.Evaluate(high_reports.Inspect(1024), 60, 1024);
		CHECK_MESSAGE(result.Changed, "normal hysteresis resumes after bootstrap cooldown");
		CHECK_MESSAGE(high.Current_Settings() == (TimingSettings{9, 27}), "normal hysteresis resumes after bootstrap cooldown");

		high.Reset();
		CHECK_MESSAGE(high.Is_Bootstrapping(), "reset starts a new bootstrap");
		CHECK_MESSAGE(high.Current_Settings() == (TimingSettings{2, 6}), "reset restores 2/6");
	}


	TEST_CASE("an incomplete census at frame 64 keeps the bootstrap open until a complete one at frame 128")
	{
		using namespace NetTiming;

		TimingReportCensus delayed_reports;
		delayed_reports.Set_Player_Active(1, true, 0);
		delayed_reports.Record_Report(1, 10, std::nullopt, 38);
		BalancedTimingPolicy delayed;
		TimingEvaluation result = delayed.Evaluate(delayed_reports.Inspect(64), 60, 64);
		CHECK_MESSAGE(result.Evaluated, "incomplete frame 64 census keeps bootstrap open");
		CHECK_MESSAGE(!result.Changed, "incomplete frame 64 census keeps bootstrap open");
		CHECK_MESSAGE(delayed.Is_Bootstrapping(), "incomplete frame 64 census keeps bootstrap open");
		delayed_reports.Record_Report(1, 10, 0, 70);
		result = delayed.Evaluate(delayed_reports.Inspect(100), 60, 100);
		CHECK_MESSAGE(!result.Evaluated, "completed census waits for frame 128");
		CHECK_MESSAGE(delayed.Is_Bootstrapping(), "completed census waits for frame 128");
		result = delayed.Evaluate(delayed_reports.Inspect(128), 60, 128);
		CHECK_MESSAGE(result.Evaluated, "second bootstrap evaluation accepts a complete census");
		CHECK_MESSAGE(result.Changed, "second bootstrap evaluation accepts a complete census");
		CHECK_MESSAGE(!delayed.Is_Bootstrapping(), "second bootstrap evaluation accepts a complete census");
		CHECK_MESSAGE(delayed.Current_Settings() == (TimingSettings{1, 4}), "frame 128 completion selects the measured target");
	}


	TEST_CASE("a census still incomplete at frame 128 falls back to 3/9 at once")
	{
		using namespace NetTiming;

		TimingReportCensus incomplete_reports;
		incomplete_reports.Set_Player_Active(1, true, 0);
		incomplete_reports.Record_Report(1, 10, std::nullopt, 38);
		BalancedTimingPolicy incomplete;
		incomplete.Evaluate(incomplete_reports.Inspect(64), 60, 64);
		incomplete_reports.Record_Report(1, 10, std::nullopt, 70);
		TimingEvaluation const result = incomplete.Evaluate(incomplete_reports.Inspect(128), 60, 128);
		CHECK_MESSAGE(result.Evaluated, "incomplete final census falls back immediately");
		CHECK_MESSAGE(result.Changed, "incomplete final census falls back immediately");
		CHECK_MESSAGE(!incomplete.Is_Bootstrapping(), "incomplete final census falls back immediately");
		CHECK_MESSAGE(incomplete.Current_Settings() == (TimingSettings{3, 9}), "incomplete bootstrap falls back to 3/9");
	}


	TEST_CASE("an RTT lost during the bootstrap falls back to 3/9")
	{
		using namespace NetTiming;

		TimingReportCensus lost_reports;
		lost_reports.Set_Player_Active(1, true, 0);
		lost_reports.Set_Player_Active(2, true, 0);
		lost_reports.Record_Report(1, 10, 20, 38);
		lost_reports.Record_Report(2, 10, std::nullopt, 38);
		BalancedTimingPolicy lost;
		TimingEvaluation result = lost.Evaluate(lost_reports.Inspect(64), 60, 64);
		CHECK_MESSAGE(result.Evaluated, "initial missing RTT keeps bootstrap open");
		CHECK_MESSAGE(!result.Changed, "initial missing RTT keeps bootstrap open");
		CHECK_MESSAGE(lost.Is_Bootstrapping(), "initial missing RTT keeps bootstrap open");
		lost_reports.Record_Report(1, 10, std::nullopt, 70);
		result = lost.Evaluate(lost_reports.Inspect(128), 60, 128);
		CHECK_MESSAGE(result.Changed, "established RTT loss during bootstrap falls back to 3/9");
		CHECK_MESSAGE(lost.Current_Settings() == (TimingSettings{3, 9}), "established RTT loss during bootstrap falls back to 3/9");
	}


	TEST_CASE("a policy taken over from a previous master does not bootstrap again")
	{
		using namespace NetTiming;

		TimingReportCensus reports;
		reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy handoff;
		handoff.Reset_From({10, 70}, 0);
		CHECK_MESSAGE(!handoff.Is_Bootstrapping(), "handoff does not regain bootstrap");
		Record_One(reports, 0, 64);
		TimingEvaluation const result = handoff.Evaluate(reports.Inspect(64), 60, 64);
		CHECK_MESSAGE(!result.Evaluated, "handoff ignores bootstrap evaluation");
		CHECK_MESSAGE(handoff.Current_Settings() == (TimingSettings{10, 70}), "handoff ignores bootstrap evaluation");
	}


	TEST_CASE("a bootstrap resumed mid-game counts its frames from where it resumed")
	{
		using namespace NetTiming;

		TimingReportCensus resumed_reports;
		resumed_reports.Set_Player_Active(1, true, 1024);
		BalancedTimingPolicy resumed;
		resumed.Reset(1024);
		CHECK_MESSAGE(resumed.Cadence_Origin() == 1024u, "resumed bootstrap records its cadence origin");
		TimingEvaluation result = resumed.Evaluate(resumed_reports.Inspect(1056), 60, 1056);
		CHECK_MESSAGE(!result.Evaluated, "resumed bootstrap does not evaluate after only 32 frames");
		Record_One(resumed_reports, 0, 1062);
		result = resumed.Evaluate(resumed_reports.Inspect(1088), 60, 1088);
		CHECK_MESSAGE(result.Evaluated, "resumed bootstrap evaluates after 64 frames");
		CHECK_MESSAGE(result.Changed, "resumed bootstrap evaluates after 64 frames");
		CHECK_MESSAGE(!resumed.Is_Bootstrapping(), "resumed bootstrap evaluates after 64 frames");
		CHECK_MESSAGE(resumed.Current_Settings() == (TimingSettings{1, 4}), "resumed bootstrap selects its measured target");
	}


	TEST_CASE("the policy improves one rung after three good evaluations, worsens at once, and descends one rung per evaluation")
	{
		using namespace NetTiming;

		TimingReportCensus reports;
		reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy policy;
		policy.Reset_From({3, 9}, 0);

		Record_One(reports, 0, 256);
		TimingEvaluation result = policy.Evaluate(reports.Inspect(256), 60, 256);
		CHECK_MESSAGE(!result.Changed, "first good evaluation does not change");
		Record_One(reports, 0, 512);
		result = policy.Evaluate(reports.Inspect(512), 60, 512);
		CHECK_MESSAGE(!result.Changed, "second good evaluation does not change");
		Record_One(reports, 0, 768);
		result = policy.Evaluate(reports.Inspect(768), 60, 768);
		CHECK_MESSAGE(result.Changed, "third good evaluation improves one rung");
		CHECK_MESSAGE(policy.Current_Rung() == 2u, "one-rung improvement");

		Record_One(reports, 0, 800);
		result = policy.Evaluate(reports.Inspect(800), 60, 800);
		CHECK_MESSAGE(!result.Evaluated, "evaluation interval enforced");
		CHECK_MESSAGE(policy.Current_Rung() == 2u, "cooldown leaves rung");

		Record_One(reports, 2000, 1024);
		result = policy.Evaluate(reports.Inspect(1024), 60, 1024);
		CHECK_MESSAGE(result.Changed, "worsening is immediate");
		CHECK_MESSAGE(policy.Current_Rung() == 10u, "worsening reaches required rung");
		CHECK_MESSAGE(policy.Current_Settings().MaxAhead == 70u, "highest rung retains measured horizon");

		for (std::uint32_t frame : {1280u, 1536u, 1792u}) {
			Record_One(reports, 1300, frame);
			result = policy.Evaluate(reports.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(result.Changed, "same-rung horizon reduction uses hysteresis");
		CHECK_MESSAGE(policy.Current_Settings().MaxAhead == 50u, "same-rung horizon retains aligned need");

		Record_One(reports, 0, 2048);
		result = policy.Evaluate(reports.Inspect(2048), 60, 2048);
		CHECK_MESSAGE(result.Changed, "descent continues one rung per evaluation");
		CHECK_MESSAGE(policy.Current_Settings() == (TimingSettings{9, 27}), "descent continues one rung per evaluation");
		Record_One(reports, 0, 2304);
		result = policy.Evaluate(reports.Inspect(2304), 60, 2304);
		CHECK_MESSAGE(result.Changed, "descent keeps stepping while headroom holds");
		CHECK_MESSAGE(policy.Current_Settings() == (TimingSettings{8, 24}), "descent keeps stepping while headroom holds");
		Record_One(reports, 2000, 2560);
		result = policy.Evaluate(reports.Inspect(2560), 60, 2560);
		CHECK_MESSAGE(result.Changed, "worsening interrupts the descent");
		CHECK_MESSAGE(policy.Current_Rung() == 10u, "worsening interrupts the descent");
		Record_One(reports, 0, 2816);
		result = policy.Evaluate(reports.Inspect(2816), 60, 2816);
		CHECK_MESSAGE(!result.Changed, "worsening restores the three-evaluation requirement");
		CHECK_MESSAGE(policy.Good_Evaluations() == 1, "worsening restores the three-evaluation requirement");
	}


	TEST_CASE("20 percent headroom blocks a marginal improvement")
	{
		using namespace NetTiming;

		BalancedTimingPolicy headroom;
		headroom.Reset_From({3, 9}, 0);
		TimingReportCensus edge;
		edge.Set_Player_Active(1, true, 0);
		for (std::uint32_t frame : {256u, 512u, 768u}) {
			Record_One(edge, 120, frame);
			headroom.Evaluate(edge.Inspect(frame), 60, frame);
		}
		CHECK(headroom.Current_Rung() == 3u);
	}


	TEST_CASE("an evaluation without headroom holds the rung and ends the descent streak")
	{
		using namespace NetTiming;

		TimingEvaluation result;
		TimingReportCensus marginal_reports;
		marginal_reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy marginal;
		marginal.Reset_From({5, 15}, 0);
		for (std::uint32_t frame : {256u, 512u, 768u}) {
			Record_One(marginal_reports, 0, frame);
			result = marginal.Evaluate(marginal_reports.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(result.Changed, "descent starts after three good evaluations");
		CHECK_MESSAGE(marginal.Current_Settings() == (TimingSettings{4, 12}), "descent starts after three good evaluations");
		Record_One(marginal_reports, 250, 1024);
		result = marginal.Evaluate(marginal_reports.Inspect(1024), 60, 1024);
		CHECK_MESSAGE(!result.Changed, "evaluation without headroom holds the rung");
		CHECK_MESSAGE(marginal.Current_Settings() == (TimingSettings{4, 12}), "evaluation without headroom holds the rung");
		Record_One(marginal_reports, 0, 1280);
		result = marginal.Evaluate(marginal_reports.Inspect(1280), 60, 1280);
		CHECK_MESSAGE(!result.Changed, "a held evaluation ends the descent streak");
		CHECK_MESSAGE(marginal.Good_Evaluations() == 1, "a held evaluation ends the descent streak");
	}


	TEST_CASE("an expired report holds the timing and discards the improvement evidence, until its peer departs")
	{
		using namespace NetTiming;

		TimingReportCensus stale;
		stale.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy stale_policy;
		stale_policy.Reset_From({3, 9}, 0);
		TimingEvaluation result = stale_policy.Evaluate(stale.Inspect(0), 60, 0);
		CHECK_MESSAGE(!result.Changed, "startup waits for a complete census");
		CHECK_MESSAGE(stale_policy.Current_Rung() == 3u, "startup keeps initial rung");

		stale.Record_Report(1, 10, 100, 256);
		stale_policy.Evaluate(stale.Inspect(256), 60, 256);
		result = stale_policy.Evaluate(stale.Inspect(256 + REPORT_EXPIRY), 60, 256 + REPORT_EXPIRY);
		CHECK_MESSAGE(result.Evaluated, "expired established report holds the current timing");
		CHECK_MESSAGE(!result.Changed, "expired established report holds the current timing");
		CHECK_MESSAGE(stale_policy.Current_Rung() == 3u, "expired established report keeps the rung");
		CHECK_MESSAGE(stale_policy.Good_Evaluations() == 0u, "expired established report discards improvement evidence");

		stale.Set_Player_Active(1, false, 1024);
		for (std::uint32_t frame : {1024u, 1280u, 1536u}) {
			stale_policy.Evaluate(stale.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(stale_policy.Current_Rung() == 2u, "departed peer allows recovery");
	}


	TEST_CASE("an incomplete census still applies a worsening but never an improvement")
	{
		using namespace NetTiming;

		TimingReportCensus partial;
		partial.Set_Player_Active(1, true, 0);
		partial.Set_Player_Active(2, true, 0);
		BalancedTimingPolicy partial_policy;
		partial_policy.Reset_From({3, 9}, 0);
		partial.Record_Report(2, 10, 50, 0);
		partial.Record_Report(1, 10, 2000, 256);
		partial.Record_Report(2, 10, std::nullopt, 256);
		TimingEvaluation result = partial_policy.Evaluate(partial.Inspect(256), 60, 256);
		CHECK_MESSAGE(result.Changed, "incomplete census still applies a worsening");
		CHECK_MESSAGE(partial_policy.Current_Settings() == (TimingSettings{10, 70}), "incomplete census still applies a worsening");
		partial.Record_Report(1, 10, 0, 512);
		partial.Record_Report(2, 10, std::nullopt, 512);
		result = partial_policy.Evaluate(partial.Inspect(512), 60, 512);
		CHECK_MESSAGE(result.Evaluated, "incomplete census never improves");
		CHECK_MESSAGE(!result.Changed, "incomplete census never improves");
		CHECK_MESSAGE(partial_policy.Good_Evaluations() == 0, "incomplete census never improves");
	}


	TEST_CASE("repeated degradation and recovery stays stable, and the descent continues past eight changes")
	{
		using namespace NetTiming;

		TimingReportCensus reports;
		reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy policy;
		policy.Reset_From({3, 9}, 0);
		std::uint32_t frame = EVALUATION_INTERVAL;
		auto evaluate = [&](Milliseconds rtt) {
			Record_One(reports, rtt, frame);
			policy.Evaluate(reports.Inspect(frame), 60, frame);
			frame += EVALUATION_INTERVAL;
		};

		for (int cycle = 0; cycle < 5; cycle++) {
			evaluate(2000);
			evaluate(0);
			evaluate(0);
			evaluate(0);
		}
		CHECK_MESSAGE(policy.Current_Rung() == 9u, "repeated degradation and recovery remains stable");
		evaluate(0);
		evaluate(0);
		evaluate(0);
		CHECK_MESSAGE(policy.Current_Rung() == 6u, "descent continues after more than eight changes");
	}


	TEST_CASE("a long wait holds the timing and resets the improvement count, and quiet waiting allows the descent")
	{
		using namespace NetTiming;

		TimingReportCensus reports;
		reports.Set_Player_Active(1, true, 0);
		reports.Set_Player_Active(2, true, 0);
		reports.Record_Report(1, 10, 0, 256, 50);
		reports.Record_Report(2, 10, 0, 256, 400);
		TimingCensus census = reports.Inspect(256);
		CHECK_MESSAGE(census.WorstStallMilliseconds == 400u, "census publishes the longest wait");

		BalancedTimingPolicy policy;
		policy.Reset_From({4, 12}, 0);
		TimingEvaluation result = policy.Evaluate(census, 60, 256);
		CHECK_MESSAGE(result.Evaluated, "a long wait never steps the timing up");
		CHECK_MESSAGE(!result.Changed, "a long wait never steps the timing up");
		CHECK_MESSAGE(policy.Current_Settings() == (TimingSettings{4, 12}), "a long wait never steps the timing up");
		CHECK_MESSAGE(policy.Good_Evaluations() == 0u, "a long wait resets the improvement count");

		reports.Record_Report(1, 10, 0, 512, 0);
		reports.Record_Report(2, 10, 0, 512, 200);
		result = policy.Evaluate(reports.Inspect(512), 60, 512);
		CHECK_MESSAGE(result.Evaluated, "waiting above the improvement limit holds the timing");
		CHECK_MESSAGE(!result.Changed, "waiting above the improvement limit holds the timing");
		CHECK_MESSAGE(policy.Good_Evaluations() == 0, "waiting above the improvement limit holds the timing");

		for (std::uint32_t frame : {768u, 1024u, 1280u}) {
			reports.Record_Report(1, 10, 0, frame, 0);
			reports.Record_Report(2, 10, 0, frame, 20);
			result = policy.Evaluate(reports.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(result.Changed, "quiet waiting allows the normal descent");
		CHECK_MESSAGE(policy.Current_Settings() == (TimingSettings{3, 9}), "quiet waiting allows the normal descent");

		reports.Record_Report(1, 10, 0, 1536, 0);
		reports.Record_Report(2, 10, 0, 1536, 150);
		result = policy.Evaluate(reports.Inspect(1536), 60, 1536);
		CHECK_MESSAGE(result.Evaluated, "a wait during the descent ends the streak");
		CHECK_MESSAGE(!result.Changed, "a wait during the descent ends the streak");
		CHECK_MESSAGE(policy.Good_Evaluations() == 0, "a wait during the descent ends the streak");
	}


	TEST_CASE("the wait ledger adds each player's waits over a thirty-second window")
	{
		using namespace NetTiming;

		WaitLedger ledger;
		CHECK_MESSAGE(ledger.Recent(1, 5000) == 0u, "a new ledger has no waits");

		ledger.Add(1, 300, 10000);
		ledger.Add(1, 200, 10999);
		ledger.Add(2, 50, 10500);
		CHECK_MESSAGE(ledger.Recent(1, 11000) == 500u, "waits in one second add up");
		CHECK_MESSAGE(ledger.Recent(2, 11000) == 50u, "players are kept apart");

		ledger.Add(1, 400, 25000);
		CHECK_MESSAGE(ledger.Recent(1, 25000) == 900u, "waits across seconds add up");
		CHECK_MESSAGE(ledger.Recent(1, 39999) == 900u, "a wait still counts in the last second of the window");
		CHECK_MESSAGE(ledger.Recent(1, 40000) == 400u, "a wait leaves the window after thirty seconds");
		CHECK_MESSAGE(ledger.Recent(1, 55000) == 0u, "the newest wait leaves last");

		ledger.Add(1, 100, 70000);
		CHECK_MESSAGE(ledger.Recent(1, 70000) == 100u, "a reused bucket drops its old second");

		ledger.Add(MAX_TIMING_PLAYERS, 100, 70000);
		ledger.Add(static_cast<unsigned int>(-1), 100, 70000);
		CHECK_MESSAGE(ledger.Recent(MAX_TIMING_PLAYERS, 70000) == 0u, "an out-of-range player reads as no wait");

		ledger.Reset();
		CHECK_MESSAGE(ledger.Recent(1, 70000) + ledger.Recent(2, 70000) == 0u, "reset clears every player");
	}


	TEST_CASE("a handoff restores the authoritative settings and starts a cooldown that one good evaluation does not end")
	{
		using namespace NetTiming;

		TimingReportCensus reports;
		reports.Set_Player_Active(1, true, 1000);
		BalancedTimingPolicy policy;
		policy.Reset_From({10, 70}, 1000);
		CHECK_MESSAGE(policy.Current_Settings() == (TimingSettings{10, 70}), "handoff restores authoritative settings");
		CHECK_MESSAGE(policy.Good_Evaluations() == 0u, "handoff discards improvement evidence");

		Record_One(reports, 0, 1000);
		TimingEvaluation result = policy.Evaluate(reports.Inspect(1000), 60, 1000);
		CHECK_MESSAGE(!result.Evaluated, "handoff starts an evaluation cooldown");
		Record_One(reports, 0, 1256);
		result = policy.Evaluate(reports.Inspect(1256), 60, 1256);
		CHECK_MESSAGE(result.Evaluated, "one good evaluation preserves the handoff target");
		CHECK_MESSAGE(!result.Changed, "one good evaluation preserves the handoff target");
		CHECK_MESSAGE(policy.Current_Settings() == (TimingSettings{10, 70}), "one good evaluation preserves the handoff target");
	}


	TEST_CASE("a handoff at 10/250 improves one rung after hysteresis and keeps descending")
	{
		using namespace NetTiming;

		TimingEvaluation result;
		TimingReportCensus recovery_reports;
		recovery_reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy recover;
		recover.Reset_From({10, 250}, 0);
		for (std::uint32_t frame : {256u, 512u, 768u}) {
			Record_One(recovery_reports, 0, frame);
			result = recover.Evaluate(recovery_reports.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(result.Changed, "10/250 improves one rung after hysteresis");
		CHECK_MESSAGE(recover.Current_Settings() == (TimingSettings{9, 27}), "10/250 improves one rung after hysteresis");
		Record_One(recovery_reports, 0, 1024);
		result = recover.Evaluate(recovery_reports.Inspect(1024), 60, 1024);
		CHECK_MESSAGE(result.Changed, "10/250 keeps descending one rung per evaluation");
		CHECK_MESSAGE(recover.Current_Settings() == (TimingSettings{8, 24}), "10/250 keeps descending one rung per evaluation");
	}


	TEST_CASE("a handoff at 10/70 catches up toward 10/50 after hysteresis")
	{
		using namespace NetTiming;

		TimingEvaluation result;
		TimingReportCensus same_rung_reports;
		same_rung_reports.Set_Player_Active(1, true, 0);
		BalancedTimingPolicy same_rung;
		same_rung.Reset_From({10, 70}, 0);
		for (std::uint32_t frame : {256u, 512u, 768u}) {
			Record_One(same_rung_reports, 1300, frame);
			result = same_rung.Evaluate(same_rung_reports.Inspect(frame), 60, frame);
		}
		CHECK_MESSAGE(result.Changed, "10/70 catches up toward 10/50 after hysteresis");
		CHECK_MESSAGE(same_rung.Current_Settings() == (TimingSettings{10, 50}), "10/70 catches up toward 10/50 after hysteresis");
	}


	TEST_CASE("the adaptive policy recovers from a legacy two-period horizon")
	{
		using namespace NetTiming;

		TimingReportCensus legacy_reports;
		legacy_reports.Set_Player_Active(1, true, 0);
		legacy_reports.Record_Report(1, 10, 200, 256);
		BalancedTimingPolicy legacy;
		legacy.Reset_From({3, 6}, 0);
		TimingEvaluation const result = legacy.Evaluate(legacy_reports.Inspect(256), 60, 256);
		CHECK_MESSAGE(result.Changed, "adaptive policy recovers from a legacy two-period horizon");
		CHECK_MESSAGE(legacy.Current_Settings() == (TimingSettings{3, 9}), "adaptive policy recovers from a legacy two-period horizon");
	}


	TEST_CASE("a decrease is staged to a frame both periods align on, then caught up one new period at a time")
	{
		using namespace NetTiming;

		std::optional<StagedTimingUpdate> staged = Stage_Timing_Update({3, 9}, {1, 4}, 100);
		REQUIRE_MESSAGE(staged, "decrease stages");
		CHECK_MESSAGE(staged->Deferred, "decrease stages");
		CHECK_MESSAGE(staged->ActivationFrame == 111u, "old horizon and periods align");
		CHECK_MESSAGE(staged->InitialMaxAhead == 6u, "activation preserves most of the old horizon");
		CHECK_MESSAGE(!Timing_Update_Is_Due(110, staged->ActivationFrame), "staged update not early");
		CHECK_MESSAGE(Timing_Update_Is_Due(111, staged->ActivationFrame), "staged update due");
		CHECK_MESSAGE(*Next_Transition_Max_Ahead({1, 6}, {1, 4}) == 5u, "first catch-up step removes one new period");
		CHECK_MESSAGE(*Next_Transition_Max_Ahead({1, 5}, {1, 4}) == 4u, "second catch-up step reaches target");
		CHECK_MESSAGE(*Next_Transition_Max_Ahead({1, 4}, {1, 4}) == 4u, "catch-up stays at target");
	}


	TEST_CASE("each kind of decrease activates at an aligned frame with a safe initial horizon")
	{
		using namespace NetTiming;

		std::optional<StagedTimingUpdate> staged = Stage_Timing_Update({3, 9}, {2, 6}, 100);
		REQUIRE(staged);
		CHECK_MESSAGE(staged->ActivationFrame == 114u, "both periods use LCM");
		CHECK_MESSAGE(staged->InitialMaxAhead == 6u, "adjacent decrease activates at target horizon");

		staged = Stage_Timing_Update({10, 250}, {9, 27}, 100);
		REQUIRE(staged);
		CHECK_MESSAGE(staged->ActivationFrame == 360u, "wide decrease aligns activation to both periods");
		CHECK_MESSAGE(staged->InitialMaxAhead == 243u, "wide decrease preserves a safe initial horizon");
		CHECK_MESSAGE(*Next_Transition_Max_Ahead({9, 243}, {9, 27}) == 234u, "wide catch-up removes one new period");

		staged = Stage_Timing_Update({10, 70}, {10, 50}, 100);
		REQUIRE(staged);
		CHECK_MESSAGE(staged->ActivationFrame == 170u, "same-rate decrease drains at old horizon");
		CHECK_MESSAGE(staged->InitialMaxAhead == 60u, "same-rate decrease keeps one intermediate period");
		CHECK_MESSAGE(*Next_Transition_Max_Ahead({10, 60}, {10, 50}) == 50u, "same-rate catch-up reaches requested horizon");

		staged = Stage_Timing_Update({9, 234}, {8, 24}, 360);
		REQUIRE_MESSAGE(staged, "replacement decrease restages from effective settings");
		CHECK_MESSAGE(staged->Deferred, "replacement decrease restages from effective settings");
		CHECK_MESSAGE(staged->InitialMaxAhead == 232u, "replacement decrease safely rebases its horizon");
	}


	TEST_CASE("a mixed worsening keeps an aligned catch-up whose command target never moves backward")
	{
		using namespace NetTiming;

		std::optional<StagedTimingUpdate> staged = Stage_Timing_Update({9, 243}, {10, 40}, 369);
		REQUIRE_MESSAGE(staged, "mixed worsening keeps an aligned catch-up");
		CHECK_MESSAGE(staged->Deferred, "mixed worsening keeps an aligned catch-up");
		CHECK_MESSAGE(staged->ActivationFrame == 369u, "mixed worsening activates at its event frame");
		CHECK_MESSAGE(staged->InitialMaxAhead == 250u, "mixed worsening preserves the effective horizon");
		std::optional<std::uint32_t> const first_boundary = Next_Send_Boundary(369, 10);
		REQUIRE_MESSAGE(first_boundary, "mixed worsening identifies its first new-rate send");
		CHECK_MESSAGE(*first_boundary == 370, "mixed worsening identifies its first new-rate send");
		TimingTransitionState mixed{*staged, *first_boundary, true};
		std::optional<TimingTransitionAdvance> mixed_step = Advance_Timing_Transition(mixed, {10, 250}, 370);
		REQUIRE_MESSAGE(mixed_step, "first new-rate send keeps the temporary horizon");
		CHECK_MESSAGE(!mixed_step->Changed, "first new-rate send keeps the temporary horizon");
		CHECK_MESSAGE(mixed_step->Settings == (TimingSettings{10, 250}), "first new-rate send keeps the temporary horizon");
		mixed_step = Advance_Timing_Transition(mixed, mixed_step->Settings, 380);
		REQUIRE_MESSAGE(mixed_step, "following boundary drains one new period");
		CHECK_MESSAGE(mixed_step->Changed, "following boundary drains one new period");
		CHECK_MESSAGE(mixed_step->Settings == (TimingSettings{10, 240}), "following boundary drains one new period");
		CHECK_MESSAGE(369u + 243u <= 370u + 250u, "mixed replacement never moves the command target backward");
		CHECK_MESSAGE(370u + 250u <= 380u + 240u, "mixed replacement never moves the command target backward");
	}


	TEST_CASE("a worsening applies at once and replaces a pending decrease, and a conservative update cancels a catch-up")
	{
		using namespace NetTiming;

		std::optional<StagedTimingUpdate> immediate = Stage_Timing_Update({1, 4}, {5, 15}, 100);
		REQUIRE_MESSAGE(immediate, "worsening applies immediately");
		CHECK_MESSAGE(!immediate->Deferred, "worsening applies immediately");
		CHECK_MESSAGE(immediate->ActivationFrame == 100u, "immediate frame");
		CHECK_MESSAGE(immediate->InitialMaxAhead == 15u, "immediate update uses requested horizon");
		std::optional<StagedTimingUpdate> staged = Stage_Timing_Update({3, 9}, {1, 4}, 100);
		staged = immediate;
		REQUIRE_MESSAGE(staged, "an immediate worse update replaces a pending decrease");
		CHECK_MESSAGE(!staged->Deferred, "an immediate worse update replaces a pending decrease");
		CHECK_MESSAGE(staged->Settings == (TimingSettings{5, 15}), "an immediate worse update replaces a pending decrease");

		immediate = Stage_Timing_Update({9, 234}, {10, 250}, 360);
		REQUIRE_MESSAGE(immediate, "conservative update cancels catch-up immediately");
		CHECK_MESSAGE(!immediate->Deferred, "conservative update cancels catch-up immediately");
		CHECK_MESSAGE(immediate->InitialMaxAhead == 250, "conservative update cancels catch-up immediately");
	}


	TEST_CASE("staging rejects zero periods, unaligned settings, and overflow, but lets a legacy horizon recover at once")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(!Stage_Timing_Update({0, 9}, {1, 4}, 100), "zero-period staging rejected");
		CHECK_MESSAGE(!Next_Send_Boundary(100, 0), "zero-period send boundary rejected");
		CHECK_MESSAGE(!Next_Send_Boundary((std::numeric_limits<std::uint32_t>::max)(), 10), "overflowing send boundary rejected");
		CHECK_MESSAGE(!Stage_Timing_Update({3, 10}, {1, 4}, 100), "unaligned staging rejected");
		std::optional<StagedTimingUpdate> const legacy_recovery = Stage_Timing_Update({3, 6}, {3, 9}, 100);
		REQUIRE_MESSAGE(legacy_recovery, "legacy response horizon can recover immediately");
		CHECK_MESSAGE(!legacy_recovery->Deferred, "legacy response horizon can recover immediately");
		CHECK_MESSAGE(!Stage_Timing_Update({10, 30}, {9, 27}, (std::numeric_limits<std::uint32_t>::max)() - 10), "overflowing staging rejected");
		CHECK_MESSAGE(!Next_Transition_Max_Ahead({9, 243}, {8, 24}), "catch-up rejects mismatched send periods");
		CHECK_MESSAGE(!Next_Transition_Max_Ahead({9, 242}, {9, 27}), "catch-up rejects invalid effective settings");
	}


	struct TransitionTrace
	{
		std::vector<std::pair<std::uint32_t, NetTiming::TimingSettings>> Changes;
		std::vector<std::uint64_t> CommandTargets;

		bool operator==(TransitionTrace const &) const = default;
	};


	TransitionTrace Run_Transition(NetTiming::TimingSettings current, NetTiming::TimingSettings requested, std::uint32_t event_frame, std::uint32_t final_frame)
	{
		TransitionTrace trace;
		std::optional<NetTiming::StagedTimingUpdate> const plan = NetTiming::Stage_Timing_Update(current, requested, event_frame);
		if (!plan || !plan->Deferred) {
			return(trace);
		}

		NetTiming::TimingTransitionState transition{*plan};
		std::uint32_t const first_frame = event_frame - event_frame % current.FrameSendRate;
		for (std::uint32_t frame = first_frame; frame <= final_frame; frame++) {
			std::optional<NetTiming::TimingTransitionAdvance> const advance = NetTiming::Advance_Timing_Transition(transition, current, frame);
			if (!advance) {
				trace.CommandTargets.clear();
				return(trace);
			}
			if (advance->Changed) {
				current = advance->Settings;
				trace.Changes.emplace_back(frame, current);
			}
			if (frame % current.FrameSendRate == 0) {
				trace.CommandTargets.push_back(static_cast<std::uint64_t>(frame) + current.MaxAhead);
			}
			if (advance->Complete) {
				break;
			}
		}
		return(trace);
	}


	TEST_CASE("a transition runs the same every time, reaches its requested settings, and never moves a command target backward")
	{
		using namespace NetTiming;

		for (std::pair<TimingSettings, TimingSettings> const & transition : {
			std::pair{TimingSettings{10, 250}, TimingSettings{9, 27}},
			std::pair{TimingSettings{10, 70}, TimingSettings{10, 50}},
			std::pair{TimingSettings{3, 9}, TimingSettings{2, 6}},
			std::pair{TimingSettings{2, 6}, TimingSettings{1, 4}}}) {
			INFO("from ", transition.first.FrameSendRate, "/", transition.first.MaxAhead, " to ", transition.second.FrameSendRate, "/", transition.second.MaxAhead);
			TransitionTrace const first = Run_Transition(transition.first, transition.second, 100, 700);
			TransitionTrace const repeat = Run_Transition(transition.first, transition.second, 100, 700);
			CHECK_MESSAGE(first == repeat, "repeated transition runs are deterministic");
			REQUIRE_MESSAGE(!first.Changes.empty(), "a transition reaches its requested settings");
			CHECK_MESSAGE(first.Changes.back().second == transition.second, "a transition reaches its requested settings");
			bool nondecreasing = !first.CommandTargets.empty();
			for (std::size_t index = 1; index < first.CommandTargets.size(); index++) {
				nondecreasing = nondecreasing && first.CommandTargets[index] >= first.CommandTargets[index - 1];
			}
			CHECK_MESSAGE(nondecreasing, "transition command targets never move backward");
		}
	}


	TEST_CASE("an active catch-up can be replaced safely, and at once by a fully conservative update")
	{
		using namespace NetTiming;

		std::optional<StagedTimingUpdate> const plan = Stage_Timing_Update({10, 250}, {9, 27}, 100);
		REQUIRE(plan);
		TimingTransitionState state{*plan};
		TimingSettings current{10, 250};
		for (std::uint32_t frame = 100; frame <= 369; frame++) {
			std::optional<TimingTransitionAdvance> const advance = Advance_Timing_Transition(state, current, frame);
			if (advance && advance->Changed) {
				current = advance->Settings;
			}
		}
		std::optional<StagedTimingUpdate> const replacement = Stage_Timing_Update(current, {8, 24}, 369);
		REQUIRE_MESSAGE(replacement, "an active catch-up can be safely replaced");
		CHECK_MESSAGE(replacement->Deferred, "an active catch-up can be safely replaced");
		CHECK_MESSAGE(replacement->InitialMaxAhead >= current.MaxAhead - current.FrameSendRate, "an active catch-up can be safely replaced");
		std::optional<StagedTimingUpdate> const conservative = Stage_Timing_Update(current, {10, 250}, 369);
		REQUIRE_MESSAGE(conservative, "a fully conservative replacement applies immediately");
		CHECK_MESSAGE(!conservative->Deferred, "a fully conservative replacement applies immediately");
	}

	struct RecordingEvent
	{
		enum Kind : unsigned int {COMMAND, TIMING, FRAME_INFO};

		int Frame;
		Kind Type;
		unsigned int Value;
		NetTiming::TimingSettings Settings = {};
		bool IsExecuted = false;

		bool operator==(RecordingEvent const &) const = default;
	};


	struct RecordedExecution
	{
		int Frame;
		RecordingEvent Event;

		bool operator==(RecordedExecution const &) const = default;
	};


	std::vector<RecordedExecution> Run_Recorded_Transitions(std::stringstream & recording, bool playback, std::vector<RecordingEvent> events)
	{
		using namespace NetTiming;

		TimingSettings current{3, 9};
		std::optional<TimingTransitionState> transition;
		std::vector<RecordedExecution> trace;
		int reschedule_after = 0;
		int reschedule_to = 0;
		int previous_execution_frame = 93;
		for (int frame = 96; frame <= 159; frame++) {
			if (transition) {
				std::optional<TimingTransitionAdvance> const advance = Advance_Timing_Transition(*transition, current, frame);
				CHECK_MESSAGE(advance.has_value(), "recorded transition advances");
				if (!advance) {
					return(trace);
				}
				current = advance->Settings;
				if (advance->Complete) {
					transition.reset();
				}
			}
			if (frame % current.FrameSendRate != 0) {
				continue;
			}

			if (playback) {
				int count = 0;
				recording.read(reinterpret_cast<char *>(&count), sizeof(count));
				CHECK_MESSAGE(recording.good(), "playback reads each execution batch");
				CHECK_MESSAGE(count >= 0, "playback reads each execution batch");
				CHECK_MESSAGE(count <= 10, "playback reads each execution batch");
				if (!recording.good() || count < 0 || count > 10) {
					return(trace);
				}
				for (int index = 0; index < count; index++) {
					RecordingEvent event{};
					recording.read(reinterpret_cast<char *>(&event), sizeof(event));
					CHECK_MESSAGE(recording.good(), "playback reads a complete event");
					event.IsExecuted = false;
					events.push_back(event);
				}
			}

			for (RecordingEvent & event : events) {
				if (event.Type != RecordingEvent::FRAME_INFO && event.Frame > reschedule_after && event.Frame < reschedule_to) {
					event.Frame = reschedule_to;
				}
			}

			if (!playback) {
				int count = 0;
				for (RecordingEvent const & event : events) {
					count += Event_Is_Due(event.Frame, event.IsExecuted, frame);
				}
				recording.write(reinterpret_cast<char const *>(&count), sizeof(count));
				for (RecordingEvent const & event : events) {
					if (Event_Is_Due(event.Frame, event.IsExecuted, frame)) {
						recording.write(reinterpret_cast<char const *>(&event), sizeof(event));
					}
				}
			}

			for (RecordingEvent & event : events) {
				if (!Event_Is_Due(event.Frame, event.IsExecuted, frame)) {
					continue;
				}
				CHECK_MESSAGE((event.Type == RecordingEvent::FRAME_INFO
					|| event.Frame > previous_execution_frame), "recorded command remains eligible after the previous execution");
				trace.push_back({frame, event});
				if (event.Type == RecordingEvent::TIMING) {
					std::optional<StagedTimingUpdate> const plan = Stage_Timing_Update(current, event.Settings, event.Frame);
					CHECK_MESSAGE(plan.has_value(), "recorded timing event can be scheduled");
					if (!plan) {
						return(trace);
					}
					if (plan->Deferred) {
						transition = TimingTransitionState{*plan};
						reschedule_after = 0;
						reschedule_to = 0;
					} else {
						transition.reset();
						current = plan->Settings;
						reschedule_after = event.Frame;
						reschedule_to = ((event.Frame + current.MaxAhead + current.FrameSendRate - 1)
							/ current.FrameSendRate) * current.FrameSendRate;
					}
				}
				event.IsExecuted = true;
			}
			previous_execution_frame = frame;
		}
		return(trace);
	}


	TEST_CASE("a recording of timing transitions plays back the same executions")
	{
		std::stringstream recording(std::ios::in | std::ios::out | std::ios::binary);
		std::vector<RecordingEvent> events{
			{99, RecordingEvent::TIMING, 1, {2, 6}},
			{111, RecordingEvent::COMMAND, 2},
			{116, RecordingEvent::TIMING, 3, {5, 15}},
			{118, RecordingEvent::COMMAND, 4},
			{135, RecordingEvent::TIMING, 5, {3, 9}},
			{155, RecordingEvent::COMMAND, 6},
			{111, RecordingEvent::FRAME_INFO, 7},
			{124, RecordingEvent::FRAME_INFO, 8},
			{180, RecordingEvent::COMMAND, 9},
			{90, RecordingEvent::COMMAND, 10, {}, true},
		};
		std::vector<RecordedExecution> const live = Run_Recorded_Transitions(recording, false, events);
		recording.seekg(0);
		int first_batch_count = -1;
		recording.read(reinterpret_cast<char *>(&first_batch_count), sizeof(first_batch_count));
		CHECK_MESSAGE(first_batch_count == 0, "recording keeps empty execution batches");
		recording.seekg(0);
		std::vector<RecordedExecution> const replay = Run_Recorded_Transitions(recording, true, {});
		CHECK_MESSAGE(live == replay, "playback preserves transition and command execution");
		CHECK_MESSAGE(recording.peek() == std::char_traits<char>::eof(), "playback consumes exactly the recorded batches");
		CHECK_MESSAGE(live.size() == std::size_t{8}, "future and already executed events are excluded");
		bool first_skipped_command = false;
		bool second_skipped_command = false;
		bool retagged_command = false;
		bool unchanged_frame_info = false;
		for (RecordedExecution const & execution : replay) {
			if (execution.Event.Value == 2) {
				first_skipped_command = execution.Frame == 112 && execution.Event.Frame == 111;
			} else if (execution.Event.Value == 6) {
				second_skipped_command = execution.Frame == 156 && execution.Event.Frame == 155;
			} else if (execution.Event.Value == 4) {
				retagged_command = execution.Frame == 135 && execution.Event.Frame == 135;
			} else if (execution.Event.Value == 8) {
				unchanged_frame_info = execution.Frame == 125 && execution.Event.Frame == 124;
			}
		}
		CHECK_MESSAGE(first_skipped_command, "3/9 to 2/6 recording preserves the skipped scheduled frame");
		CHECK_MESSAGE(second_skipped_command, "5/15 to 3/9 recording preserves the skipped scheduled frame");
		CHECK_MESSAGE(retagged_command, "worsening retags a command before recording its execution batch");
		CHECK_MESSAGE(unchanged_frame_info, "worsening does not retag frame information");
	}


	TEST_CASE("only the master may send timing events, and their values must be in range and aligned")
	{
		using namespace NetTiming;

		CHECK_MESSAGE(Timing_Authority_Is_Valid(2, 2), "the resolved master may send timing events");
		CHECK_MESSAGE(!Timing_Authority_Is_Valid(3, 2), "a guest may not send timing events");
		CHECK_MESSAGE(Response_Time_Is_Valid(2, 2, 0, false), "legacy response time accepts its minimum");
		CHECK_MESSAGE(Response_Time_Is_Valid(255, 2, 0, false), "legacy response time preserves its byte range");
		CHECK_MESSAGE(Response_Time_Is_Valid(6, 2, 3, true), "compressed response time accepts two aligned periods");
		CHECK_MESSAGE(!Response_Time_Is_Valid(3, 2, 3, true), "compressed response time rejects one period");
		CHECK_MESSAGE(!Response_Time_Is_Valid(7, 2, 3, true), "compressed response time rejects misalignment");
		CHECK_MESSAGE(!Response_Time_Is_Valid(255, 2, 3, true), "compressed response time enforces the scheduling cap");
		CHECK_MESSAGE(Timing_Values_Are_Valid(60, 9, 3), "timing values accept a balanced setting");
		CHECK_MESSAGE(!Timing_Values_Are_Valid(0, 9, 3), "timing values reject zero desired FPS");
		CHECK_MESSAGE(!Timing_Values_Are_Valid(60, 10, 3), "timing values reject an unaligned horizon");
		CHECK_MESSAGE(!Timing_Values_Are_Valid(60, 251, 10), "timing values reject a horizon above the cap");
	}

}

