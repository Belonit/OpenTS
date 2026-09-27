---
key: TrailerAnim
scope: animtype
label: Animation trail
see_also: ["TrailerSeperation", "Bouncer", "IsMeteor"]
when_omitted:
  kind: value
  value: none
---

While the animation exists, it drops an animation of the named type at its position on every game frame whose number is a multiple of [`TrailerSeperation`](/keys/trailerseperation/). The frame number is the game's, not the animation's, so every animation of the type drops its trail on the same frames. Each trail animation appears one frame after it is dropped.

Any animation can leave a trail, not only a thrown one. An explosion or a smoke column that names a trail animation leaves one just as a meteor does.

A name that matches no animation type creates a new type of that name. The new type reads its settings from the `art.ini` section of that name. Without that section it has no artwork, and the trail shows nothing.

Always set [`TrailerSeperation`](/keys/trailerseperation/) with a trail; its page describes the crash that follows otherwise.
