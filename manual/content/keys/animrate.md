---
key: AnimRate
summary: The number of game frames each frame of the projectile's flight animation is held for.
see_also: [AnimLow, AnimHigh, Image]
when_omitted:
  kind: value
  value: "0"
---

`AnimRate=1` steps the flight animation every game frame, 15 animation frames a second. `AnimRate=4` steps it every fourth game frame.

The setting is used only while the animation runs, which needs [`AnimLow`](/keys/animlow/) or [`AnimHigh`](/keys/animhigh/) to be other than `0`.

:::caution[Keep `AnimRate` between `1` and `255`]
The value is stored in a single byte. `AnimRate=0` does not hold the animation still: it steps once every 256 game frames, a little over 17 seconds. A value above `255` wraps around, so `256` behaves as `0` and `300` as `44`.
:::

The setting is read from the art section named by the projectile's [`Image`](/keys/image/). Write `Image=` in the projectile's rules section even when it would name the section itself. Without it, this setting is not read, not even from an art section named after the projectile, as [where a projectile's artwork is read from](/systems/projectile-flight/#where-a-projectiles-artwork-is-read-from) explains.
