---
key: GateStages
summary: The number of door frames a gate animates through.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "9"
---

The value is the number of undamaged door frames in the gate's artwork. A closed gate shows frame `0` and a fully open one shows frame `GateStages - 1`. While the door moves, the frame drawn follows how far it has traveled.

```ini title="art.ini"
[MYGATE] ; example gate, drawn from its own Image ID
GateStages=9
```

A gate at or below [`ConditionYellow`](/keys/conditionyellow/) draws its door from a second block of frames that starts at `GateStages` plus one, so the art needs both blocks. With `GateStages=9`, the undamaged door uses frames `0` through `8`, the damaged door uses frames `10` through `18`, and frame `9` is never drawn as a door frame. The damaged block needs no [`DamagedDoor=yes`](/keys/damageddoor/).

While the door is open or moving, the frames before `GateStages / 2`, rounded down, are depth-sorted as an upright wall, and the later frames as if lying flat on the ground. The damaged block follows the same split. With `GateStages=9`, frames `0` through `3` are upright and frames `4` through `8` lie flat.

A [`Gate=yes`](/keys/gate/) type's buildup animation plays frames `GateStages` down to `0` of its buildup art, in that order. [Buildup](/systems/production/#buildup) covers the animation's timing.
