---
title: Repaint every cell flagged for redraw
category: fix
release: 0.1.0
targets: []
credit:
- ZivDero
---

Frames that change more than 800 map cells now repaint every changed cell. Previously the excess cells kept their old picture until another change or a full redraw.
