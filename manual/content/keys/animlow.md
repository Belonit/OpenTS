---
key: AnimLow
summary: The frame the projectile's flight animation returns to when it loops.
see_also: [AnimHigh, AnimRate, Rotates, Image]
when_omitted:
  kind: value
  value: "0"
---

Once the shape steps past [`AnimHigh`](/keys/animhigh/), it starts again on this frame instead of at the beginning of the artwork. A value above `0` therefore keeps a few leading frames out of the loop.

The animation runs only while this key or `AnimHigh` is other than `0`. [`AnimHigh`](/keys/animhigh/) covers what is drawn when both are `0`.

A new projectile always starts on frame `0`, so this value is skipped on the first pass and takes effect from the second.

A value higher than `AnimHigh` holds the shape still on this frame after the first pass, because every step from here is already past the last frame of the loop. The exception is `255`: the next step wraps the frame number to `0`, so the shape runs from frame `0` through `AnimHigh`, shows frame `255` once, and repeats.

The value is stored in a single byte, so `256` is stored as `0` and anything above `255` wraps around.

The setting is read from the art section named by the projectile's [`Image`](/keys/image/). Write `Image=` in the projectile's rules section even when it would name the section itself. Without it, this setting is not read, not even from an art section named after the projectile, as [where a projectile's artwork is read from](/systems/projectile-flight/#where-a-projectiles-artwork-is-read-from) explains.
