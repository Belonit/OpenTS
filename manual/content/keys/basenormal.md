---
key: BaseNormal
summary: Whether this placed building can anchor later building placements.
see_also: [Adjacent, "system:base-adjacency"]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="rules.ini"
[GAPOWR]
BaseNormal=no
```

`BaseNormal=no` stops a placed `GAPOWR` from serving as an [anchor](/systems/base-adjacency/), so a player cannot use it to place another building nearby. This applies to the owner's placements and to an ally's alike.

The setting belongs to the building already on the map. How far a pending building searches for an anchor is set by that pending building's [`Adjacent`](/keys/adjacent/).
