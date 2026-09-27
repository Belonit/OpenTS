---
title: Let a house act for its own country
category: fix
release: 0.2.0
targets:
- type: key
  id: ActsLike
  effect: changed
credit: [ZivDero, AlexB]
---

Each house now acts as its own country unless its section in the map file sets `ActsLike=`, which names the country whose structures and units the house builds. The default used to come from the first three letters of the country's name: `GDI` acted as GDI, `Nod` as Nod, and any other name as no country. Multiplayer games never read the map's house sections, so a third country's construction yard built nothing and a country named `GDI-Reserve` acted as GDI.

A house of a country with `MultiplayPassive=yes` in its `rules.ini` section now acts as no country, unless `ActsLike=` names one.

`ActsLike=` now also accepts a country's name. A name used to be read as `0`, the first country.

AlexB is credited for the ts-patches patch that first gave every country its own index here.
