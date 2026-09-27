---
key: AIIonCannonHelipadValue
summary: The ion cannon rating a computer house gives an enemy HoverPad structure.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

Applies to a structure with [`HoverPad=yes`](/keys/hoverpad/). It is the last of the seven structure tests, so a pad that matches any [earlier test](/systems/superweapons/#the-computers-use), such as a positive [`Power=`](/keys/power/#scope-buildingtype) or [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype), takes that rating instead. A structure that matches none of the seven is rated 4 while its strength is at or below `IonCannonDamage`.

The computer uses this rating only while the structure's current strength is at or below [`IonCannonDamage`](/keys/ioncannondamage/). A stronger structure keeps its starting rating of 3. A cloaked structure is rated at random at any strength. The computer strikes one of the [highest-rated targets](/systems/superweapons/#the-computers-use), so a higher value puts pads ahead of more kinds of target.

Each entry belongs to one [difficulty slot](/systems/difficulty/#the-per-difficulty-lists) of the firing house, so give the list three entries. For a computer house the first entry is used at the Hard setting and the last at Easy. The key has no built-in list. If no rules file sets it, the game crashes the first time the computer rates a pad at or below `IonCannonDamage`. A list with fewer than three entries gives an unpredictable rating in the slots it does not cover.
