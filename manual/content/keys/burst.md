---
key: Burst
summary: How many shots the weapon fires in quick succession before it waits out its full reload.
see_also: ["ROF", "BurstDelay0", "PrimaryFireFLH", "VoxelBarrelOffsetToBarrelEnd", "FiringSyncFrame1"]
when_omitted:
  kind: value
  value: "1"
---

A burst is a run of shots with short gaps between them. After the last shot of the burst, the weapon waits its full [`ROF`](/keys/rof/#scope-weapontype) delay, adjusted as that page describes, and the next shot starts a new burst. `0` and negative values are read as `1`.

```ini title="rules.ini"
[MyTwinCannon] ; example WeaponType
Burst=2
ROF=60        ; the wait after the second shot, not after each one
BurstDelay0=4 ; frames between the first shot and the second
```

The gap after each shot but the last comes from the weapon's [`BurstDelay0`](/keys/burstdelay0/) to [`BurstDelay3`](/keys/burstdelay3/), chosen by the shot just fired: `BurstDelay0` after the first shot, `BurstDelay1` after the second, and so on. An entry left at `-1` gives a random three to five frames. So does every gap after the fifth or a later shot, because no entry covers it.

Two cases never use the short gap:

- A weapon with [`IsSonic=yes`](/keys/issonic/), [`IsRailgun=yes`](/keys/israilgun/), [`UseFireParticles=yes`](/keys/usefireparticles/) or [`UseSparkParticles=yes`](/keys/usesparkparticles/) waits its bare [`ROF`](/keys/rof/#scope-weapontype) after every shot, without that page's adjustments. A burst on such a weapon still alternates muzzles, but its shots are never grouped.
- A structure that had more than one round of [`Ammo`](/keys/ammo/) when it fired waits a single frame, whatever `Burst`, the `BurstDelay` entries and `ROF` say. A structure with `Ammo` left unset uses the normal delays.

If the object loses its target partway through a burst, it keeps its place in the burst and starts a timer as long as the wait after a burst's last shot. If the timer runs out while the object still has no target, the next shot starts a new burst. If the object gets a new target first, it continues the unfinished burst. Clearing a target and immediately giving a new one therefore does not restart the burst.

The side of the gun each shot leaves from also alternates. The lateral part of the firing offset ([`PrimaryFireFLH`](/keys/primaryfireflh/) or its secondary counterpart) is reversed on every second shot, so a weapon mounted off the centerline fires from two muzzles in turn. A structure with a voxel barrel does the same with [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/), and fires its third and later shots from the center. [Firing geometry](/systems/firing-geometry/#how-a-burst-alternates-muzzles) covers which parts of a shot use which muzzle.

A computer house rates an object as twice as strong a defender when its type has a first-slot weapon and either names the same weapon in both slots or has a burst above one on either weapon.

:::caution[A structure's first upgrade decides whether both weapons fire]
A structure with anything in its first upgrade slot stops choosing between its two weapon slots. It fires both slots in the same frame, or neither, depending on the upgrade type in the first upgrade slot:

- The structure fires both slots when the upgrade type has a first-slot weapon, and either names the same weapon in both slots or has a burst above one on either weapon.
- Otherwise the structure fires neither slot.

Only the first upgrade slot decides whether the structure fires. Each slot then fires the weapon of the first installed upgrade that has a weapon in that slot, or the structure's weapon if no upgrade does.
:::
