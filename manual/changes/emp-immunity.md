---
title: Let a type say it is immune to an EM pulse
category: feature
release: 0.2.0
targets:
- type: key
  id: ImmuneToEMP
  effect: added
- type: key
  id: IsCoreDefender
  scope: buildingtype
  effect: changed
- type: key
  id: IsCoreDefender
  scope: unittype
  effect: changed
- type: system
  id: emp-pulse
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring]
---

`ImmuneToEMP=yes` in an object type's section of `rules.ini` protects that object from EM pulses. A pulse does not stun an immune vehicle, landed aircraft or cyborg, crash an immune aircraft that is taking off or landing, power off an immune structure, or destroy an immune limpet mine. An immune object still springs its Paralyzed trigger event.

`IsCoreDefender=yes` on a structure or vehicle used to make it immune whatever the rest of its section said. It now makes `ImmuneToEMP` default to `yes`, so Firestorm's Core Defender stays immune unless its section sets `ImmuneToEMP=no`.

Rampastring is credited for the Vinifera feature this follows.
