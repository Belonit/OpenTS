---
key: AIIonCannonPlugValue
summary: The ion cannon rating a computer house gives an enemy IsPlug structure.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

Applies to a structure with [`IsPlug=yes`](/keys/isplug/). A structure that builds structures or vehicles, has a positive [`Power=`](/keys/power/#scope-buildingtype), or sets [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype) is tested first and takes that rating instead.

In the shipped rules only the GDI Upgrade Center, which takes upgrades, sets `IsPlug=yes`. Setting it on an upgrade type has no effect here, because an upgrade merges into its host when placed and is never on the map to be rated.

The computer uses this rating only while the structure's current strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A stronger structure keeps its starting rating of 3. A cloaked structure is rated at random at any strength. The computer strikes one of the [highest-rated targets](/systems/superweapons/#the-computers-use), so a higher value puts these structures ahead of more kinds of target.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists) of the firing house, so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. The key has no built-in list. If no rules file sets it, the game crashes the first time the computer rates an `IsPlug=yes` structure at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
