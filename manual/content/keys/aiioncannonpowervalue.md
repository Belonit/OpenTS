---
key: AIIonCannonPowerValue
summary: The ion cannon rating a computer house gives an enemy structure that produces more power than it draws.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

Applies to a structure whose [`Power=`](/keys/power/#scope-buildingtype) is positive, that is, one that supplies power. The test reads the type's `Power=`, not the house's power balance. A structure that builds structures or vehicles is tested first and takes [`AIIonCannonConYardValue`](/keys/aiioncannonconyardvalue/) or [`AIIonCannonWarFactoryValue`](/keys/aiioncannonwarfactoryvalue/) instead.

The computer uses this rating only while the structure's current strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A stronger structure keeps its starting rating of 3. A cloaked structure is rated at random at any strength. The computer strikes one of the [highest-rated targets](/systems/superweapons/#the-computers-use), so a higher value puts power plants ahead of more kinds of target.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists) of the firing house, so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. The key has no built-in list. If no rules file sets it, the game crashes the first time the computer rates a power plant at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
