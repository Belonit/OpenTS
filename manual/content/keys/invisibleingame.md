---
key: InvisibleInGame
summary: Hides a structure from every player, keeps it off the radar and out of targeting, and lets units pass through it.
see_also: [Invisible, "system:cloaking"]
when_omitted:
  kind: value
  value: "no"
---

An `InvisibleInGame=yes` structure is never drawn for any house, its owner included. That separates it from [`Invisible=yes`](/keys/invisible/), which still draws the structure for its owner.

Setting this key also forces `Invisible=yes` and [`RadarVisible=no`](/keys/radarvisible/) onto the type, overriding either key in the same section. The structure therefore has every effect of `Invisible=yes` as well.

It is also left out of these interactions:

- it offers no cursor action when selected, and no structure offers an action against it;
- band-box selection passes over it;
- no object picks it as a target on its own;
- explosions do not damage it;
- infantry and vehicles move through its cells, and Tiberium can grow on them;
- [an EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) leaves it untouched and does not spring its [Paralyzed](/mapping/events/tevent-paralyzed/) trigger event.
