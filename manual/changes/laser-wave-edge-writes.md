---
title: Hold the laser wave inside the view
category: fix
release: 0.1.0
targets: []
credit: [ZivDero]
---

Laser and disruptor-style beams at the edge of the view no longer risk a crash at the highest detail level. Their fallback drawing also reaches the edge instead of stopping two pixels short.
