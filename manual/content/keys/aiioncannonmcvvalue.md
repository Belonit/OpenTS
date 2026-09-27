---
key: AIIonCannonMCVValue
summary: The ion cannon rating a computer house gives an enemy vehicle that deploys into a construction yard.
see_also: [IonCannonDamage, BuildConst, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

Applies to a vehicle whose [`DeploysInto`](/keys/deploysinto/) names a type listed in [`BuildConst`](/keys/buildconst/). A vehicle that deploys into anything else is not covered. A [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle is tested first and takes [`AIIonCannonHarvesterValue`](/keys/aiioncannonharvestervalue/) instead.

The computer uses this rating only while the vehicle's current strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A stronger vehicle keeps its starting rating of 1. A cloaked vehicle is rated at random at any strength. The computer strikes one of the [highest-rated targets](/systems/superweapons/#the-computers-use), so a higher value puts these vehicles ahead of more kinds of target.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists) of the firing house, so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. The key has no built-in list. If no rules file sets it, the game crashes the first time the computer rates a vehicle that deploys into a construction yard at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
