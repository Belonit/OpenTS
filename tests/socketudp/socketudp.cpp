/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Drives the UDP transport against a socket that reaches no network, so that the
// send and receive passes can be exercised without opening a session. The
// transport is used through its public surface only; what a test knows about a
// datagram it learns from the socket it handed in.

#include "always.h"

#include "netsocket.h"
#include "wspudp.h"

#include "doctest/doctest.h"

#include <cstring>
#include <string>
#include <vector>


// The transport logs through DebugString and reads the default port from the
// game. Neither is worth starting an engine for.
int WestwoodOnline_PortNumber = 1234;

void __cdecl DebugString(char const *, ...)
{
}

void __cdecl DebugStringNoPrefix(char const *, ...)
{
}

// The transport asks the platform for a socket as it is constructed. Answering
// with a null one is what keeps the Winsock implementation out of this harness
// altogether; each test then supplies the socket it means to drive.
std::unique_ptr<SocketClass> Socket_Create_Platform_Socket(void)
{
	return(std::make_unique<NullSocketClass>());
}

namespace {

// A transport wired to a socket the test keeps hold of. Open_Socket is what
// actually opens the injected socket, so the order here matters.
struct Harness
{
	UDPInterfaceClass Transport;
	NullSocketClass * Socket = nullptr;

	explicit Harness(std::vector<InterfaceType> interfaces = {})
	{
		auto socket = std::make_unique<NullSocketClass>();
		Socket = socket.get();
		Socket->Set_Interfaces(std::move(interfaces));

		Transport.Set_Socket(std::move(socket));
		Transport.Set_Local_Port(50000);
		Transport.Set_Destination_Port(50000);
		Transport.Open_Socket();
		Transport.Start_Listening();
	}

	// Hands the transport a buffer to send and returns the bytes that reached
	// the wire, which is the framing a peer would have to accept.
	std::vector<unsigned char> Send(std::string const & payload, IPXAddressClass const & to)
	{
		Socket->Clear_Sent();
		IPXAddressClass address = to;
		Transport.WriteTo(const_cast<char *>(payload.data()), static_cast<int>(payload.size()), &address, sizeof(address));
		Transport.Service();

		if (Socket->Sent().empty()) return(std::vector<unsigned char>());
		return(Socket->Sent().back().Bytes);
	}

	// Drains whatever the transport accepted, as the manager's service pass does.
	std::vector<std::string> Drain(void)
	{
		std::vector<std::string> received;

		for (;;) {
			char buffer[2048];
			char address[64];
			int length = sizeof(buffer);
			int address_len = sizeof(address);

			int const rc = Transport.Read(buffer, length, address, address_len);
			if (rc == 0) break;

			received.emplace_back(buffer, buffer + length);
		}

		return(received);
	}
};


IPXAddressClass Peer(uint32_t ip, uint16_t port)
{
	return(IPXAddressClass(ip, Socket_Network_Port(port)));
}


unsigned short const TunnelUs = 7;
unsigned short const TunnelThem = 9;


// A harness speaking through the tunnel server as TunnelUs.
struct TunnelHarness : Harness
{
	TunnelHarness(void)
	{
		Transport.Configure_Tunnel(TunnelUs, 0x0100007f, Socket_Network_Port(50000));
	}

	// Sends a payload to TunnelThem and returns it as the server would echo it to us.
	std::vector<unsigned char> Echo(std::string const & payload)
	{
		std::vector<unsigned char> wire = Send(payload, IPXAddressClass(0, TunnelThem));
		REQUIRE(wire.size() >= 4u);
		wire[2] = static_cast<unsigned char>(TunnelUs & 0xff);
		wire[3] = static_cast<unsigned char>(TunnelUs >> 8);
		return(wire);
	}
};

}


// A send the socket refuses must cost the pass, not the queue. This is the case
// the transport cannot reach against a real socket, since a loopback send buffer
// never fills.
TEST_CASE("a full socket sends nothing, and the queue survives the refused pass in order")
{
	Harness harness;
	IPXAddressClass const peer = Peer(0x0100007f, 51000);

	IPXAddressClass first = peer;
	IPXAddressClass second = peer;
	char one[] = "first";
	char two[] = "second";

	// WriteTo flushes as it queues, so the socket has to be refusing before the
	// packets go in for them to still be waiting.
	harness.Socket->Set_Would_Block(true);

	harness.Transport.WriteTo(one, 5, &first, sizeof(first));
	harness.Transport.WriteTo(two, 6, &second, sizeof(second));

	harness.Transport.Service();
	CHECK(harness.Socket->Sent().empty());

	harness.Socket->Set_Would_Block(false);
	harness.Transport.Service();

	REQUIRE(harness.Socket->Sent().size() == 2u);
	std::vector<unsigned char> const & sent = harness.Socket->Sent()[0].Bytes;
	REQUIRE(sent.size() == 5 + sizeof(unsigned int));
	CHECK_MESSAGE(std::memcmp(sent.data() + sizeof(unsigned int), "first", 5) == 0, "the first packet queued goes first");
}


TEST_CASE("a datagram the transport framed is one it accepts back")
{
	Harness harness;
	IPXAddressClass const peer = Peer(0x0100007f, 51000);

	std::vector<unsigned char> const wire = harness.Send("hello", peer);
	REQUIRE_MESSAGE(!wire.empty(), "the queued packet reaches the socket");

	harness.Socket->Deliver(peer, wire.data(), static_cast<int>(wire.size()));
	harness.Transport.Service();

	std::vector<std::string> const got = harness.Drain();
	REQUIRE(got.size() == 1u);
	CHECK(got[0] == "hello");
}


