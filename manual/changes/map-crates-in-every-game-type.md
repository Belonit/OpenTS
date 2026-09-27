---
title: Keep a map's crates in every game type
category: feature
release: 0.2.0
breaking: true
migration:
- Remove the crate overlay from a multiplayer map that should not hand one out. A crate the map draws is now placed in every game type, and the match's Crates option does not remove it.
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
