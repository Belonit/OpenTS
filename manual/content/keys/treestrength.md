---
key: TreeStrength
summary: Maximum strength a TerrainType takes when its own section sets none.
see_also: [Strength, VeinholeTypeClass]
when_omitted:
  kind: value
  value: "25"
---

A TerrainType whose section sets no [`Strength`](/keys/strength/#scope-aircrafttype), or sets `Strength=-1`, takes this value as its maximum strength. The engine applies it right after reading the type's section. `[General]` is read before the type sections of each rules file, so the fallback uses a `TreeStrength` set in the same file or an earlier one.

The fallback applies only once per type. After a type has taken it, a later rules layer that omits `Strength` leaves the value in place, and a later `TreeStrength` reaches the type only if that layer sets `Strength=-1` again.

:::caution[The fallback needs a section to run in]
A TerrainType named in the rules but given no section of its own is never read, so it keeps a maximum strength of `-1`. [`VeinholeTypeClass`](/keys/veinholetypeclass/) explains what that costs when the missing section is a veinhole monster's.
:::
