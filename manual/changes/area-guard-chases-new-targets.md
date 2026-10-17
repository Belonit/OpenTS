---
title: Units guarding another object engage each new target directly
category: fix
release: 0.2.0
targets: []
credit: [ZivDero, JoyfulShush]
---

A unit ordered to guard another object used to walk back to that object between targets, even when the next target was already in reach. It now heads straight for each new target. It still returns when it strays too far from the object it guards.

JoyfulShush is credited for the Vinifera fix this follows.
