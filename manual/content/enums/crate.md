---
enum_id: CrateType
slug: crate
title: Crate result
summary: Random crate outcomes referenced by crate-control settings.
representation: token
bindings:
  key_value_types: [cratetype]
  scripting_parameter_types: []
source_files: [code/crate.hh, code/const.cpp, code/rules.cpp]
values:
  - { constant: CRATE_MONEY, value: 0, input: "Money", meaning: "Award money." }
  - { constant: CRATE_UNIT, value: 1, input: "Unit", meaning: "Create a vehicle." }
  - { constant: CRATE_HEAL_BASE, value: 2, input: "HealBase", meaning: "Restore every object of the collector's house to maximum strength." }
  - { constant: CRATE_CLOAK, value: 3, input: "Cloak", meaning: "Let nearby objects cloak." }
  - { constant: CRATE_EXPLOSION, value: 4, input: "Explosion", meaning: "Damage the collector and scatter explosions around the crate." }
  - { constant: CRATE_NAPALM, value: 5, input: "Napalm", meaning: "Create a napalm blast." }
  - { constant: CRATE_SQUAD, value: 6, input: "Squad", meaning: "Always becomes the Money result." }
  - { constant: CRATE_DARKNESS, value: 7, input: "Darkness", meaning: "Shroud the whole map again for the player of the collector's house. No effect for a computer house." }
  - { constant: CRATE_REVEAL, value: 8, input: "Reveal", meaning: "Reveal the whole map to the player of the collector's house. No effect for a computer house." }
  - { constant: CRATE_ARMOR, value: 9, input: "Armor", meaning: "Improve the armor of nearby objects." }
  - { constant: CRATE_SPEED, value: 10, input: "Speed", meaning: "Improve the speed of nearby objects." }
  - { constant: CRATE_FIREPOWER, value: 11, input: "Firepower", meaning: "Improve the firepower of nearby objects." }
  - { constant: CRATE_ICBM, value: 12, input: "ICBM", meaning: "Grant the collector's house a one-time superweapon, unless it already holds that weapon." }
  - { constant: CRATE_INVULN, value: 13, input: "Invulnerability", meaning: "No effect beyond using up the crate and playing its animation." }
  - { constant: CRATE_VETERAN, value: 14, input: "Veteran", meaning: "Promote nearby objects." }
  - { constant: CRATE_ION_STORM, value: 15, input: "IonStorm", meaning: "No effect beyond using up the crate and playing its animation." }
  - { constant: CRATE_GAS, value: 16, input: "Gas", meaning: "Damage the crate's cell and its neighbors with gas." }
  - { constant: CRATE_TIBERIUM, value: 17, input: "Tiberium", meaning: "Scatter Tiberium around the crate." }
  - { constant: CRATE_POD, value: 18, input: "Pod", meaning: "No effect beyond using up the crate and playing its animation." }
---

These names are the keys of the `[Powerups]` section, which [Crate powerups](/formats/powerups/) covers. The list is fixed, and a mod cannot add a result. [Crates](/systems/crates/) covers how a result is drawn and what each one does.
