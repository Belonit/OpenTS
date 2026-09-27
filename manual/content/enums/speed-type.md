---
enum_id: SpeedType
slug: speed-type
title: Locomotion speed type
summary: Movement-table classes used to select terrain speed behavior.
representation: token
bindings:
  key_value_types: [SpeedType]
  scripting_parameter_types: []
source_files: [code/speed.hh, code/const.cpp]
values:
  - { constant: SPEED_FOOT, value: 0, input: "Foot", meaning: "Bipedal foot movement." }
  - { constant: SPEED_TRACK, value: 1, input: "Track", meaning: "Tracked vehicle movement." }
  - { constant: SPEED_WHEEL, value: 2, input: "Wheel", meaning: "Wheeled vehicle movement." }
  - { constant: SPEED_HOVER, value: 3, input: "Hover", meaning: "Hover movement." }
  - { constant: SPEED_WINGED, value: 4, input: "Winged", meaning: "Aircraft movement." }
  - { constant: SPEED_FLOAT, value: 5, input: "Float", meaning: "Watercraft movement." }
  - { constant: SPEED_AMPHIBIOUS, value: 6, input: "Amphibious", meaning: "Amphibious movement." }
  - { constant: SPEED_CREEP, value: 7, input: "Creep", meaning: "Creeping movement." }
---

A speed type picks the column of the [terrain table](/systems/movement-and-terrain/#the-terrain-table) that an object reads. The table is one `rules.ini` section per [land type](/reference/enums/land-type/), such as `[Clear]`, `[Road]` or `[Water]`. Each section holds one entry per speed type, named by the tokens below, beside its [`Buildable`](/keys/buildable/) setting. The terrain table section explains what each entry does.

Only a vehicle's section accepts [`SpeedType=`](/keys/speedtype/). Every infantry type uses `Foot` and every aircraft type uses `Winged`. A structure uses `Float` when it sets [`WaterBound=yes`](/keys/waterbound/#scope-buildingtype) and has no speed type otherwise. The speed type does not choose how the object moves; [`Locomotor`](/keys/locomotor/) sets that separately.
