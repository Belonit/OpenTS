---
key: Type
scope: superweapontype
label: Superweapon behavior
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

`Type=` selects which of the engine's seven built-in effects the weapon delivers when it fires: `MultiMissile`, `EMPulse`, `Firestorm`, `IonCannon`, `HunterSeeker`, `ChemMissile` or `DropPod`, in any letter case. [What each behavior delivers](/systems/superweapons/#what-each-behavior-delivers) describes them.

The section's other keys set the rest: its delay, cameo, cursor and required [`AuxBuilding=`](/keys/auxbuilding/) structure. Several sections can therefore share one behavior and remain independent weapons. Three things come from elsewhere:

- A `Type=EMPulse` weapon takes its cursor from its behavior, as [`Action=`](/keys/action/#scope-superweapontype) explains.
- A repeating `MultiMissile` or `ChemMissile` weapon launches from its silo the `WeaponType=` of the section at a fixed position in `[SuperWeaponTypes]`, as [the declaration warning](/systems/superweapons/#declaring-a-superweapon) explains.
- A one-time `MultiMissile` or `ChemMissile` weapon fires the hard-coded weapon `MultiLauncher` or `ChemLauncher` and ignores its section's `WeaponType=`.

An unrecognized name is ignored, and the section keeps the behavior it already had. A section that has never named a valid behavior has none: it charges, shows a cameo and can be fired, but firing it has no effect.

Firing a `Type=Firestorm` weapon raises the [firestorm wall](/systems/superweapons/#the-firestorm-defense). Only a [`UseChargeDrain=yes`](/keys/usechargedrain/) weapon lowers it again, for example when fired a second time or when its drain runs out. Without that key, nothing lowers the wall once the first shot raises it. The stock firestorm section sets both keys.
