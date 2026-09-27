---
title: Queue a Tiberium cell to grow only once
category: fix
release: 0.2.0
targets:
- type: system
  id: tiberium
  effect: changed
credit:
- ZivDero
---

A Tiberium cell is now queued to grow at most once. It could be queued many times over, most often after a chain reaction across a field. Each growth pass grows a limited number of cells, and every stale copy used up one of them without growing anything, so growth stayed slow until the queue drained.
