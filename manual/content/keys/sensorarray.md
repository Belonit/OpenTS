---
key: SensorArray
summary: Whether the structure marks the cells around it as sensed, revealing cloaked objects standing there.
see_also: ["system:power", "system:cloaking"]
when_omitted:
  kind: value
  value: "no"
---

A sensor array marks every cell within [`CloakRadiusInCells`](/keys/cloakradiusincells/) of it as sensed for its owner. That house sees cloaked objects and fully faded enemy structures on a sensed cell as shadowy outlines, and can target the cloaked objects. [What sensing changes](/systems/cloaking/#what-sensing-changes) lists the full effect.

The array marks its cells at these times, each only if the array is [operational](/systems/power/#defenses) then:

- when its construction finishes and it first opens;
- when it is captured, for the new owner;
- whenever any house's cloak generator finishes growing its field.

An array that is not operational when it opens therefore marks nothing until a cloak field next finishes growing. On a map without cloak generators it never marks its cells, even after its power returns, unless it is captured while operational.

Coverage is lifted only when the array is taken off the map or captured. Capturing moves the coverage: the old owner stops sensing the cells, and the new owner senses them at once if the array is operational. A cell that another array of the same house also covers stays sensed.

:::caution[Power loss does not lift coverage]
A [cloak generator](/keys/cloakgenerator/)'s field collapses when its base runs short of power, but an array keeps every cell it has marked through a power shortfall, a stun or being switched off. Those conditions matter only to an array that has not marked its cells yet.
:::
