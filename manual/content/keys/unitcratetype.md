---
key: UnitCrateType
summary: The single vehicle type every unit crate delivers.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: none
---

With a type named here, every unit crate delivers that vehicle type, or pays money if the vehicle cannot be placed. The type is delivered even if it does not set [`CrateGoodie=yes`](/keys/crategoodie/) and even if the collector's country may not own it.

With `UnitCrateType=none`, the unit crate chooses a vehicle as [Money and free units](/systems/crates/#money-and-free-units) describes: a free MCV or harvester when the collector's house needs one, and otherwise a random `CrateGoodie=yes` type the collector's country may own.

:::caution[Naming a type replaces the free MCV and harvester]
A house that has lost its base, or that owns a refinery but no harvester, receives the named type instead of the MCV or harvester it would otherwise get. Leave the setting at `none` to keep both.
:::
