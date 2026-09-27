---
key: SellSound
summary: Sound played as a structure, a unit or a wall section is sold back.
see_also: [CrumbleSound, GenericClick, RefundPercent, Unsellable]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
SellSound=SELL1 ; a sound ID registered in SOUND.INI
```

The sound plays when the local player sells a structure, a vehicle or aircraft, or a wall section. Sales by other houses play nothing.

A structure plays it from its position as its build-down begins, so it fades with distance from the view. It does not play in two cases:

- Removing an upgrade. Selling an upgraded structure removes one upgrade per sale before the structure itself is sold.
- Selling or undeploying a structure whose type sets [`UndeploysInto`](/keys/undeploysinto/), other than a construction yard.

A vehicle or aircraft sale plays the sound at full volume, not from a map position, together with the spoken "unit sold" line.

A vehicle or aircraft can be sold only while it stands on a [`UnitRepair=yes`](/keys/unitrepair/) structure such as a service depot. Selling that structure while a vehicle or aircraft is docked on it sells the docked unit instead of the structure. Infantry cannot be sold.

A wall section the player sells plays the sound at full volume. A section removed to make room for a structure placed over it is removed without the sound. [Walls and gates](/systems/walls-and-gates/#crushing-clearing-and-selling) covers which sections can be sold.
