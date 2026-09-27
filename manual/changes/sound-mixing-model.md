---
title: Place sound effects in the view
category: feature
release: 0.2.0
targets:
- type: format
  id: sound-ini
  effect: changed
- type: system
  id: sound-effects
  effect: added
credit: [ZivDero]
---

A sound played at a place on the map is now panned left or right by where that place is in the view. Outside the view it fades with its distance from the view's edge, vertical distance counting double. It falls silent at the sound's `Range=` in `SOUND.INI`, measured in cells, unless its `Type=` includes `GLOBAL`, which stops the fade at its `MinVolume=`. A `Type=LOCAL` sound measures that distance from the center of the view instead. Volume and pan follow the view while the sound plays, so scrolling away from a sound now quiets it; it used to stay as loud as it started.

Up to sixteen sound effects play at once by default. When all are playing, a new sound replaces the lowest-priority one only if the new sound has a higher `Priority=`, or the same priority and a clearly louder volume; otherwise the new sound does not play.
