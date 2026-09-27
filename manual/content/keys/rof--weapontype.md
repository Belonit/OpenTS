---
key: ROF
scope: weapontype
label: Weapon reload delay
see_also: [Burst, IsSonic, VeteranROF, Ammo]
when_omitted:
  kind: value
  value: "0"
---

The value is the number of game frames the weapon waits after a shot before it can fire again. There are 15 game frames to the second. It is a delay, so a larger value fires more slowly.

```ini title="rules.ini"
[120mm]
Damage=70
ROF=80
```

Unless one of the cases further down applies, the value is adjusted in this order:

1. It is multiplied by the firing house's rate-of-fire multiplier. That multiplier is the [difficulty `ROF`](/keys/rof/#scope-difficulty-settings) of the house's difficulty slot. In skirmish and multiplayer games it is also multiplied by the house's [country `ROF`](/keys/rof/#scope-housetype).
2. A random 0 to 2 frames is added.
3. If the firer has earned the rate-of-fire ability, the result is divided by one plus [`VeteranROF`](/keys/veteranrof/).

Three cases use a different delay. The first case that applies decides it:

1. A structure that had more than one round of [`Ammo`](/keys/ammo/) when it fired waits a single frame. `ROF` therefore sets only the pause after its last round.
2. A beam or particle weapon waits exactly `ROF`, with none of the adjustments above. This covers every [`IsSonic=yes`](/keys/issonic/) weapon. It also covers every [`UseFireParticles=yes`](/keys/usefireparticles/), [`UseSparkParticles=yes`](/keys/usesparkparticles/) or [`IsRailgun=yes`](/keys/israilgun/) weapon. Such a weapon also cannot fire again until its effect has ended, as [Firing geometry](/systems/firing-geometry/#effects-that-hold-the-weapon-shut) describes.
3. A shot that does not end a [`Burst`](/keys/burst/) waits the gap its [`BurstDelay0`](/keys/burstdelay0/) to [`BurstDelay3`](/keys/burstdelay3/) entry gives. The shot that ends the burst uses the adjusted `ROF`.

During a [strafing run](/keys/curleyshuffle/), an aircraft also waits its first weapon's `ROF`, unadjusted, after each shot but the last. This sets the spacing between the shots of the run.

:::caution[Keep ROF above 0]
At `ROF=0`, which is also the value when the key is omitted, the weapon can fire again within two frames. When this is the firer's first weapon, the computer's ratings of the firer as an anti-air, anti-armor and anti-infantry threat also divide by `ROF`, so at 0 they become meaningless values. The computer uses these ratings to station newly built units, to score its base defense zones and to weigh which base defenses to build. The anti-air rating is taken only when the projectile is [`AA=yes`](/keys/aa/), and the other two only when it is [`AG=yes`](/keys/ag/).
:::
