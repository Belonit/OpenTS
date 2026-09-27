---
key: FinalDamageState
summary: The last animation state at which a flame particle still burns what it drifts over.
see_also: ["EndStateAI", "MaxDC", "Damage", "Normalized"]
when_omitted:
  kind: inherited
  note: The value EndStateAI holds in the same section.
---

A [`Fire`](/keys/behaveslike/#scope-particletype) particle applies its [`Damage`](/keys/damage/#scope-particletype) only while its animation state is at or below this value. States only climb, so once a flame passes this state it does no more damage. A value at or above [`EndStateAI`](/keys/endstateai/) keeps the flame damaging for its whole life. A negative value stops it from ever damaging. The value is held in one signed byte, so `128` to `255` wrap to negative values and also stop all damage, and `256` wraps to `0`. Other behaviors ignore the setting.

A flame with [`Normalized=yes`](/keys/normalized/#scope-particletype) also uses this value to pace its animation. When it is created, it divides its expected flight time to its target point by this value plus one, and advances one state per share. It therefore passes this state at about the time it reaches its target point.

:::danger[Keep this value from 0 to 127 on a normalized flame]
With `Normalized=yes`, a value of `-1`, or `255`, which wraps to it, gives the flame an interval of 0 frames between states. About half the flames of the type then crash the game on their first frame, as [`StateAIAdvance=0`](/keys/stateaiadvance/) does.
:::

A later rules file that opens the section without this key sets it to the `EndStateAI` in force after that file. A layer that changes only `EndStateAI` therefore moves the damage limit with it. A layer that sets neither key discards a shorter damage limit set earlier and returns it to the end state.
