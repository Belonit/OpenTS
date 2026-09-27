---
enum_id: LightBehaviorType
slug: spotlight-behavior
title: Spotlight behavior
summary: Modes a structure's spotlight beam runs in, from sweeping an arc to standing still and undrawn.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [spotlight-behavior]
source_files: [code/blight.hh, code/blight.cpp, code/building.cpp]
values:
  - { constant: LIGHT_BEHAVIOR_NONE, value: 0, input: "0", meaning: "The beam is held in place and not drawn at all." }
  - { constant: LIGHT_BEHAVIOR_SWEEP, value: 1, input: "1", meaning: "The beam sweeps back and forth across an arc centered on the structure's facing." }
  - { constant: LIGHT_BEHAVIOR_CIRCLE, value: 2, input: "2", meaning: "The beam travels around the structure at a constant rate." }
  - { constant: LIGHT_BEHAVIOR_FOLLOW, value: 3, input: "3", meaning: "The beam follows the nearest non-allied infantry or vehicle in or next to the beam's cell at the moment the mode is set." }
---

[`HasSpotlight`](/keys/hasspotlight/) decides whether a structure has a beam at all, and [`SpotlightRadius`](/keys/spotlightradius/) covers which modes detect intruders.

A structure's beam starts in `Sweep` when the structure is placed. A map's structure entry can give it another mode, and the [Change Light Behavior](/mapping/actions/taction-change-spotlight-behavior/) trigger action can change the mode during play.

`Follow` lasts only while the beam has a target within reach. The beam returns to `Sweep` when the target is [`SpotlightMovementRadius`](/keys/spotlightmovementradius/) or farther from the structure. It also returns to `Sweep`, and forgets the target, when the target is destroyed, cloaks, changes owner or is removed from the map, such as by boarding a transport.

When `Follow` is set with no non-allied infantry or vehicle near the beam, the beam returns to `Sweep` on the next frame. The exception is a beam that has followed a target before and has not forgotten it. That beam follows the same target again while the target is closer to the structure than `SpotlightMovementRadius`.

:::caution[Use only the values 0 to 3]
Any other value, including a negative one, leaves the beam drawn but motionless over one spot. It stays there and detects no intruders until a trigger action sets another mode.
:::
