---
key: WeaponType
summary: The WeaponType a missile silo launches, read only from the first and sixth entries of the superweapon list.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

A missile silo launching a repeating `Type=MultiMissile` or `Type=ChemMissile` superweapon takes the missile's projectile, warhead, maximum speed and projectile range from the WeaponType this key names, in the section the caution below identifies. It ignores that WeaponType's `Damage=` and gives the missile [a fixed strength of 200](/systems/superweapons/#multi-missile-and-chem-missile).

No other use of a superweapon reads this key. A one-time missile, granted by a trigger action or a crate, is built from the hard-coded weapons `MultiLauncher` and `ChemLauncher` instead.

:::caution[The silo reads this key by list position]
A silo does not read the `WeaponType=` of the section that ordered the launch. It reads the section at a fixed position in `[SuperWeaponTypes]`: the first entry for every `Type=MultiMissile` launch and the sixth for every `Type=ChemMissile` launch. The shipped list puts its multi missile and chem missile sections at those positions.

A custom `Type=MultiMissile` section added after the shipped seven therefore charges and fires normally, but its missile uses the first entry's `WeaponType=`. [Declaring a superweapon](/systems/superweapons/#declaring-a-superweapon) gives the full order to keep.
:::

:::danger[Give the first and sixth sections a WeaponType]
Set `WeaponType=` in the first section of `[SuperWeaponTypes]` when any section uses `Type=MultiMissile`, and in the sixth when any section uses `Type=ChemMissile`. If the section a launch reads sets none, the game crashes when the silo launches the missile.
:::
