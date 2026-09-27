---
key: ActiveAnimDamaged
summary: The animation the first active slot runs while the structure is damaged.
see_also: ["ActiveAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation ActiveAnim names.
---

`ActiveAnimDamaged=` names the animation that active slot one runs in place of [`ActiveAnim`](/keys/activeanim/) while the structure's health is at or below [`ConditionYellow`](/keys/conditionyellow/). Each time the structure takes damage or is repaired, its running animations switch to the form that matches its health.

If only `ActiveAnimDamaged=` is set, the slot starts only while the structure is damaged, and repairing the structure leaves that animation running. [The damaged form](/systems/building-animations/#the-damaged-form) lists the starts that always use the healthy form, whatever the structure's health.
