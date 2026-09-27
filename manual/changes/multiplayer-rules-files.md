---
title: Read multiplayer rules from MPLAYER.INI
category: feature
release: 0.2.0
targets:
- type: format
  id: multiplayer-rules
  effect: added
- type: format
  id: opents-ini
  effect: changed
- type: format
  id: rules-registries
  effect: changed
credit:
- ZivDero
---

Every game that is not a campaign, skirmish included, now reads [`MPLAYER.INI`](/formats/multiplayer-rules/) on top of the rest of the rules, and `MPLAYERFS.INI` as well while Firestorm is enabled. Both files are optional and accept everything `RULES.INI` accepts. They apply after the Firestorm and translated rules and before the scenario, so a map still overrides them.

[`OPENTS.INI`](/formats/opents-ini/) can rename the two files with `MultiplayerRules=` and `MultiplayerRulesExpansion=` under `[Files]`.

Both files count toward the rules checksum that a host compares with each joining player's, so every machine in a game needs the same copies. A deployment that ships neither file keeps the checksum it had before.
