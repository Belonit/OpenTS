---
key: AIIonCannonTempleValue
summary: The ion cannon rating a computer house gives an enemy IsTemple structure.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

The rating applies only while the structure's strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A structure above that figure keeps the starting structure rating of 3. The computer strikes one of the candidates that share the highest rating, so this value matters only against the other ratings; [the computer's use](/systems/superweapons/#the-computers-use) lists them.

The structure tests run in a fixed order, and the first match decides the rating. An [`IsTemple=yes`](/keys/istemple/) structure is rated here only if it matches none of the earlier tests:

- [`Factory=BuildingType`](/keys/factory/)
- `Factory=UnitType`
- a positive [`Power=`](/keys/power/)
- [`IsBaseDefense=yes`](/keys/isbasedefense/)
- [`IsPlug=yes`](/keys/isplug/)

The list holds one rating for each [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot), in slot order 0, 1, 2. The firing house's slot selects the entry. Give all three entries in a rules file or the map. If neither sets the key, the game crashes the first time the computer rates a temple at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
