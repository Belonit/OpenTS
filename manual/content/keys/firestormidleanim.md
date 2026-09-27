---
key: FirestormIdleAnim
summary: The animation a raised firestorm wall section flickers over itself at random.
see_also: ["system:laser-fences"]
when_omitted:
  kind: value
  value: none
---

`FirestormIdleAnim` flickers at random over raised firestorm wall sections that are not part of a straight run. A section with wall sections only to its north and south, or only to its east and west, never shows it. [`FirestormActiveAnim`](/keys/firestormactiveanim/) uses the same test.

While its house has [raised the wall](/systems/laser-fences/#raising-and-lowering-the-wall), each such section has a one-in-sixteen chance every eighth frame to start the animation, unless its previous one is still playing.

The animation is drawn half-transparent, nearly three cells up and to the left of the section.

:::danger[Set `FirestormIdleAnim` before a wall can be raised]
If the key is missing or empty, the game crashes the first time a raised section starts the animation.
:::
