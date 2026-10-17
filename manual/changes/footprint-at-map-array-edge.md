---
title: Keep object footprints inside the map's cell storage
category: fix
release: 0.2.0
targets: []
credit: [ZivDero, Rampastring]
---

An object whose footprint reaches past the edge of the 512 by 512 cell grid no longer reads memory outside the map when it is placed or removed. Footprint cells outside the grid are skipped, as cells without ground already were.

Rampastring is credited for the Vinifera fix this follows.
