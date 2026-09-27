---
title: Reject malformed network packets
category: fix
release: 0.2.0
targets: []
credit:
- ZivDero
- Rampastring
---

A multiplayer packet that is malformed, too large, cut short, or sent from an address other than its player's is now dropped before it changes any player's connection or queues a command. A packet shorter than its header used to be read past its end, and a frame report from an unknown address that named a player moved that player's connection to the new address.

Rampastring is credited for the Vinifera fixes against crafted network requests this follows.
