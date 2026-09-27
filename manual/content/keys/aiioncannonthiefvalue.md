---
key: AIIonCannonThiefValue
summary: The ion cannon rating a computer house gives an enemy vehicle thief.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

The rating applies only while the thief's strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A thief above that figure keeps the starting rating of 1. The computer strikes one of the candidates that share the highest rating, so this value matters only against the other ratings; [the computer's use](/systems/superweapons/#the-computers-use) lists them.

A vehicle thief is an InfantryType with [`VehicleThief=yes`](/keys/vehiclethief/). A type that is also an engineer takes [`AIIonCannonEngineerValue`](/keys/aiioncannonengineervalue/) instead, because the engineer test runs first. Other infantry at or below `IonCannonDamage` is rated 2.

The list holds one rating for each [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot), in slot order 0, 1, 2. The firing house's slot selects the entry. Give all three entries in a rules file or the map. If neither sets the key, the game crashes the first time the computer rates a thief at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
