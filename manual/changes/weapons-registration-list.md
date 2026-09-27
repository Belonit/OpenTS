---
title: Declare weapons in the rules
category: feature
release: 0.2.0
targets:
- type: format
  id: rules-registries
  effect: changed
credit: [ZivDero, CCHyper]
---

A `[Weapons]` list in a rules file, such as `rules.ini` or `firestrm.ini`, now registers each weapon it names, and every listed weapon reads its section even when no other key names it. Before, a weapon that only the engine or a projectile's `AirburstWeapon=` names read its section only if an object type also named it as a weapon. Without such an object type, the [Mobile EM-Pulse](/systems/emp-pulse/#mobile-emp-vehicle) vehicle's pulse (`MobileEMPulseWeapon`) fired nothing, and the Multi-Missile crashed the game when its `MultiCluster` burst.

The [Do Explosion At](/mapping/actions/taction-do-explosion/) trigger action picks its weapon by number. Weapons in the `rules.ini` `[Weapons]` list now take the first numbers, in list order, ahead of any weapon the list leaves out. Before, every weapon was numbered in the order other keys first named it. When a rules file has a `[Weapons]` list, a map written for the old numbering can detonate a different weapon.
