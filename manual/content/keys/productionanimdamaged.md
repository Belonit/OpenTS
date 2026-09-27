---
key: ProductionAnimDamaged
summary: The damaged form of a structure's production animation.
see_also: ["ProductionAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation ProductionAnim names.
---

`ProductionAnimDamaged=` names the production slot's animation for a structure whose health is at or below [`ConditionYellow`](/keys/conditionyellow/).

When the slot starts, only a [`ConstructionYard=yes`](/keys/constructionyard/) structure chooses this name, and only if its health is at or below `ConditionYellow` at that moment. Every other structure starts the slot with the [`ProductionAnim`](/keys/productionanim/) name, whatever its health.

Once the slot is running, any structure switches it to this name at the next hit or repair step that finds its health at or below `ConditionYellow`, or earlier if another animation on the structure starts in its damaged form.

A type that sets this key without `ProductionAnim` runs the slot only on a construction yard that is damaged when a structure it placed finishes. Other structures never run it.
