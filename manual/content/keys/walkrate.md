---
key: WalkRate
summary: The number of game frames between steps of a moving object's animation count.
when_omitted:
  kind: value
  value: "1"
---

A moving vehicle, infantryman or aircraft keeps a count of animation steps. The count advances by one on each game frame whose number is a multiple of `WalkRate`, as long as the object's locomotor reports that it is moving. A structure keeps no count.

Only vehicle artwork uses the count; infantry and aircraft animation does not depend on it:

- A vehicle drawn from shape art shows its next walk frame at each step.
- A vehicle drawn from a voxel model shows the next frame of its motion animation every second step, so each frame holds for twice `WalkRate` game frames.
- The harvesting animation takes its phase from the count.

A larger value slows the walk cycle. The stock Titan's `WalkRate=2` changes its walk frame every second game frame, and the Core Defender's `WalkRate=4` every fourth. The test uses the game's frame number, so moving objects with the same value step on the same frames.

:::danger[Keep WalkRate at 1 or above]
`WalkRate=0` crashes the game as soon as an object of that type starts to move, whether or not its artwork uses the count.
:::
