---
key: IsAnimated
summary: Terrain object that plays through its artwork instead of holding a single frame.
see_also: [AnimationRate, AnimationProbability, SpawnsTiberium]
when_omitted:
  kind: value
  value: "no"
---

The flag has two effects on terrain objects of the type:

- The object starts its animation by chance. On each game frame while the animation is stopped, it starts with the chance set by [`AnimationProbability`](/keys/animationprobability/). The animation runs from the first frame of the artwork at the pace set by [`AnimationRate`](/keys/animationrate/).
- The object always shows its current animation frame. It no longer switches to its damaged frame when its strength drops below 2.

```ini title="rules.ini"
[MYTREE]              ; example blossom tree
IsAnimated=yes
AnimationRate=3
AnimationProbability=.02
SpawnsTiberium=yes
```

:::caution[Only a Tiberium-spawning type stops its animation]
An animated [`SpawnsTiberium=yes`](/keys/spawnstiberium/) object stops when it reaches the middle frame of its shape file, where the shadow frames begin. It returns to its first frame, [seeds Tiberium](/systems/tiberium/#other-sources-of-tiberium) in a neighboring cell, and waits for `AnimationProbability` to start it again.

Any other animated type never stops once it has started. It runs on into the shadow frames and shows its shadow artwork as its body. Past the last frame in the file, it draws nothing.
:::
