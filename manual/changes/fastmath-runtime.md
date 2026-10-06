---
title: Replace the fastmath lookup tables
category: internal
release: 0.1.0
breaking: true
targets: []
credit: [ZivDero]
---

OpenTS now uses C runtime trigonometric and square-root functions instead of fastmath lookup tables. Numerical results may differ, affecting saves, recordings and network synchronization.
