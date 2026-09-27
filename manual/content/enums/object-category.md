---
enum_id: CategoryType
slug: object-category
title: Object category
summary: Classification tokens that infantry, vehicle, aircraft and building types can set, read only by the dropship loadout screen.
representation: token
bindings:
  key_value_types: [CategoryType]
  scripting_parameter_types: []
source_files: [code/category.hh, code/category.cpp]
values:
  - { constant: CATEGORY_SOLDIER, value: 0, input: "Soldier", meaning: "Combat soldier." }
  - { constant: CATEGORY_CIVILIAN, value: 1, input: "Civilian", meaning: "Noncombatant civilian." }
  - { constant: CATEGORY_VIP, value: 2, input: "VIP", meaning: "VIP, agent, or commando." }
  - { constant: CATEGORY_RECON, value: 3, input: "Recon", meaning: "Reconnaissance vehicle." }
  - { constant: CATEGORY_AFV, value: 4, input: "AFV", meaning: "Armored fighting vehicle." }
  - { constant: CATEGORY_IFV, value: 5, input: "IFV", meaning: "Infantry fighting vehicle." }
  - { constant: CATEGORY_ARTY, value: 6, input: "LRFS", meaning: "Indirect or long-range fire support." }
  - { constant: CATEGORY_SUPPORT, value: 7, input: "Support", meaning: "Miscellaneous support vehicle." }
  - { constant: CATEGORY_TRANSPORT, value: 8, input: "Transport", meaning: "Ground transport vehicle." }
  - { constant: CATEGORY_AIRSUPPORT, value: 9, input: "AirPower", meaning: "Air combat support." }
  - { constant: CATEGORY_AIRTRANSPORT, value: 10, input: "AirLift", meaning: "Air transport." }
---

Only `Civilian` has an effect. An InfantryType with `Category=Civilian` is left off the dropship loadout screen when the scenario lists no [`AllowableUnits`](/keys/allowableunits/). [`Category`](/keys/category/) gives the details. The other ten categories change nothing.

Each category has a short and a long spelling, and `Category=` accepts either in any letter case. For example, `recon vehicle` and `Recon` name the same category. `Soldier` and `Civilian` are spelled the same both ways; the table pairs the other nine.

| Short token | Long description |
| --- | --- |
| `VIP` | `VIP/Agent` |
| `Recon` | `Recon Vehicle` |
| `AFV` | `Armored Fighting Vehicle` |
| `IFV` | `Infantry Fighting Vehicle` |
| `LRFS` | `Indirect Fire Support` |
| `Support` | `Misc. Support Vehicle` |
| `Transport` | `Transport Vehicle` |
| `AirPower` | `Air Combat Support` |
| `AirLift` | `Air Transport` |
