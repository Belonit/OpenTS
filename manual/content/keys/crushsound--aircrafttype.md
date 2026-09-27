---
key: CrushSound
scope: aircrafttype
label: Crushed sound
see_also: ["Crushable"]
when_omitted:
  kind: value
  value: none
---

The sound plays when a crusher runs over an object or overlay of this type. It is taken from the type being crushed, not from the crusher, and plays at the crusher's position. The value names a sound ID registered in [SOUND.INI](/formats/sound-ini/).

A crushed object and a destroyed wall overlay play this sound as they are removed. A crushable overlay that is not a wall survives, but plays the sound each time a crusher drives onto it. A type that names no sound is crushed in silence.

The sound is used only for a [`Crushable=yes`](/keys/crushable/#scope-aircrafttype) type, since nothing else can be crushed.
