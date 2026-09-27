---
enum_id: ArmorType
slug: armor
title: Armor
summary: Armor classes used when warheads calculate their effectiveness against a target.
representation: token
bindings:
  key_value_types: [ArmorType]
  scripting_parameter_types: []
source_files: [code/armor.hh, code/const.cpp, code/weapon.cpp]
values:
  - { constant: ARMOR_NONE, value: 0, input: "none", meaning: "Unarmored target class." }
  - { constant: ARMOR_WOOD, value: 1, input: "wood", meaning: "Wood and other light structural armor." }
  - { constant: ARMOR_ALUMINUM, value: 2, input: "light", meaning: "Light vehicle armor." }
  - { constant: ARMOR_STEEL, value: 3, input: "heavy", meaning: "Heavy vehicle armor." }
  - { constant: ARMOR_CONCRETE, value: 4, input: "concrete", meaning: "Concrete building armor." }
---

Armor names are matched without regard to case. A mod cannot add a sixth class. How much damage a warhead deals to each class is set by that warhead's [`Verses`](/keys/verses/) list, which has one entry per class in the order shown above.

The `wood` class is also tested outside `Verses`. A [`Wood=yes`](/keys/wood/) warhead can reduce a wall overlay whose class is `wood`, and only a terrain object whose class is `wood` can catch fire. [`Armor`](/keys/armor/#scope-aircrafttype) covers both.

:::caution[Check the spelling of armor names]
A misspelled armor name is not rejected. It reads as `none`, an ordinary class, so every warhead scales its damage to the type by the first entry of that warhead's `Verses` list.
:::
