---
title: Re-check buildability when the sidebar recalculates
category: feature
release: 0.2.0
targets:
- type: key
  id: RecheckPrerequisites
  effect: added
- type: system
  id: sidebar
  effect: changed
credit: [ZivDero]
---

`RecheckPrerequisites=yes` in `[General]` of `rules.ini` removes a cameo from the sidebar when the player stops meeting its tech level, prerequisites or, for a structure, ownership rules. This happens, for example, when a prerequisite structure is destroyed. The item's production is canceled: the item being built, every queued copy, and a structure waiting to be placed. Without the key, losing a prerequisite leaves a cameo on the sidebar.
