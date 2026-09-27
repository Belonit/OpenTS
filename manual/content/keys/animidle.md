---
key: AnimIdle
summary: The first frame, frame count and step delay of a structure's resting animation.
see_also: ["AnimActive", "AnimAux1", "AnimAux2", "ConditionYellow"]
when_omitted:
  kind: value
  value: "0,1,0"
---

`AnimIdle` is the frame sequence a structure's artwork plays whenever no other sequence has taken over. The value is three whole numbers:

1. the first frame of the structure's artwork to draw;
2. how many frames the sequence runs;
3. how many game frames each frame is held.

A delay of `0` holds the sequence on its first frame. A sequence that runs past its last frame starts again at the first.

```ini title="art.ini"
[MYSILO] ; example missile silo, drawn from its own Image ID
AnimIdle=0,1,0   ; one frame, held
AnimActive=2,5,4 ; the door opening
```

## Game speed

The idle delay is adjusted for the selected game speed each time the sequence starts again at its first frame, and each time a structure returns to it from another sequence. The [`AnimActive`](/keys/animactive/), [`AnimAux1`](/keys/animaux1/) and [`AnimAux2`](/keys/animaux2/) delays are used as written.

A structure that starts out in the idle sequence, such as one the scenario places, runs its first idle cycle at the written delay unless its art entry sets [`Normalized=yes`](/keys/normalized/). The adjustment applies from the first time the sequence starts again. A structure a player builds reaches the idle sequence from its construction sequence, so its idle delay is adjusted from the start.

## Damaged frames

At or below [`ConditionYellow`](/keys/conditionyellow/), a structure draws its damaged artwork. The four sequences together decide where those frames are:

- A damaged structure running `AnimIdle` draws the frame one after the healthy frame.
- A damaged structure running any of the other three sequences adds an offset to the healthy frame. The offset is the largest first frame plus frame count among the four sequences. In the example above, `AnimIdle` ends at 1 and `AnimActive` at 7, so the damaged door-opening frames are 9 to 13.

A damaged idle sequence of more than one frame overlaps the healthy one. With `AnimIdle=0,2`, the damaged idle frames are 1 and 2, so frame 1 is drawn both healthy and damaged.

:::caution[Write all three numbers]
Only the numbers the value supplies are stored. `AnimIdle=5` sets the first frame and leaves the frame count and delay unchanged, which for a type that sets them nowhere else is one frame with no delay.
:::
