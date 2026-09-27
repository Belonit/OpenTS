---
title: Offer a building only when a yard can produce it
category: fix
release: 0.2.0
targets:
- type: system
  id: production
  effect: changed
credit: [ZivDero, AlexB]
---

A structure with several countries in its `Owner=` list used to appear on the sidebar even when none of the house's construction yards acted for one of them, and then could not be built. The yard test now applies to every structure: the sidebar offers one only when the house has a construction yard acting for a country in its `Owner=` list. `MultiMCV=yes` under `[General]` in `rules.ini` removes the test.

AlexB is credited for the ts-patches patch that first ran the yard test for every structure.
