---
enum_id: ScrollSpeedType
slug: camera-speed
title: Camera speed
summary: Discrete camera-scroll speeds accepted by camera movement actions.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [camera-speed]
source_files: [code/scrspeed.hh, code/tactical.cpp]
values:
  - { constant: SCROLL_SPEED_0, value: 0, input: "0", meaning: "The slowest pan: about 667 frames to arrive." }
  - { constant: SCROLL_SPEED_1, value: 1, input: "1", meaning: "About 334 frames to arrive." }
  - { constant: SCROLL_SPEED_2, value: 2, input: "2", meaning: "About 134 frames to arrive." }
  - { constant: SCROLL_SPEED_3, value: 3, input: "3", meaning: "About 34 frames to arrive." }
  - { constant: SCROLL_SPEED_4, value: 4, input: "4", meaning: "The fastest pan: about 17 frames to arrive." }
---

The speed sets how many frames a scripted pan takes to reach its destination, whatever the distance. The view covers an equal share of the distance each frame, with no easing at either end, so a longer pan moves faster. No rules setting changes the five durations.

:::caution[Use a speed from 0 to 4]
Both the [scripted camera move](/mapping/actions/taction-center-viewpoint/) and the [team script mission](/mapping/missions/tmission-center-viewpoint/) accept any number. A negative speed or one above 4 has no entry in the engine's table of rates, so how long the pan takes, and whether it arrives at all, is unpredictable.
:::
