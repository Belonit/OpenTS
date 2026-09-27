---
key: Smoke
summary: Parsed animation that the engine never creates.
no_effect: true
see_also: [SmallFire, LargeFire, DropPodPuff]
when_omitted:
  kind: value
  value: none
---

The value is still looked up when the rules are read. A name not already registered as an animation is registered as a new one at that point. The shipped rules assign `xxxx`, which is not a real animation. This is harmless because the game never creates the animation.
