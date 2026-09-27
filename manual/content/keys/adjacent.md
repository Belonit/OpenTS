---
key: Adjacent
summary: How far this building searches for an eligible anchor while it is being placed.
see_also: [BaseNormal, "system:base-adjacency"]
when_omitted:
  kind: value
  value: "3"
---

```ini title="rules.ini"
[GAPOWR]
Adjacent=5
```

`Adjacent` sets how far from an [anchor](/systems/base-adjacency/) a player may place a building of this type. An anchor is a building already on the map that has [`BaseNormal=yes`](/keys/basenormal/) and belongs to the placing player, or to a mutual ally when the match allows [building off an ally](/systems/base-adjacency/#building-off-an-ally). A larger value lets the building stand farther from its anchor.

The search covers every cell up to `Adjacent` + 1 cells beyond each edge of the pending foundation, corners included. With `Adjacent=5`, it reaches six cells out. `Adjacent=0` still finds an anchor that touches the foundation, including diagonally. A negative value leaves no cells to search, so no anchor is ever found.

The value belongs to the building being placed. It is not a radius around a building already on the map, so raising it on one type changes nothing for other types. Computer houses place their buildings without the search, and [Base placement and adjacency](/systems/base-adjacency/) lists the other placements it does not apply to.
