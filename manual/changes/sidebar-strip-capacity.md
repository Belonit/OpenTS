---
title: Raise the sidebar strip capacity and hold its entries inside it
category: fix
release: 0.1.0
targets:
- type: system
  id: sidebar
  effect: changed
credit: [ZivDero]
---

Each sidebar strip now holds up to 225 entries instead of 75 and refuses entries beyond that limit. Previously a full strip could accept one extra entry and corrupt memory. Tooltips now also work on a full strip.
