---
key: ActiveAnimTwoDamaged
summary: The animation the second active slot runs while the structure is damaged.
see_also: ["ActiveAnimTwo", "ActiveAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation ActiveAnimTwo names.
---

The second active slot runs this animation in place of [`ActiveAnimTwo`](/keys/activeanimtwo/) when the slot is filled while the structure's health is at or below [`ConditionYellow`](/keys/conditionyellow/). A slot that names only `ActiveAnimTwoDamaged` starts only while the structure is damaged.

The structure shows all its attached animations in one form at a time. After each damage or repair step, if its health is on the other side of `ConditionYellow` from the form on show, every animation it is running switches to the matching form. Each one continues from the frame it had reached.

[The damaged form](/systems/building-animations/#the-damaged-form) lists the fills that always use the healthy name, and covers what a damaged-only animation does after a repair.
