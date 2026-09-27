---
key: DemandLoad
scope: overlaytype
label: Overlay shape
see_also: ["Image", "NewTheater", "Theater"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="art.ini"
[BTIB01]
DemandLoad=yes
```

With `DemandLoad=yes`, the overlay's shape is not loaded with the rest of the rules. It is loaded the first time the game needs it, and then kept. Loading a map loads the shape of every overlay type the map places. After a saved game is loaded, the shape is loaded again the first time the game needs it.

A demand-loaded shape is a separate copy for each overlay type. Two overlay types with the same [Image ID](/keys/image/) each load their own copy.

The file name is formed the same way as for any overlay. An ordinary overlay loads its Image ID with a `.SHP` extension. [`Theater=yes`](/keys/theater/) uses the theater's extension instead, and [`NewTheater=yes`](/keys/newtheater/) rewrites the `.SHP` name for the theater.

The copy is freed when the rules are read again or the type is discarded. An overlay with `Theater=yes` or `NewTheater=yes` also frees its copy whenever a map sets up its theater, so the next request loads the artwork for the new theater.
