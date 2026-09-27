---
title: Let a second copy of the game run with -MULTIINSTANCE
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:multiple-instances
  effect: added
credit: [ZivDero, dkeeton]
---

The `-MULTIINSTANCE` launch option lets a copy of the game start while another copy is running, for example to play a network match against yourself on one machine. A copy started with the option never stops a later copy from starting. A copy started without it still exits if another copy started without it is running, and brings a running copy's window to the front.

dkeeton is credited for the ts-patches debugging change this follows.
