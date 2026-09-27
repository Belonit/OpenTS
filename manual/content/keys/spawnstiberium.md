---
key: SpawnsTiberium
summary: Makes a TerrainType seed Tiberium into the cells around it.
see_also: ["system:tiberium", "TiberiumToSpawn"]
when_omitted:
  kind: value
  value: "no"
---

A Tiberium-spawning terrain object, such as a blossom tree, seeds the cells around it only if its type also sets [`IsAnimated=yes`](/keys/isanimated/). Each time its animation reaches the middle frame of its shape file, the animation stops and the object plants stage 5 Tiberium in one neighboring cell. The type is the one in Tiberium slot [`TiberiumToSpawn`](/keys/tiberiumtospawn/). [Other sources of Tiberium](/systems/tiberium/#other-sources-of-tiberium) covers which neighbors qualify.

Every cell of the object's [`Foundation`](/keys/foundation/#scope-terraintype) block without a Tiberium overlay counts as holding that Tiberium type. Infantry take [Tiberium damage](/systems/tiberium/#damage) there as in any Tiberium cell. A harvester collects nothing from these cells.

Placing the object removes any overlay already in its top-left cell, and new Tiberium cannot take root in any cell of its block.

The flag also changes how the object is drawn and destroyed:

- Its artwork is drawn 16 pixels higher than that of an ordinary terrain object.
- It never catches fire, as [`TreeFlammability`](/keys/treeflammability/) describes.
- When destroyed, it explodes, as [What the ground keeps](/systems/destruction-and-debris/#what-the-ground-keeps) describes.
