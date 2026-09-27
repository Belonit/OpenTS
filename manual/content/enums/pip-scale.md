---
enum_id: PipScaleType
slug: pip-scale
title: Pip scale
summary: Quantities that a selected object's pip row can represent.
representation: token
bindings:
  key_value_types: [PipScaleType]
  scripting_parameter_types: []
source_files: [code/pip.hh, code/ccini.cpp]
values:
  - { constant: PIPSCALE_AMMO, value: 1, input: "Ammo", meaning: "Remaining ammunition." }
  - { constant: PIPSCALE_TIBERIUM, value: 2, input: "Tiberium", meaning: "Stored Tiberium. A Weeder=yes structure counts the weeds its house holds instead. Infantry and aircraft draw no pips." }
  - { constant: PIPSCALE_PASSENGERS, value: 3, input: "Passengers", meaning: "Passenger space in use." }
  - { constant: PIPSCALE_POWER, value: 4, input: "Power", meaning: "Nothing. The row has a length, but no pips are drawn in it." }
  - { constant: PIPSCALE_CHARGE, value: 5, input: "Charge", meaning: "A vehicle's stored charge against its MaxCharge. Any other kind of object shows the row empty." }
---

A **pip** is one of the small markers drawn in a row beneath a selected object. [`PipScale`](/keys/pipscale/) chooses the quantity that row counts, in any letter case, and that page gives each scale's row length and how the row fills. The [pip colors](/reference/enums/pip-color/) are a separate list.

A type that can carry passengers shows its passengers whatever its scale. The scale then sets only the length of the row.
