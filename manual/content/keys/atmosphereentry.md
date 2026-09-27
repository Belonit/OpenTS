---
key: AtmosphereEntry
summary: The animation drawn high above the map where a drop pod enters the scenario.
see_also: [DropPod, DropPodHeight, DropPodAngle, "system:drop-pods"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
AtmosphereEntry=MYPODRING ; an AnimType registered in [Animations]
```

Each drop pod creates this animation once, at the start of its fall. It appears at the high point where the fall begins, on the frame the passenger is placed there, and plays as many times as its animation type's [`LoopCount`](/keys/loopcount/) sets. [Approach selection](/systems/drop-pods/#approach-selection) covers where that point lies for each of the four approaches. No other part of the game uses the animation.

If the passenger cannot be placed at the start point, the engine tries once more and creates no animation on the second try. A pod placed on that retry falls without the animation.

:::danger[Set an animation before using drop pods]
If `AtmosphereEntry` names no animation, the game crashes when a [Drop Pods superweapon or a drop-pod team](/systems/drop-pods/#entry-paths) places its first passenger.
:::
