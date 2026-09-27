---
key: AIIonCannonAPCValue
summary: The ion cannon rating a computer house gives an enemy vehicle that can carry passengers.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

Applies to a vehicle whose type sets [`Passengers`](/keys/passengers/) above zero, whether or not it is carrying anyone. A [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle, or one that deploys into a [`BuildConst`](/keys/buildconst/) type, is tested first and takes [`AIIonCannonHarvesterValue`](/keys/aiioncannonharvestervalue/) or [`AIIonCannonMCVValue`](/keys/aiioncannonmcvvalue/) instead. A vehicle that matches none of the three vehicle ratings is rated 2 while its strength is at or below `IonCannonDamage`.

The computer uses this rating only while the vehicle's current strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A stronger vehicle keeps its starting rating of 1. A cloaked vehicle is rated at random at any strength. The computer strikes one of the [highest-rated targets](/systems/superweapons/#the-computers-use), so a higher value puts transports ahead of more kinds of target.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists) of the firing house, so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. The key has no built-in list. If no rules file sets it, the game crashes the first time the computer rates a transport at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
