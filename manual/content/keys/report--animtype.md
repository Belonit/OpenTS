---
key: Report
scope: animtype
label: Animation sound
see_also: ["StartSound", "ExpireSound", "BounceSound"]
when_omitted:
  kind: value
  value: none
---

`Report=` names the sound the animation plays at its position when it starts. An animation created with a delay starts, and plays the sound, when the delay runs out.

The sound plays again each time the animation starts over:

- after each pause set by [`RandomLoopDelay`](/keys/randomloopdelay/);
- when the animation changes type through [`Next`](/keys/next/), which plays the new type's sound.

This is the only sound an animation plays when it starts. [`StartSound`](/keys/startsound/#scope-animtype) has no effect on it.

Animations placed by the [Play Anim At](/mapping/actions/taction-play-anim/) and [Drop Zone Flare](/mapping/actions/taction-dz/) trigger actions play this sound when they appear. After that they are silent, so they play no sound after a pause or after changing type through `Next`.

A value that names no registered sound is ignored, and the type keeps the sound it had.
