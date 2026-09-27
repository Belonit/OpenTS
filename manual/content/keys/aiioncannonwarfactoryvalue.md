---
key: AIIonCannonWarFactoryValue
summary: The ion cannon rating a computer house gives an enemy structure that produces vehicles.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

The rating applies only while the structure's strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A structure above that figure keeps the starting structure rating of 3. The computer strikes one of the candidates that share the highest rating, so this value matters only against the other ratings; [the computer's use](/systems/superweapons/#the-computers-use) lists them.

The rating covers a [`Factory=UnitType`](/keys/factory/) structure. The structure tests run in a fixed order, and the first match decides the rating. Only the test for a `Factory=BuildingType` structure comes earlier, so a war factory that also generates power or is a base defense is still rated here.

The list holds one rating for each [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot), in slot order 0, 1, 2. The firing house's slot selects the entry. Give all three entries in a rules file or the map. If neither sets the key, the game crashes the first time the computer rates a war factory at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
