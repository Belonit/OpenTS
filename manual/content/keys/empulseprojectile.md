---
key: EMPulseProjectile
summary: Parsed BulletType that the engine never uses.
no_effect: true
see_also: [EMPulseWarhead, EMPulseCannon, "system:emp-pulse"]
when_omitted:
  kind: value
  value: none
---

An EM pulse cannon does not launch this projectile. [Firing the cannon](/systems/emp-pulse/#em-pulse-cannon-superweapon) fires the structure's primary weapon, so the shot uses that weapon's [`Projectile=`](/keys/projectile/).
