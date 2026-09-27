---
key: CloakGenerator
summary: Whether the structure projects a cloaking field over the cells around it.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "no"
---

A `CloakGenerator=yes` structure hides its own house's vehicles, infantry, aircraft and structures that stand in its field, unless something on the [list of refusals](/systems/cloaking/#starting-a-cloak) applies. Allied objects in the field stay visible. [`CloakRadiusInCells`](/keys/cloakradiusincells/) sets how far the field reaches.

The field is up while the structure is [operational](/systems/power/#defenses). It grows outward by one cell of radius per game frame, and it collapses ring by ring when the structure is switched off, stunned, or stops being operational through a power shortfall. Except right after a capture, a `Powered=yes` generator also waits for its house to have full power before it raises or regrows its field. A generator whose type stays operational through a shortfall, such as one at `Powered=no`, keeps its field.

Destroying, selling or capturing the generator removes the whole field at once. A captured generator raises a new field for its new owner at once if it is operational, even while the new owner is short of power.

[Cloaking fields](/systems/cloaking/#cloaking-fields) covers what overlapping fields do to each other, the refreshes that follow a change, and the square edge that can cut a field short.
