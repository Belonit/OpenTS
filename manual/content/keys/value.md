---
key: Value
summary: Credits paid for each growth stage of a Tiberium type.
see_also: ["system:tiberium"]
when_omitted:
  kind: value
  value: "0"
  note: Cells of the type are worth nothing.
---

A harvester lifts one growth stage at a time and carries each as one unit of Tiberium. Each unit is worth `Value` credits.

When the units become credits depends on the house, as [Credits and storage](/systems/tiberium/#credits-and-storage) explains. A computer house in a skirmish or multiplayer game receives the credits as soon as its harvester unloads. Every other house keeps only the units that fit in its free storage. Each stored unit becomes `Value` credits when the house spends it.

The [harvester's patch search](/systems/tiberium/#finding-a-patch) ranks a cell by `Value` multiplied by its growth stage plus one, so a full-grown cell counts twelve times the setting.

[`FillSilos=yes`](/keys/fillsilos/) uses the first Tiberium type's `Value` to decide how much Tiberium each house receives when the scenario starts.
