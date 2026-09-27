---
key: Foundation
scope: terraintype
label: Terrain footprint
when_omitted:
  kind: value
  value: "1x1"
---

The value selects the block of cells a terrain object stands on. It is one of the [building foundation](/reference/enums/building-foundation/) names a structure uses, matched without regard to case, and any other value gives `1x1`.

The object occupies every cell of the block. A vehicle is refused those cells unless it can destroy the object; [Movement and terrain](/systems/movement-and-terrain/#why-a-cell-refuses-a-vehicle) owns that test. Infantry standing places are filled only in the object's top-left cell, as [`TemperateOccupationBits`](/keys/temperateoccupationbits/) describes.

:::danger[Use only the first eight names on a terrain object]
Only `1x1`, `2x1`, `1x2`, `2x2`, `2x3`, `3x2`, `3x3` and `3x5` give a terrain object a block of cells. Any other name makes the game hang once something searches the object's top-left cell. Placing the object makes that cell's list of occupants loop back on the object, so a search of the cell for a structure, vehicle or infantry never finishes. The tests that check the object's cells, such as whether it may stand on them, also read past the end of the engine's footprint table, so their results depend on unrelated data.
:::

:::caution[On a terrain object 3x5 is a 4x2 block]
A TerrainType with `Foundation=3x5` stands on a block four cells by two, not three by five.
:::
