---
key: HunterSeeker
scope: side
label: Side hunter-seeker drone
see_also: [HSBuilding, "system:superweapons"]
when_omitted:
  kind: computed
  note: The first side takes GDIHunterSeeker and the second NodHunterSeeker, as each rules file sets them; any other side names none and launches nothing.
---

```ini title="rules.ini"
[GDI] ; the section named after the side
HunterSeeker=GHUNTER
```

The UnitType a [hunter-seeker superweapon](/systems/superweapons/#hunter-seeker) launches when a house playing for this side fires it. The drone appears near the house's [`HSBuilding`](/keys/hsbuilding/) structure, facing east. When the side names no drone, firing spends the charge and launches nothing.

Any UnitType can be named here, but only a type on the flying locomotor is given a target. At launch, such a type is assigned a random enemy object, when one exists, and ordered to attack it. Only a type that also sets [`HunterSeeker=yes`](/keys/hunterseeker/#scope-aircrafttype) dives onto that target and detonates as a drone. A type on any other locomotor gets no target, even with `HunterSeeker=yes`.
