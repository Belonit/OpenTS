---
key: AnimationRate
summary: Game frames each frame of an animated terrain object's artwork is held for.
see_also: [IsAnimated, AnimationProbability]
when_omitted:
  kind: value
  value: "0"
  note: A pace of zero, which never advances the artwork.
---

The value is the number of game frames an [`IsAnimated=yes`](/keys/isanimated/) terrain object shows each frame of its artwork. `1` advances the artwork on every game frame, and `15` advances it once a second at 15 frames a second. The object takes the value each time its animation starts, which [`AnimationProbability`](/keys/animationprobability/) decides.

```ini title="rules.ini"
[MYTREE]                 ; example blossom tree
IsAnimated=yes
AnimationRate=3          ; one frame every three game frames, five a second
AnimationProbability=.02
SpawnsTiberium=yes
```

:::caution[Set AnimationRate above 0 on an animated type]
An animated object with `0` stays on the first frame of its artwork, and a [`SpawnsTiberium=yes`](/keys/spawnstiberium/) object never seeds Tiberium.
:::
