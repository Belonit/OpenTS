---
key: IsFlammable
summary: Parsed terrain flag that the engine never uses.
no_effect: true
see_also: [TreeFlammability, SpawnsTiberium]
when_omitted:
  kind: value
  value: "no"
---

The flag neither makes a terrain object burn nor stops it burning. A terrain object can catch fire when its type has `Armor=wood` and does not set [`SpawnsTiberium=yes`](/keys/spawnstiberium/). [`TreeFlammability`](/keys/treeflammability/) covers the full conditions and how fire spreads between terrain objects.
