---
enum_id: MeteorShowerType
slug: meteor-shower
title: Meteor shower intensity
summary: Fixed intensity presets used by meteor-shower trigger actions.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [meteor-shower]
source_files: [code/meteor.hh, code/taction.cpp]
values:
  - { constant: SHOWER_DRIZZLE, value: 0, input: "0", meaning: "Light drizzle preset." }
  - { constant: SHOWER_SHOWER, value: 1, input: "1", meaning: "Standard shower preset." }
  - { constant: SHOWER_DOWNPOUR, value: 2, input: "2", meaning: "Heavy downpour preset." }
  - { constant: SHOWER_ARMAGEDDON, value: 3, input: "3", meaning: "Maximum Armageddon preset." }
---

The presets differ only in how many meteors fall and how widely they scatter around the waypoint. The base counts are one for a drizzle, five for a shower, nine for a downpour and fifteen for an Armageddon, and every preset adds zero to two more at random. Along each map axis, a meteor lands up to about a quarter of a cell per meteor in the shower from the waypoint. A drizzle therefore stays within about a cell of the waypoint on each axis, and an Armageddon spreads over a square about nine cells across.

Each meteor is a `METLARGE` or `METSMALL` animation, picked at random, and that animation decides what the meteor does where it lands. A higher preset therefore covers more ground with more meteors, but no meteor strikes harder.

:::caution[Keep the intensity from 0 to 3]
Only the four values in the table have a meteor count. Any other value reads its count from outside the table; [Meteor Shower At](/mapping/actions/taction-meteor-shower/) describes the result.
:::
