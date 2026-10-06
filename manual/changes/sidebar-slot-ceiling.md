---
title: Stop a tall picture from laying out more sidebar rows than a strip holds
category: fix
release: 0.1.0
targets:
- type: system
  id: sidebar
  effect: changed
credit: [ZivDero]
---

Each sidebar strip now supports up to 60 visible rows instead of 20. Taller rendering resolutions no longer write beyond the row storage. Above 60 rows, the sidebar artwork stops at the last supported row.
