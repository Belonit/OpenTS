---
title: Let barracks and vehicle factories run their production animation
category: feature
release: 0.2.0
targets:
- type: key
  id: ProductionAnim
  effect: changed
credit: [ZivDero, Rampastring]
---

`ProductionAnim=` in a structure's `art.ini` entry now also plays when a finished infantryman leaves a barracks or a finished vehicle leaves a factory without `WeaponsFactory=yes`. It used to play only on a construction yard, refinery, repair bay or weapons factory. An aircraft factory still does not play it, and neither does a hospital or armory when a healed or upgraded infantryman leaves, unless the structure also builds infantry.
