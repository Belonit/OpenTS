---
key: FirestormActiveAnim
summary: The animation a raised firestorm wall section runs while it is not part of a straight run.
see_also: ["system:laser-fences"]
when_omitted:
  kind: value
  value: none
---

`FirestormActiveAnim` plays over a raised firestorm wall section that is not part of a straight run. A section with wall sections only to its north and south, or only to its east and west, does not show it. All other sections do: corners, tees, crossings, ends and isolated sections. The animation is drawn half a cell up and to the left of the section, and starts fogged if the section is fogged.

A section checks whether it should show the animation at these moments:

- its house [raises or lowers the wall](/systems/laser-fences/#raising-and-lowering-the-wall);
- the section is placed;
- a section beside it is placed or removed.

The animation plays its type's [`LoopCount`](/keys/loopcount/), once if the type sets none. Once it ends, it starts again only at the section's next check.

Each check removes an animation that is already playing, whatever the section's shape. While the wall is up, placing or removing a section beside a lit section therefore turns its animation off. The next such change turns it back on if the section still qualifies.

:::danger[Set `FirestormActiveAnim` before a wall can be raised]
If the key is missing or empty, the game crashes the first time a raised section needs the animation.
:::
