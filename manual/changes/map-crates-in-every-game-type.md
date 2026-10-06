---
title: Keep a map's crates in every game type
category: feature
release: 0.2.0
breaking: true
migration:
- Remove crate overlays from multiplayer maps where you do not want placed crates. Turning off the match's Crates option does not remove them.
targets:
- type: system
  id: crates
  effect: changed
- type: key
  id: Crate
  effect: changed
credit: [ZivDero, Rampastring]
---

Crates a map places in its overlay layer now appear in skirmish and network games; they used to be removed from every game that was not a campaign. Turning the match's Crates option off does not remove them, because that option controls random crates only.
