---
key: Parachute
summary: The canopy drawn above a paradropped passenger on the way down.
see_also: [BombParachute, ChuteSound, "system:drop-pods"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
Parachute=MYCHUTE ; an AnimType registered in [Animations]
```

An aircraft carrying passengers drops one of them each time it would fire its weapon. The passenger appears at the aircraft's position and falls, with this animation attached above it as a canopy until it lands. If the ground below will not take the passenger, it goes back into the hold and no canopy is created.

Every paradropped passenger uses this canopy. [`BombParachute`](/keys/bombparachute/) is never used.

The passenger falls at the slow parachute rate only while the animation lasts. Give it a [`LoopCount=`](/keys/loopcount/) long enough to play until landing; if it ends early, the rest of the fall is faster. The landing and the mission the passenger is given do not depend on the animation.

:::danger[Name a parachute animation]
The canopy is created without checking that one was named. With the key unset, the game crashes the first time an aircraft drops a passenger.
:::
