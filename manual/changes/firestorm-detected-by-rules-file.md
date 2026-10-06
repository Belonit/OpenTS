---
title: Detect Firestorm from its rules file alone
category: fix
release: 0.2.0
targets:
- type: format
  id: rules-registries
  effect: changed
breaking: true
migration:
- 'If the deployment should run without Firestorm, remove or rename its expansion rules file: `FIRESTRM.INI`, or the file selected by `[Files] RulesExpansion` in `OPENTS.INI`. Enabling Firestorm requires `SOUNDS01.MIX`.'
credit:
- ZivDero
---

Firestorm now counts as installed whenever the game finds the file that `RulesExpansion=` names under `[Files]` in `OPENTS.INI`, `FIRESTRM.INI` by default. The file may be loose in any folder the game searches, or inside `PATCH.MIX`, `PCACHE.MIX`, or an `EXPANDnn.MIX` or `ECACHEnn.MIX` archive.

`EXPAND01.MIX` used to be required as well. A deployment that kept the expansion's content in other archives, or under other names, played as the base game however complete it was. The game did not read the Firestorm rules, did not offer the Firestorm game type, and did not load the expansion's sounds or side archives.
