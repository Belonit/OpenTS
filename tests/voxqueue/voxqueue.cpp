/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Drives the speech queue on its own: the order lines come out in, what a
// duplicate does, the cap, the interrupt classes, and the standard slot.
// Needs no game data.

#include "voxqueue.h"

#include "doctest/doctest.h"

namespace {

VoxType Pop(VoxQueueClass & queue)
{
	VoxType voice = VOX_NONE;
	queue.Next(voice);
	return(voice);
}

}


TEST_CASE("queued lines of equal priority play in order and do not cut")
{
	VoxQueueClass queue;
	CHECK_FALSE(queue.Submit(VOX_CONSTRUCTION, 50, VOXC_QUEUE, VOX_NONE));
	queue.Submit(VOX_UNIT_READY, 50, VOXC_QUEUE, VOX_NONE);
	queue.Submit(VOX_LOW_POWER, 50, VOXC_QUEUE, VOX_NONE);
	CHECK(queue.Count() == 3);
	CHECK(Pop(queue) == VOX_CONSTRUCTION);
	CHECK(Pop(queue) == VOX_UNIT_READY);
	CHECK(Pop(queue) == VOX_LOW_POWER);
	CHECK(queue.Count() == 0);
	CHECK(Pop(queue) == VOX_NONE);
}


TEST_CASE("a higher priority line plays first, then the rest in order")
{
	VoxQueueClass queue;
	queue.Submit(VOX_CONSTRUCTION, 50, VOXC_QUEUE, VOX_NONE);
	queue.Submit(VOX_BASE_UNDER_ATTACK, 100, VOXC_QUEUE, VOX_NONE);
	queue.Submit(VOX_UNIT_READY, 50, VOXC_QUEUE, VOX_NONE);
	CHECK(Pop(queue) == VOX_BASE_UNDER_ATTACK);
	CHECK(Pop(queue) == VOX_CONSTRUCTION);
	CHECK(Pop(queue) == VOX_UNIT_READY);
}


TEST_CASE("a line already waiting or playing is not queued again, and no line is nothing")
{
	VoxQueueClass queue;
	queue.Submit(VOX_CONSTRUCTION, 50, VOXC_QUEUE, VOX_NONE);
	queue.Submit(VOX_CONSTRUCTION, 50, VOXC_QUEUE, VOX_NONE);
	CHECK_MESSAGE(queue.Count() == 1, "a waiting line is not queued twice");

	queue.Submit(VOX_UNIT_READY, 50, VOXC_QUEUE, VOX_UNIT_READY);
	CHECK_MESSAGE(queue.Count() == 1, "the playing line is not queued");
	CHECK_FALSE(queue.Contains(VOX_UNIT_READY));

	CHECK_FALSE(queue.Submit(VOX_NONE, 50, VOXC_QUEUE, VOX_NONE));
	CHECK(queue.Count() == 1);
}


TEST_CASE("a full queue drops its lowest priority line, or its oldest of equals, and plays a critical line first")
{
	VoxQueueClass queue;
	for (int i = 0; i < VoxQueueClass::MAX_PENDING; i++) {
		queue.Submit((VoxType)(VOX_CONSTRUCTION + i), i == 3 ? 20 : 50, VOXC_QUEUE, VOX_NONE);
	}
	CHECK(queue.Count() == VoxQueueClass::MAX_PENDING);

	queue.Submit(VOX_BASE_UNDER_ATTACK, 50, VOXC_QUEUE, VOX_NONE);
	CHECK_MESSAGE(queue.Count() == VoxQueueClass::MAX_PENDING, "the queue is still full");
	CHECK_MESSAGE(!queue.Contains((VoxType)(VOX_CONSTRUCTION + 3)), "the lowest priority line was dropped");
	CHECK(queue.Contains(VOX_BASE_UNDER_ATTACK));

	queue.Submit(VOX_ACCOMPLISHED, 255, VOXC_CRITICAL, VOX_NONE);
	CHECK(queue.Contains(VOX_ACCOMPLISHED));
	CHECK_MESSAGE(!queue.Contains(VOX_CONSTRUCTION), "with equal priorities the oldest goes");
	CHECK(Pop(queue) == VOX_ACCOMPLISHED);
}


