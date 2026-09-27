---
key: PreProductionAnim
summary: The animation a structure runs while work is being set up on it.
see_also: ["PreProductionAnimDamaged", "PreProductionAnimX", "PreProductionAnimY", "PreProductionAnimYSort", "PreProductionAnimZAdjust", "ProductionAnim", "ActiveAnim", "system:production"]
when_omitted:
  kind: value
  value: ""
---

The slot runs an animation registered in `[Animations]`, on the terms [Building animations](/systems/building-animations/) covers. Two kinds of structure use it. On a construction yard it is the lead-in that [`ProductionAnim`](/keys/productionanim/) replaces. On a refinery it runs alongside the production slot, and neither stops the other.

- **Construction yard.** A [`ConstructionYard=yes`](/keys/constructionyard/) structure starts the slot when a newly placed structure reports to it that construction has begun. The yard picks the healthy or damaged name from its own health at that moment. The slot stops if contact with that structure drops. When the structure reports its buildup finished, the slot stops and the production slot starts.
- **Refinery.** A [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle starts the slot on the structure one cell west of it as it begins to unload, always in the healthy form. At a refinery's dock, that structure is normally the refinery itself. No refinery event stops the slot; only selling or destroying the structure ends it. An animation that plays to its end leaves the slot empty until the next harvester unloads; a looping one runs for the rest of the structure's life.

:::caution[The harvester starts the slot on whatever stands west of it]
The harvester starts the pre-production slot of the structure one cell west of its own cell, whatever kind of structure that is. Only the later start of the production slot checks for [`Refinery=yes`](/keys/refinery/).
:::

The two names come from the structure's `[<Image ID>]` art entry. The offset and the two draw-order biases come from the entry named after the BuildingType itself, and are read only when the slot has a name. [Where the settings are read](/keys/productionanim/#where-the-settings-are-read) covers that split. The slot has no power flags.
