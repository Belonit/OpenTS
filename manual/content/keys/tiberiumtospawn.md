---
key: TiberiumToSpawn
summary: Registration slot of the Tiberium type a Tiberium-spawning TerrainType produces.
see_also: ["system:tiberium", "SpawnsTiberium"]
when_omitted:
  kind: value
  value: "0"
---

The value is a slot number, not a section name: `0` is the first type the `[Tiberiums]` list registers, `1` the second, and so on. It has an effect only when the type sets [`SpawnsTiberium=yes`](/keys/spawnstiberium/). It then decides both the Tiberium type the object's cell counts as holding and the type the object seeds.

:::caution[Name a registered slot]
The engine does not check the value. Use a slot from `0` up to one less than the number of registered types. A higher value, or one below `-1`, makes the engine read outside its list of Tiberium types whenever the cell's Tiberium is used, for example when infantry take Tiberium damage there or the object seeds.

With `-1`, the object's cells count as holding no Tiberium, but the object still seeds the type in slot `0`.
:::
