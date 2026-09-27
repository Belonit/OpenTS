---
title: Let any yard build for its owner with MultiMCV
category: feature
release: 0.2.0
targets:
- type: key
  id: MultiMCV
  effect: added
- type: system
  id: production
  effect: changed
credit: [ZivDero]
---

A construction yard [acts as](/keys/actslike/) the country of the house that created it, or of the MCV it deployed from, and keeps that country when captured. `MultiMCV=yes` under `[General]` in `rules.ini` lets it also build structures whose `Owner` list does not include that country, both on the sidebar and in the choice of which yard builds. The key and its meaning match Vinifera's, so rules written for Vinifera carry over.
