---
title: Silos launch the missile of the superweapon that was fired
category: fix
release: 0.2.0
targets:
- type: system
  id: superweapons
  effect: changed
- type: key
  id: NukeSilo
  effect: changed
credit: [ZivDero]
---

A missile silo used to launch the `WeaponType=` of the `[SuperWeaponTypes]` entry at the fixed position for the fired weapon's `Type=`, so a reordered list or two missile superweapons of the same type launched the wrong missile. A silo now launches the `WeaponType=` of the superweapon that was fired, and a `Type=ChemMissile` launch follows that superweapon too. A launch already under way in a game saved by an earlier build keeps the missile it had.
