---
key: Elite
summary: The WeaponType an elite object fires in place of its primary.
see_also: ["system:veterancy", "system:target-selection"]
when_omitted:
  kind: value
  value: none
  note: With no elite weapon, an elite object keeps firing its primary weapon.
---

Once an object reaches elite rank, it uses this weapon in place of its primary for target selection, range checks, reload delay and firing. The secondary weapon is never replaced, and a veteran still fires its ordinary weapons. [The elite weapon](/systems/veterancy/#the-elite-weapon) covers the rest of the substitution.

```ini title="rules.ini"
[MYTANK] ; example UnitType
Primary=MyCannon     ; each names its own weapon section
Elite=MyEliteCannon
```

The elite weapon fires from the primary weapon's muzzle position. It uses the primary's [`PrimaryFireFLH`](/keys/primaryfireflh/), [`PBarrelLength`](/keys/pbarrellength/) and [`PBarrelThickness`](/keys/pbarrelthickness/) art settings.

:::caution[An upgrade's weapon replaces this one]
A structure with an upgrade installed uses the upgrade's primary weapon when the upgrade supplies one. The structure's `Elite` weapon then never applies, whatever the structure's rank.
:::
