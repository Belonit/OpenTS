---
key: AIIonCannonHarvesterValue
summary: The ion cannon rating a computer house gives an enemy harvesting vehicle.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

Applies to a vehicle type with [`Harvester=yes`](/keys/harvester/#scope-unittype). It is the first vehicle test, so a harvester never takes the rating for a vehicle that deploys into a construction yard or one that carries passengers.

The computer uses this rating only while the harvester's current strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A stronger harvester keeps its starting rating of 1. A cloaked harvester is rated at random at any strength. The computer strikes one of the [highest-rated targets](/systems/superweapons/#the-computers-use), so a higher value puts harvesters ahead of more kinds of target.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists) of the firing house, so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. The key has no built-in list. If no rules file sets it, the game crashes the first time the computer rates a harvester at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
