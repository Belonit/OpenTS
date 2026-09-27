---
title: Adapt multiplayer timing to every connection
category: performance
release: 0.2.0
targets:
- type: system
  id: network-synchronization
  effect: added
credit:
- ZivDero
---

A network game now adjusts its timing during play: how often each machine sends its commands, and how many frames ahead each command is scheduled. The game starts by sending every two frames with commands scheduled six frames ahead. It then follows the slowest player's processing time and the worst round trip between any two players.

The timing slows at the first evaluation that finds a worse connection. It speeds up again only after repeated evaluations find spare margin, and only while no player has recently waited 0.1 seconds or longer for the others.

Internet games used to lengthen every frame by up to 30 milliseconds while a player's latency was high compared with how far ahead commands were scheduled. That slowdown is gone.

In an internet game, the disabled Connection slider in the options dialog shows the timing in force as a rung from 1, the fastest, to 10, and names its quality tier. The message list announces each change of target tier.

Every player now sends a new `NETWORK_REPORT` event during a network game, so all players need the same OpenTS build. Recordings contain the event, so play a recording with the build that wrote it. Existing events keep their IDs, and `LATENCYFUDGE` and `PROCESS_TIME` are no longer sent.
