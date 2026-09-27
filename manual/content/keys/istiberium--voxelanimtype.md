---
key: IsTiberium
scope: voxelanimtype
label: Voxel Tiberium debris
see_also: ["system:tiberium", "IsMeteor", "Spawns"]
when_omitted:
  kind: value
  value: "no"
---

The flag has two unrelated effects: the piece seeds Tiberium where its life ends, and an unowned piece is drawn in Tiberium colors.

A piece seeds Tiberium when its life ends on land below bridge-deck height. A meteor seeds the eight cells around its impact cell; any other piece seeds the cell beneath it. A cell that cannot take Tiberium is skipped. A piece that ends in water, or at bridge-deck height or above, seeds nothing. [Other sources of Tiberium](/systems/tiberium/#other-sources-of-tiberium) covers which type is planted and at what growth stage.

A piece with no owning house is drawn with the Tiberium color table and lit by the cell beneath it. Without this flag, an unowned piece uses the plain voxel colors at full brightness. A piece with an owning house always uses that house's colors, so the flag does not change how it looks.

Debris thrown by a destroyed object's [`DebrisTypes`](/keys/debristypes/) belongs to that object's house. Pieces a meteor spawns, debris an exploding barrel throws, and pieces a trigger action creates have no house.
