---
key: MissileSpeedVar
summary: Parsed fraction that the engine never uses.
no_effect: true
see_also: [MissileROTVar]
when_omitted:
  kind: value
  value: ".25"
---

Homing projectiles have no speed variation to match the turn-rate weave of [`MissileROTVar`](/keys/missilerotvar/). Their speed comes from the firing weapon and the BulletType:

- It leaves the launcher at one lepton per frame, accelerates toward the weapon's [`Speed`](/keys/speed/#scope-weapontype), and then holds that speed.
- With a weapon `Speed` of `40` or more, it gains the BulletType's [`Acceleration`](/keys/acceleration/#scope-bullettype) each frame.
- With a lower `Speed`, it gains one lepton of speed every other frame until it reaches the weapon's `Speed`.
- If it is ever moving faster than the weapon's `Speed`, it slows by half the BulletType's `Acceleration` each frame, rounded down.
