---
key: Warhead
scope: weapontype
label: Weapon warhead
see_also: ["Verses", "Damage", "Projectile", "Bright", "system:target-selection"]
when_omitted:
  kind: value
  value: none
---

The warhead decides what the weapon's [`Damage=`](/keys/damage/#scope-weapontype) does where a shot lands. It sets how much of the damage each armor type takes, how far the blast spreads and which explosion is drawn. It also adds effects such as an electromagnetic pulse or webs. It decides whether the blast knocks down walls and whether it sets off volatile Tiberium.

```ini title="rules.ini"
[MyCannon] ; example WeaponType
Damage=90
Warhead=AP ; a WarheadType registered in [Warheads]
Projectile=Cannon ; a BulletType, registered by naming it here
```

The beam of an [`IsRailgun=yes`](/keys/israilgun/) weapon uses this warhead. A sonic wave uses the warhead of its firer's first weapon, as [`IsSonic`](/keys/issonic/) describes. The [Do Explosion At](/mapping/actions/taction-do-explosion/) trigger action also uses the named weapon's damage and warhead, without its projectile, sounds or firing animation.

The warhead's [`Verses`](/keys/verses/) table also affects which targets an object picks. It supplies both effectiveness terms of the [threat score](/systems/target-selection/#the-threat-score). An object also does not return fire at an attacker when the warhead of the weapon it would answer with has a `Verses` value of 0% against that attacker's armor.

A name the game does not already know is registered as a new warhead of that name. If no rules file has a section of that name, the warhead keeps every warhead default: it deals full damage against every armor type and draws no explosion. A misspelled name therefore produces a shot that lands with no explosion, not an error.

:::danger[Give every weapon a warhead]
With `Warhead=none`, or with the key left out, the weapon has no warhead, and the game crashes as soon as it needs the warhead. Events that need it include:

- a shot from the weapon lands;
- an infantry whose first weapon it is looks for a target;
- the rules are loaded, if it is the first weapon of an [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype) structure and its projectile is [`AA=yes`](/keys/aa/) or [`AG=yes`](/keys/ag/);
- the owning house places, loses or captures a building, if it is the first weapon of any structure the house owns and its projectile is `AA=yes` or `AG=yes`, unless the house's only structure costs under 1000;
- a computer house picks a guard spot in its base for a unit whose first weapon it is, such as one it has just built, if the projectile is `AA=yes` or `AG=yes`;
- the owning house's base is attacked and the house considers sending an infantry or vehicle whose first weapon it is.
:::
