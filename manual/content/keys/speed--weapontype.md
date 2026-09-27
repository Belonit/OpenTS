---
key: Speed
scope: weapontype
label: Projectile launch speed
when_omitted:
  kind: value
  value: "0"
---

The value is the speed of the weapon's projectile, on the same `0` to `100` scale as an [object's top speed](/keys/speed/#scope-aircrafttype). Values outside that range are clamped, and `Speed=-1` counts as leaving the key out. What the speed controls depends on the projectile's [`ROT`](/keys/rot/#scope-bullettype):

- A homing projectile, with `ROT` above 0, is launched at one lepton per frame and accelerates to this speed.
- Any other projectile is launched at this speed. The launch speed is capped so that the projectile covers at most half the distance to its target in its first frame.

The firer aims ahead of a moving vehicle target by an amount based on its first weapon's projectile speed. The slower that projectile, the further ahead it aims.

:::caution[A projectile with ROT=0 ignores this value]
If the weapon's [`Projectile=`](/keys/projectile/) sets [`ROT=0`](/keys/rot/#scope-bullettype), the value written here is replaced after each rules file is read. The new launch speed is worked out from the weapon's [`Range=`](/keys/range/#scope-weapontype) and the gravity the projectile falls under, so that the shot can reach the weapon's full range.
:::