TEST_CASE("a full queue of critical lines gives up its oldest")
{
	VoxQueueClass queue;
	for (int i = 0; i < VoxQueueClass::MAX_PENDING; i++) {
		queue.Submit((VoxType)(VOX_CONSTRUCTION + i), 255, VOXC_CRITICAL, VOX_NONE);
	}
	queue.Submit(VOX_LOW_POWER, 50, VOXC_QUEUE, VOX_NONE);
	CHECK(queue.Count() == VoxQueueClass::MAX_PENDING);
	CHECK(queue.Contains(VOX_LOW_POWER));
	CHECK_FALSE(queue.Contains(VOX_CONSTRUCTION));
}


TEST_CASE("a line asked for now does not cut, but goes ahead of the queue")
{
	VoxQueueClass queue;
	queue.Submit(VOX_CONSTRUCTION, 50, VOXC_QUEUE, VOX_NONE);
	queue.Submit(VOX_UNIT_READY, 50, VOXC_QUEUE, VOX_NONE);
	CHECK_FALSE(queue.Submit(VOX_INCOMING_TRANSMISSION, 50, VOXC_QUEUED_INTERRUPT, VOX_LOW_POWER));
	CHECK(Pop(queue) == VOX_INCOMING_TRANSMISSION);
	CHECK(Pop(queue) == VOX_CONSTRUCTION);
}


TEST_CASE("an interrupt cuts the playing line and empties the queue behind it")
{
	VoxQueueClass queue;
	queue.Submit(VOX_LOW_POWER, 50, VOXC_QUEUE, VOX_NONE);
	CHECK(queue.Submit(VOX_FAIL, 255, VOXC_INTERRUPT, VOX_CONSTRUCTION));
	CHECK(queue.Count() == 1);
	CHECK(Pop(queue) == VOX_FAIL);
}


TEST_CASE("an interrupt with nothing playing cuts nothing")
{
	VoxQueueClass queue;
	CHECK_FALSE(queue.Submit(VOX_FAIL, 255, VOXC_INTERRUPT, VOX_NONE));
}


TEST_CASE("a critical line beats a line asked for now")
{
	VoxQueueClass queue;
	queue.Submit(VOX_CONSTRUCTION, 50, VOXC_QUEUED_INTERRUPT, VOX_NONE);
	queue.Submit(VOX_ACCOMPLISHED, 255, VOXC_CRITICAL, VOX_NONE);
	CHECK(Pop(queue) == VOX_ACCOMPLISHED);
	CHECK(Pop(queue) == VOX_CONSTRUCTION);
}


TEST_CASE("the standard slot holds one line, replaced only by a higher one, and plays after the queue")
{
	VoxQueueClass queue;
	CHECK_FALSE(queue.Submit(VOX_CONSTRUCTION, 50, VOXC_STANDARD, VOX_NONE));
	queue.Submit(VOX_UNIT_READY, 50, VOXC_STANDARD, VOX_NONE);
	CHECK_MESSAGE(queue.Count() == 1, "an equal standard line is dropped");
	CHECK(queue.Contains(VOX_CONSTRUCTION));

	queue.Submit(VOX_BASE_UNDER_ATTACK, 100, VOXC_STANDARD, VOX_NONE);
	CHECK(queue.Count() == 1);
	CHECK(queue.Contains(VOX_BASE_UNDER_ATTACK));

	queue.Submit(VOX_LOW_POWER, 50, VOXC_QUEUE, VOX_NONE);
	CHECK(Pop(queue) == VOX_LOW_POWER);
	CHECK(Pop(queue) == VOX_BASE_UNDER_ATTACK);
}
