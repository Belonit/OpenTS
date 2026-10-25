---
title: Apply air-speed bias and veteran speed to aircraft
category: fix
release: 0.2.0
targets:
- type: key
  id: Airspeed
  scope: difficulty-settings
  effect: changed
- type: key
  id: Airspeed
  scope: housetype
  effect: changed
- type: key
  id: VeteranSpeed
  effect: changed
- type: system
  id: movement-and-terrain
  effect: changed
- type: system
  id: difficulty
  effect: changed
- type: system
  id: veterancy
  effect: changed
credit:
- JoyfulShush
---

`Airspeed=` now scales the top speed of a house's aircraft on the flying locomotor; a value above 1 makes them fly faster. It is set in `rules.ini`, in `[Easy]`, `[Normal]` and `[Difficult]`, and in a country's section outside a campaign. [`GameSpeedBias`](/keys/gamespeedbias/) scales that figure too, and aircraft previously flew at their type's [`Speed=`](/keys/speed/#scope-aircrafttype) alone.

An aircraft whose type lists the `FASTER` ability in `VeteranAbilities=` or `EliteAbilities=` now gains the veteran speed increase once it is promoted to the rank whose list names it. [`VeteranSpeed=`](/keys/veteranspeed/) in `[General]` of `rules.ini` sets the size of the increase; the default doubles a qualifying aircraft's top speed.
