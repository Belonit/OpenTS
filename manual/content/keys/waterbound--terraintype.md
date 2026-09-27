---
key: WaterBound
scope: terraintype
label: Water-based terrain object
see_also: [Foundation]
when_omitted:
  kind: value
  value: "no"
---

The flag decides which ground a terrain object may stand on. A `WaterBound=yes` object is tested against the `Float` column of the [land types](/systems/movement-and-terrain/#the-terrain-table), and any other object against the `Track` column. A cell of the object's [`Foundation`](/keys/foundation/#scope-terraintype) block fails the test when any of these is true:

- It lies outside the playable area.
- It holds a wall, or an overlay without [`BuildableOver=yes`](/keys/buildableover/).
- Its land type's value in the tested column is `0`.

The test does not read [`Buildable=`](/keys/buildable/), which decides where structures may be placed.

Terrain a scenario places is not tested, so it stands where the map puts it whatever the ground. The test runs when a low bridge is destroyed, for each terrain object in a cell under the bridge. For an object larger than one cell, the block is laid out with that bridge cell as its top-left cell, so the cells tested can differ from the cells the object stands on. An object that fails takes damage equal to its remaining strength through [`C4Warhead`](/keys/c4warhead/). That destroys it unless the warhead lacks [`Wood=yes`](/keys/wood/) or the terrain type sets [`Immune=yes`](/keys/immune/#scope-aircrafttype).