// The drain is bounded so a flood cannot hold the frame, and what is left waits
// for the next pass rather than being lost.
TEST_CASE("one pass takes no more than the buffer pool holds, and the rest waits for the next")
{
	Harness harness;
	IPXAddressClass const peer = Peer(0x0100007f, 51000);

	std::vector<unsigned char> const wire = harness.Send("x", peer);

	int const flood = WS_MAX_STATIC_BUFFERS + 10;
	for (int i = 0; i < flood; i++) {
		harness.Socket->Deliver(peer, wire.data(), static_cast<int>(wire.size()));
	}

	harness.Transport.Service();
	std::size_t const first_pass = harness.Drain().size();
	CHECK(first_pass <= (std::size_t)WS_MAX_STATIC_BUFFERS);

	harness.Transport.Service();
	std::size_t const second_pass = harness.Drain().size();
	CHECK(first_pass + second_pass == static_cast<std::size_t>(flood));
}


// A transient failure mid-drain must not end the pass. Windows reports
// WSAECONNRESET routinely when a peer quits, and stopping there would strand
// everything queued behind it.
TEST_CASE("a reset is cleared and the drain carries on")
{
	Harness harness;
	IPXAddressClass const peer = Peer(0x0100007f, 51000);

	std::vector<unsigned char> const wire = harness.Send("after", peer);

	harness.Socket->Set_Next_Receive_Error(SocketError::RESET);
	harness.Socket->Deliver(peer, wire.data(), static_cast<int>(wire.size()));

	harness.Transport.Service();

	std::vector<std::string> const got = harness.Drain();
	REQUIRE(got.size() == 1u);
	CHECK(got[0] == "after");
}


// A packet from one of our own addresses is our own broadcast coming back.
TEST_CASE("a packet from one of our own addresses is thrown away")
{
	uint32_t const mine = 0x0100007f;

	Harness harness({{mine, 0}});
	IPXAddressClass const self = Peer(mine, 51000);

	std::vector<unsigned char> const wire = harness.Send("echo", self);

	harness.Socket->Deliver(self, wire.data(), static_cast<int>(wire.size()));
	harness.Transport.Service();

	CHECK(harness.Drain().empty());
}


// Anything the admission layer rejects must not reach the game.
TEST_CASE("a runt and a bad checksum are both refused, and the short datagram is counted as a drop")
{
	Harness harness;
	IPXAddressClass const peer = Peer(0x0100007f, 51000);

	unsigned char const runt[] = {1, 2};
	harness.Socket->Deliver(peer, runt, sizeof(runt));

	unsigned char corrupt[] = {0, 0, 0, 0, 'n', 'o'};
	harness.Socket->Deliver(peer, corrupt, sizeof(corrupt));

	harness.Transport.Service();

	CHECK(harness.Drain().empty());
	CHECK(harness.Transport.Dropped_Packets(WinsockInterfaceClass::WS_DROP_RECEIVE_TOO_SHORT) >= 1);
}


// A tunnelled game names its players by tunnel ID, and the server is the only
// endpoint the socket ever sees.
TEST_CASE("a tunnelled datagram leads with the sender and recipient")
{
	TunnelHarness harness;
	std::vector<unsigned char> const wire = harness.Send("tunnelled", IPXAddressClass(0, TunnelThem));
	REQUIRE(wire.size() >= 4u);
	CHECK(wire[0] == (TunnelUs & 0xff));
	CHECK(wire[1] == (TunnelUs >> 8));
	CHECK(wire[2] == (TunnelThem & 0xff));
	CHECK(wire[3] == (TunnelThem >> 8));
}


TEST_CASE("a tunnelled datagram the server echoes to us is accepted")
{
	TunnelHarness harness;
	std::vector<unsigned char> const ours = harness.Echo("tunnelled");
	harness.Socket->Deliver(IPXAddressClass(0, 0), ours.data(), static_cast<int>(ours.size()));
	harness.Transport.Service();
	CHECK(harness.Drain().size() == 1u);
}


// One for somebody else must be passed over, not treated as a failure.
TEST_CASE("a tunnelled datagram for another tunnel ID is passed over")
{
	TunnelHarness harness;
	std::vector<unsigned char> const theirs = harness.Send("tunnelled", IPXAddressClass(0, TunnelThem));
	harness.Socket->Deliver(IPXAddressClass(0, 0), theirs.data(), static_cast<int>(theirs.size()));

	std::vector<unsigned char> const echoed = harness.Echo("second");
	harness.Socket->Deliver(IPXAddressClass(0, 0), echoed.data(), static_cast<int>(echoed.size()));

	harness.Transport.Service();
	std::vector<std::string> const got = harness.Drain();
	REQUIRE(got.size() == 1u);
	CHECK(got[0] == "second");
}


// Enable_Broadcast only takes effect when the socket opens, so both transports
// were opened without it; what matters here is that neither crashes and the
// local address list came from the socket.
TEST_CASE("every interface the socket reports is a local address")
{
	Harness with_networks({{0x0100007f, 0xff00007f}, {0x0200a8c0, 0xff00a8c0}});
	with_networks.Transport.Enable_Broadcast(true);

	Harness blind;
	blind.Transport.Enable_Broadcast(true);

	CHECK(with_networks.Transport.Get_Num_Local_Addresses() == 2);
	CHECK_MESSAGE(blind.Transport.Get_Num_Local_Addresses() == 0, "a socket naming no interface reports none");
}
