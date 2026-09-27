---
key: PaveTile
summary: Tile set whose first tile is a theater's plain pavement.
see_also: [ClearToPaveLat, MiscPaveTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The set's first tile is plain, unbroken pavement. The [`ClearToPaveLat`](/keys/cleartopavelat/) blend treats it as the pavement it edges against, and turns a blended pavement cell back into this tile once pavement surrounds it on all four sides.

The [random map generator](/systems/map-generation/#settlements) paves a town with this tile before it lays the town's roads, buildings and [`MiscPaveTile`](/keys/miscpavetile/) patches. Road planning inside the town looks for this first tile only. When the generator checks whether a cell is pavement before placing a road, a building or a large patch, any of the set's first sixteen tiles qualifies.

:::caution[Set PaveTile in any theater that gets towns]
The generator does not check that this role is bound. Without it, the generator paves towns with a tile that does not exist, which can crash the game. It also takes any of the theater's first fifteen tiles for pavement, including tile 0, which the game treats as clear ground.
:::
