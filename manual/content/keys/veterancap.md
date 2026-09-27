---
key: VeteranCap
summary: The highest experience total a credited kill may leave an object at.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

After each [credited kill](/systems/veterancy/#earning-experience) adds its experience, the total is limited to this value. Veteran rank starts at `1` experience and elite at `2`, so the value sets the highest rank that kills can reach:

| `VeteranCap` | Highest rank from kills |
| --- | --- |
| Below `0` | Below rookie. The first credited kill drops the object below rookie. |
| `0` up to but not including `1` | Rookie. Kills never promote. |
| `1` up to but not including `2` | Veteran |
| `2` and above | Elite |

Crates, armories, triggers and the other sources in [Promotion without kills](/systems/veterancy/#promotion-without-kills) set the rank directly and ignore this value.

:::caution[Set VeteranCap to 2 for elite rank from kills]
With `VeteranCap` unset, kills alone never promote an object past veteran.
:::

:::caution[A ceiling below an object's rank demotes it]
The limit applies to the running total, not to the experience a kill adds. An object already above it drops to it on its next credited kill. Under the default, an elite [`Trainable=yes`](/keys/trainable/) object that scores a kill drops to veteran and loses its elite weapon and [`EliteAbilities`](/keys/eliteabilities/).
:::
