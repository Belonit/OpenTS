---
key: Trailer
summary: The animation left behind the projectile as it flies.
see_also: [Image, Inviso]
when_omitted:
  kind: value
  value: none
---

The projectile drops one copy of the animation at its current position on every third game frame, five times a second at 15 frames a second. Each puff starts one frame after it is dropped and plays through as many times as the animation's [`LoopCount`](/keys/loopcount/) says, at least once.

The frames are counted on the game clock, not from the projectile's launch, so every trailing projectile in a match drops its puffs on the same frames.

A shot with a [head start](/systems/firing-geometry/#the-shot-step-by-step) moves three times in the frame it is fired. If that frame is one of the trail frames, the shot leaves three puffs a step apart, the first at the point it was fired from.

A [`Voxel=yes`](/keys/voxel/) projectile leaves a trail just as a shape-drawn one does.

An [`Inviso=yes`](/keys/inviso/) projectile is placed on its target when it is fired, so any puff it leaves appears on the target.

The setting is read only when the projectile's rules section sets [`Image`](/keys/image/), and it is read from the art section that `Image` names. A rules file that declares the projectile without `Image=` skips this setting, and the projectile keeps the trail an earlier file gave it, or none. An art section named after the projectile is not used in its place. [Where a projectile's artwork is read from](/systems/projectile-flight/#where-a-projectiles-artwork-is-read-from) lists the other art settings this affects.

```ini title="rules.ini"
[MYMISSILE]        ; a BulletType, registered by a weapon naming it as its Projectile
Image=MYMISSILEART ; required, or Trailer is not read
```

```ini title="art.ini"
[MYMISSILEART]     ; the Image ID named above
Trailer=SMOKEY2    ; an AnimType registered in [Animations]
```
