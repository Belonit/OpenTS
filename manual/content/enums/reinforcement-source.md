---
enum_id: SourceType
slug: reinforcement-source
title: Reinforcement source
summary: Map-edge origins used when objects cross a scenario's boundary.
representation: token
bindings:
  key_value_types: [sourcetype]
  scripting_parameter_types: []
source_files: [code/source.hh, code/_source.cpp, code/display.cpp, code/reinf.cpp]
values:
  - { constant: SOURCE_NORTH, value: 0, input: "North", meaning: "Enter from the north edge." }
  - { constant: SOURCE_EAST, value: 1, input: "East", meaning: "Enter from the east edge." }
  - { constant: SOURCE_SOUTH, value: 2, input: "South", meaning: "Enter from the south edge." }
  - { constant: SOURCE_WEST, value: 3, input: "West", meaning: "Enter from the west edge." }
  - { constant: SOURCE_AIR, value: 4, input: "Air", meaning: "Names no edge. Reinforcements enter along the north edge." }
---

A house's [`Edge`](/keys/edge/) setting takes one of these values to choose the map edge its reinforcements enter from. That page covers which kinds of reinforcement use it.

Only the four compass values name an edge. With `Edge=Air`, reinforcements enter along the north edge and face the same way as with `Edge=North`. When the team names no waypoint, though, `Air` can pick a different entry cell on that edge than `North` would, so set `North` for north-edge reinforcements.
