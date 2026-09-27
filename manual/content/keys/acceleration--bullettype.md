---
key: Acceleration
scope: bullettype
label: Homing projectile acceleration
see_also: [ROT, Speed]
when_omitted:
  kind: value
  value: "3"
---

Only a homing projectile reads the figure: one whose [`ROT`](/keys/rot/#scope-bullettype) is above zero. A projectile with no rate of turn follows the arc it was launched along and never changes speed under its own power.

The figure is the speed a homing projectile gains each game frame, in leptons per frame, until it reaches its ceiling. There are 256 leptons to a cell and 15 game frames to the second. The ceiling is normally the firing weapon's [`Speed`](/keys/speed/#scope-weapontype) converted to leptons per frame, about 2.56 leptons for each point, so `Speed=100` gives 255. A bomblet released by a [splitting](/keys/splits/) projectile has a ceiling of 50 leptons per frame instead, the equivalent of about `Speed=20`. At `2` or more, the figure decides only how quickly the projectile reaches its ceiling.

A homing projectile leaves the launcher at one lepton per frame, in a launch phase that ignores this setting. During the launch phase its speed rises by one lepton every second game frame. The phase ends once the projectile is within half a lepton of its ceiling, so a weapon whose `Speed` is below `16` reaches full speed on the launch ramp alone, and this setting makes no difference to it. A weapon whose `Speed` is `16` or more skips the launch phase, and this figure carries its projectile the whole way from one lepton per frame to the ceiling.

A projectile flying faster than its ceiling slows by half the figure each frame, rounded down to a whole lepton, so at `0` or `1` it never slows. This matters for a bomblet whose weapon's `Speed` is `20` or more, because it is launched faster than its ceiling of 50 leptons per frame.

:::caution[A fast weapon with no acceleration leaves its projectile crawling]
A weapon whose `Speed` is `16` or more skips the launch ramp, and at `Acceleration=0` nothing else speeds its projectile up. The projectile stays at its launch speed of one lepton per game frame, about a seventeenth of a cell each second.
:::
