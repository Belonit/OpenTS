---
title: Adapt private network retries
category: performance
release: 0.2.0
targets:
- type: system
  id: network-transport-timing
  effect: added
credit:
- ZivDero
---

Each player's private connection to another player used to resend an unacknowledged packet at a fixed interval. It now measures that link's round trip and sets the link's retry timeout and connection timeout from the measurement. Each further resend of one packet waits twice as long as the last. When the link's latency climbs past its retry timeout, the retry timeout itself doubles, so the link can still be measured.

The global channel, which carries lobby messages, in-game chat and other messages outside the frame traffic, keeps its fixed retry interval.
