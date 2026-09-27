---
title: Honor the seed a campaign launch or -SEED names
category: fix
release: 0.2.0
targets:
- type: format
  id: spawn-ini
  effect: changed
- type: command
  id: launch:seed
  effect: changed
credit: [ZivDero]
---

A campaign mission started from a launch file now uses a nonzero `Seed` from the file's `[Settings]` section, as a skirmish already did, so launching the same file repeats the same random draws. It used to draw a new seed at every launch. The Debug build's `-SEED<number>` option now uses its number, up to 65535. It used to read every number as `0`, so each launch drew a new seed.
