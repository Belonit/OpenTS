---
key: PreProductionAnimDamaged
summary: The animation the pre-production slot runs while the structure is damaged.
see_also: ["PreProductionAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation PreProductionAnim names.
---

A construction yard starts the pre-production slot with this name when its health is at or below [`ConditionYellow`](/keys/conditionyellow/). An unloading harvester always starts the slot in its healthy form, whatever the structure's health.

Once the slot is running, it follows the structure's other animations between the healthy and damaged forms. [The damaged form](/systems/building-animations/#the-damaged-form) covers when the whole set switches, including the switch back to healthy that a harvester's start causes on a damaged structure.

If only this name is set, the slot runs nothing when a harvester unloads, and nothing when a healthy construction yard starts it.
