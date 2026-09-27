---
key: Theater
scope: scenarios
label: Scenario theater
see_also: [IceGrowthEnabled]
when_omitted:
  kind: context-dependent
  note: "The first theater the rules declare, which is TEMPERATE unless a [Theaters] list puts another first."
---

```ini title="map file"
[Map]
Theater=SNOW
```

The theater decides which tile, art and palette archives are mounted for the whole map load, so it is settled before the map's houses, objects, terrain and rules overrides are read. Unlike most scenario-wide settings, it goes under `[Map]`, not `[Basic]`.

The value names one of the theaters the rules file lists in [`[Theaters]`](/formats/rules-registries/), ignoring case. Rules that declare no such section still have `TEMPERATE` and `SNOW`, in that order. A name that matches no theater is ignored, and the map is played in the first declared theater.

The theater also decides whether ice grows. [`IceGrowthEnabled`](/keys/icegrowthenabled/) does nothing in a theater whose [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) is off.
