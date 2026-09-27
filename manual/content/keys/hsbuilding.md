---
key: HSBuilding
summary: The BuildingTypes a hunter-seeker drone may walk out of.
see_also: [GDIHunterSeeker, NodHunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: ""
---

When a [`Type=HunterSeeker`](/keys/type/#scope-superweapontype) superweapon fires, the drone leaves the firing house's structure of a listed type. If the house owns several, the drone uses the one created most recently, not the first listed type. It appears on the nearest cell to that structure that infantry could stand in.

A listed building that is still being built on the sidebar, or is ready and waiting to be placed, already counts as owned. Being the newest, it is the one chosen. It is not on the map yet, so the drone either appears away from the house's base or does not launch. A failed launch still spends the charge.

```ini title="rules.ini"
[SpecialWeapons]
HSBuilding=GAPLUG,NATMPL   ; the stock list: GDI Upgrade Center and Temple of Nod
```

Nothing launches, and the charge is still spent, when **any of:**

- the list is empty, or the house owns none of the listed types;
- the chosen cell lies outside the playable area;
- the house [acts as](/keys/actslike/) no side, or that side names no drone in its [`HunterSeeker=`](/keys/hunterseeker/#scope-side);
- the drone cannot be placed on the chosen cell.
