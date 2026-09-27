---
key: Visceroids
summary: Parsed flag that spawns nothing.
no_effect: true
see_also: [TiberiumDeathToVisceroid, SmallVisceroid]
when_omitted:
  kind: context-dependent
  note: Off in the first scenario after the game starts. A later campaign mission that omits the key keeps the value from the previous campaign mission, or off if a skirmish or multiplayer game came in between.
---

Nothing in the game reads this flag, so it does not decide whether infantry killed by Tiberium leave a small visceroid. [`TiberiumDeathToVisceroid`](/keys/tiberiumdeathtovisceroid/) in the map's `[Basic]` section decides that.
