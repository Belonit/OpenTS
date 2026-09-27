---
key: UseBlueTiberium
summary: Ignored, because the Firestorm addon alone decides whether a generated map's tiberium fields can grow from the second tiberium overlay set.
see_also: [Tiberium, TiberiumLayout, "system:tiberium"]
when_omitted:
  kind: computed
  note: On with the Firestorm addon enabled and off without it.
---

With the Firestorm addon enabled, some of a generated map's tiberium fields grow from the second tiberium overlay set; without it, none do. Before any map is built, from the dialog or from a seed file, the flag is turned on when Firestorm is enabled and off when it is not. A `UseBlueTiberium=` line in a seed file changes nothing, and the map generator dialog has no control for the flag. [Map seed files](/formats/map-seed/#missing-and-out-of-range-settings) covers the section it is written in and this override.

```ini title="map seed file"
[RandomMap]
UseBlueTiberium=yes
Tiberium=60
```

With the flag on, the fields are rolled as follows:

- Each field spread across the map is rolled for separately, and about three in ten grow from the second set.
- The fields at the players' start points share one roll, and about one time in four they all grow from the second set. Every player therefore starts beside the same kind of tiberium.

The flag also means fewer tiberium trees, because only fields of the first set get one. A spread field of the first set has about a one-in-four chance of a tree, and a start-point field of the first set always has one.
