---
key: GDIFirestormGenerator
summary: The BuildingType whose loss discharges a house's firestorm superweapon and brings down its wall.
see_also: [FirestormWall, "system:laser-fences", "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

While a house's firestorm wall is up, losing its last working structure of exactly this type brings the wall down. When such a structure is switched off or taken off the map, the house looks for another one that still qualifies. If it finds none, every [`Type=Firestorm`](/keys/type/#scope-superweapontype) superweapon the house holds is [discharged](/systems/superweapons/#the-firestorm-defense), and the wall comes down. [Losing the generator](/systems/laser-fences/#losing-the-generator) lists what makes a structure qualify.

For a house a human is playing, the discharge is the same as clicking the superweapon's cameo a second time. The drain the wall had not yet spent is returned as charge.

Losing the last working structure of this type brings the wall down even while another structure still grants the superweapon through `SuperWeapon=`. This key never lowers the wall of a house that owns no structure of this type. That wall comes down only in the ways every firestorm wall does, such as losing the structure that grants the superweapon.
