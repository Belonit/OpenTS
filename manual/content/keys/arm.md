---
key: Arm
summary: How long after launch a projectile's proximity fuse is held shut, in game frames.
see_also: [ROT, Proximity]
when_omitted:
  kind: value
  value: "0"
---

The delay starts at launch and is counted in game frames, 15 to the second. Until it runs out, the fuse cannot set the projectile off.

Only a projectile with a [`ROT`](/keys/rot/#scope-bullettype) above zero has a fuse. On a projectile whose `ROT` is zero, this setting has no effect.

A shot fired at an aircraft is armed at once, whatever `Arm` says.

Once armed, the fuse trips when the projectile comes within 64 leptons of the fuse point, height included, or when it is within two cells of the fuse point and moving away from it.

The fuse point is the target's position at the moment of launch, not the predicted aim point. It does not follow a target that moves afterward.

```ini title="rules.ini"
[MYSEEKER] ; a BulletType, registered by a weapon naming it as its Projectile
Image=MISSILE
ROT=5
Arm=30 ; the fuse cannot trip for the first two seconds of flight
```

:::caution[Arming holds off only the fuse]
While the fuse is shut, a steered projectile still goes off when it arrives at its target, reaches the ground, or stops gaining on its target. Every other path in [what ends a flight](/systems/projectile-flight/#what-ends-a-flight) applies too. A very large `Arm` therefore does not make a projectile fly forever. It only stops the fuse from ever setting it off.
:::
