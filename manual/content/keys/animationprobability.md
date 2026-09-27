---
key: AnimationProbability
summary: Chance each game frame that a stopped terrain animation starts over.
see_also: [IsAnimated, AnimationRate]
when_omitted:
  kind: value
  value: "0"
  note: No roll ever succeeds, so an animation that has stopped never restarts.
---

The chance applies to an [`IsAnimated=yes`](/keys/isanimated/) terrain object whose animation is stopped. On each game frame, such an object starts its animation with this probability, written as a fraction from `0` to `1`. `.02` gives one chance in fifty per frame, so the animation starts on average every fifty frames, a little over three seconds at 15 frames a second. A percentage also works: `2%` is the same as `.02`.

```ini title="rules.ini"
[MYTREE]                 ; example blossom tree
IsAnimated=yes
AnimationRate=3
AnimationProbability=.02 ; one restart every 50 frames on average
SpawnsTiberium=yes
```

How often the chance comes up depends on the type:

- Every animated object begins stopped, showing the first frame of its artwork.
- A [`SpawnsTiberium=yes`](/keys/spawnstiberium/) object stops again each time it seeds Tiberium, so this chance sets how often it seeds.
- Any other animated object never stops once it has started, so this chance only decides when it first starts.

`1` or more starts a stopped animation on the next frame. `0` or less never starts it, so a stopped object keeps showing the first frame of its artwork.
