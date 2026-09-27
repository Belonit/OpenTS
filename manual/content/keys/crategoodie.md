---
key: CrateGoodie
summary: Whether the vehicle type is in the random pool a unit crate draws from.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

A unit crate gives a random vehicle from this pool unless another rule has already chosen the vehicle. Those rules are the free MCV or harvester given to a house that needs one, and a type named by [`UnitCrateType`](/keys/unitcratetype/). [Money and free units](/systems/crates/#money-and-free-units) gives the full order.

A vehicle type enters the pool under **All of:**

- it sets `CrateGoodie=yes`;
- the country the collector's house acts as may own it;
- **Any of:** bases are enabled for the match, or it is not in the [`BaseUnit`](/keys/baseunit/) list.

If no vehicle type qualifies for the collecting house, the crate gives nothing: no vehicle and no money.
