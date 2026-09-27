---
key: PowersUpToLevel
summary: How many upgrade slots the plug consumes at once, or -1 for one slot in the next free position.
when_omitted:
  kind: value
  value: "-1"
---

At `-1` the plug takes the next free upgrade slot. It may be installed on a host that already has plugs, until the host holds its [`Upgrades`](/keys/upgrades/) count.

At `1`, `2` or `3` the plug fills that many slots in one placement, and only a host with no plugs at all accepts it. The value counts slots to consume; it does not name the slot to occupy. Any other value makes the plug impossible to install.

The fill stops at the host's `Upgrades` count. The structure that [`WallTower`](/keys/walltower/) names is the exception: it takes every slot the value asks for, whatever its `Upgrades`, and each slot filled also advances its [turret animation](/keys/turretanim/) by one letter.

:::danger[A multi-slot plug leaves the slots beneath it empty]
Only the highest slot filled records the plug, so its [`Power=`](/keys/power/#scope-buildingtype), weapon and superweapon count once, however many slots it consumed. Selling the host first sells the plug from that top slot. Selling it again reads the empty slot beneath and crashes the game. A computer house that sells plugs to raise money can crash the same way.

In a multiplayer game, a computer house that captures the host sells all its plugs at once and crashes on the first empty slot. The exception is a structure-building factory, such as a construction yard, that is the only structure of its type the house owns. The computer house keeps that host and its plugs.

The risk applies to `2` and `3` on a host with room for more than one slot, including a value of `3` on a two-slot host. A value of `1`, or a single-slot host, leaves no empty slot. A [`Turret=yes`](/keys/turret/) plug is also exempt, because removing it empties every slot at once. Keep other multi-slot plugs off any host that can be sold or captured.
:::
