---
key: EndStateAI
summary: The animation state that ends a particle's sequence.
see_also: ["StartStateAI", "StateAIAdvance", "DeleteOnStateLimit", "FinalDamageState"]
when_omitted:
  kind: value
  value: "0"
---

For most behaviors, a particle's animation state is the frame of its artwork that it shows. The state starts at [`StartStateAI`](/keys/startstateai/) and advances one step at a time at the pace [`StateAIAdvance`](/keys/stateaiadvance/) sets. What happens at this state depends on the particle's [behavior](/keys/behaveslike/#scope-particletype):

- A `Gas`, `WeakGas` or `Web` particle advances until its state equals this value. It is then removed if [`DeleteOnStateLimit`](/keys/deleteonstatelimit/) is set, and otherwise restarts at state 0.
- A `Smoke` or `Fire` particle advances only while its state is below this value. It stops here and shows this frame for the rest of its life, unless `DeleteOnStateLimit` removes it on arrival.
- `Spark` and `Railgun` particles have no animation states and ignore the setting.

With the key omitted, the end is state 0, where a `Gas`, `WeakGas` or `Web` particle starts by default. With `DeleteOnStateLimit=yes`, most such particles are removed on their first frame.

## Flame artwork banks

A `Fire` particle's artwork holds four banks of frames, one for each pair of opposite directions. This value is also the number of frames in each bank. The frame drawn is the current state plus an offset set by the direction the flame was fired in, as seen on screen:

| Direction | Offset |
| --- | --- |
| North or south | none |
| Northeast or southwest | one times this value |
| East or west | two times this value |
| Southeast or northwest | three times this value |

A flame's artwork therefore needs four times this many frames. It needs one more if the flame can hold its final state, which it does when `DeleteOnStateLimit` is off.

## Out-of-range values

The state is held in one signed byte, so a value above 127 wraps to a negative number. A `Smoke` or `Fire` particle then never advances. A `Gas`, `WeakGas` or `Web` particle still reaches the end, after as many advances from state 0 as the value written.
