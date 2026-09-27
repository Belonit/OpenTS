---
key: TiberiumSpreadRadius
summary: Selects which of the eight cells around a landing animation can take Tiberium.
see_also: ["IsTiberium", "TiberiumSpawnType", "system:tiberium"]
when_omitted:
  kind: value
  value: "0"
---

The setting applies only to an animation that sets [`IsTiberium=yes`](/keys/istiberium/#scope-animtype), names a [`TiberiumSpawnType`](/keys/tiberiumspawntype/), and is thrown by [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype).

Despite the name, the setting never reaches beyond the eight cells touching the landing cell, and never plants the landing cell itself. Each step up adds the next neighbor on each side of north:

| Setting | Cells that can take Tiberium |
| --- | --- |
| `0` | north |
| `1` | northwest, north, northeast |
| `2` | west through east across the north |
| `3` | southwest through southeast across the north |
| `4` and above | all eight neighbors |

A negative setting plants nothing. [`IsTiberium`](/keys/istiberium/#scope-animtype) lists which of these cells can actually take Tiberium.

:::caution[The default still plants]
`0` does not turn planting off. An animation that sets `IsTiberium=yes`, names a `TiberiumSpawnType` and leaves this setting out plants the cell north of where it lands. Every shipped animation that plants Tiberium either sets `0` or leaves the setting out.
:::
