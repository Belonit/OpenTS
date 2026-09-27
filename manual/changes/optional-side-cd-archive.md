---
title: Start a campaign without its side CD archive
category: fix
release: 0.2.0
targets:
- type: format
  id: mix
  effect: changed
credit: [ZivDero, dkeeton]
---

A campaign mission now starts when neither `E<xx>SCD<nn>.MIX` nor `SIDECD<nn>.MIX` is found for the player's side. It used to fall back to the first side's archives, and failed to load when those had no CD archive either. The score screen then leaves out a picture or movie it cannot find. Map selection between missions still needs its files, so a campaign that ships none should set `SkipMapSelect=yes` on its missions.

dkeeton is credited for the ts-patches change this follows.
