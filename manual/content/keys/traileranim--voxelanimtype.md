---
key: TrailerAnim
scope: voxelanimtype
label: Voxel debris trail
see_also: ["AttachedSystem", "BounceAnim", "ExpireAnim"]
when_omitted:
  kind: value
  value: none
---

`TrailerAnim` names an animation that the piece leaves behind as it flies. A new one is created on every even-numbered frame of the game clock while the piece is alive, so the piece leaves one every other frame. To keep a single effect attached to the piece for its whole flight, use [`AttachedSystem`](/keys/attachedsystem/) instead.

:::caution[The trail appears far above the piece]
Each trail animation takes the piece's horizontal position, but its height is about 8.7 times the piece's height. A piece 100 leptons up leaves its trail about 870 leptons up. Height is measured from the lowest ground level, so the gap also grows over raised terrain.
:::
