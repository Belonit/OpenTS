---
key: EnemyHealth
summary: Flag intended to hide an enemy object's condition bar.
no_effect: true
see_also: [ConditionYellow, ConditionRed, Selectable]
when_omitted:
  kind: value
  value: "yes"
---

`EnemyHealth=no` hides nothing. An object's condition indicator is drawn, whoever owns it, in any of these cases:

- the object is selected;
- the object is underground in a cell that the player's [sensor arrays](/keys/sensorarray/) detect;
- the object is under the mouse pointer and its type is selectable, unless the player cannot see it there.

A hovered object counts as out of sight when any of these holds:

- its cell is under shroud;
- it is a structure hidden by fog of war in a fog-of-war game;
- it belongs to another house and its type is invisible;
- it belongs to another house, is cloaked or is a structure that has faded out completely, and the player's sensors do not detect it.
