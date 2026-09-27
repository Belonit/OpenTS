---
title: Fall back to the base side archive when the expansion's is absent
category: fix
release: 0.2.0
targets:
- type: format
  id: mix
  effect: changed
credit:
- ZivDero
---

A mission in an expansion campaign now starts when the installation lacks that expansion's side CD archive, such as `E01SCD01.MIX` or `E01SCD02.MIX` for Firestorm. The game mounts the side's base archive, `SIDECD01.MIX` or `SIDECD02.MIX`, in its place. Such a mission used to stop with `Unable to read scenario!`, even when the base archive held every file it needed.
