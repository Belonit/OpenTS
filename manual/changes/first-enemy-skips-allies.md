---
title: Pick a computer house's first enemy from outside its alliance
category: fix
release: 0.2.0
targets:
- type: system
  id: base-attacked
  effect: changed
credit: [ZivDero, dkeeton]
---

Outside a campaign, a computer house choosing its first enemy now passes over the houses it counts as allies and takes the nearest other house. It used to pick the nearest house even when that house was an ally, and an ally never becomes the enemy. A computer house whose nearest neighbor was an ally therefore had no enemy until another house angered it, usually by attacking it.

dkeeton is credited for the ts-patches change this follows.
