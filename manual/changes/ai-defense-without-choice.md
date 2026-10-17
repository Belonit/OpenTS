---
title: Stop AI defense planning crashing without a choice
category: fix
release: 0.2.0
targets:
- type: system
  id: ai-base-building
  effect: changed
credit: [ZivDero, Rampastring]
---

A computer house no longer crashes the game when it plans a base defense and the weighted pick among its candidate defenses selects nothing. That base node now fails, as it does when no defense is available.

Rampastring is credited for the Vinifera fix this follows.
