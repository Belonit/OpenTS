---
key: AnimHigh
summary: The last frame of the projectile's looping flight animation.
see_also: [AnimLow, AnimRate, Rotates, Image]
when_omitted:
  kind: value
  value: "0"
---

The projectile's shape steps forward one frame at a time and returns to [`AnimLow`](/keys/animlow/) after it passes this frame. The two keys set the loop, and [`AnimRate`](/keys/animrate/) sets how fast it runs.

The animation runs only while at least one of the two frame numbers is not `0`. With both at `0`, the shape is chosen from the projectile's heading instead, which is what [`Rotates`](/keys/rotates/) controls. With either set, the animation frame is drawn and the heading is ignored.

A new projectile always starts on frame `0`, not on `AnimLow`. Its first pass runs from the beginning of the artwork, and only later passes stay inside the loop.

```ini title="art.ini"
[MYFLAREART] ; the Image ID that the projectile's Image assignment names
AnimPalette=yes
AnimLow=0
AnimHigh=5 ; six frames, restarting at the first
AnimRate=1
```

The value is stored in a single byte, so `256` is stored as `0` and anything above `255` wraps around. At `255` the frame counter wraps back to `0` before it can pass this frame, so the animation runs through every frame number from `0` and never returns to `AnimLow`.

The setting is read from the art section named by the projectile's [`Image`](/keys/image/). Write `Image=` in the projectile's rules section even when it would name the section itself. Without it, this setting is not read, not even from an art section named after the projectile, as [where a projectile's artwork is read from](/systems/projectile-flight/#where-a-projectiles-artwork-is-read-from) explains.
