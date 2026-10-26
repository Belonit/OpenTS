---
title: Replace an animation's zero End and LoopEnd in every scenario
category: fix
release: 0.2.0
targets:
- type: key
  id: End
  effect: changed
- type: key
  id: LoopEnd
  effect: changed
credit: [ZivDero]
---

A `NewTheater=yes` animation that does not also set `Theater=yes` replaces `End=0` with its shape's frame count and `LoopEnd=0` with its `End` count. One without `DemandLoad=yes` used to keep the zeros in a scenario loaded right after another in the same theater and session, so an `End=0` animation ended at its first frame advance and the middle passes of a looping `LoopEnd=0` animation showed only their `LoopStart` frame. Every scenario now replaces them.

The shipped art's only animation that kept the zeros, the damaged GDI Kodiak's `GAKODK_CD`, makes a single pass and plays the same either way.
