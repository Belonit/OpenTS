---
key: Bright
scope: weapontype
label: Weapon flash
when_omitted:
  kind: value
  value: "no"
---

`Bright=yes` makes every projectile the weapon fires light up the ground where it explodes.

```ini title="rules.ini"
[MyCannon] ; example WeaponType
Damage=400
Bright=yes ; the impact lights the surrounding ground
```

The flash is larger for a stronger shot. Its size is a quarter of the damage the projectile carries when it explodes, rounded down and held between 21 and 63. A shot of up to 87 damage gives the smallest flash, and a shot of 252 or more gives the largest. Whatever its size, every flash grows to full size within three game frames and shrinks away over the next seven.

:::caution[Set Bright on the weapon to light projectile impacts]
A projectile's explosion ignores the [warhead's `Bright=`](/keys/bright/#scope-warheadtype). That setting lights explosions created without a projectile, which its page lists. A projectile whose warhead sets `Bright=yes` explodes without a flash unless its weapon sets `Bright=yes` too.
:::
