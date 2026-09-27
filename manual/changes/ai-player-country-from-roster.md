---
title: Draw a computer player's country from the lobby's own list
category: fix
release: 0.2.0
targets:
- type: key
  id: Multiplay
  effect: changed
credit: [ZivDero]
---

A computer player whose country the launch file does not name now gets a random country from those whose `rules.ini` sections set `Multiplay=yes`, which are the countries the lobby offers. If no country sets it, the computer player gets the first country in `[Houses]`. It used to get one of the first two countries in `[Houses]`, whether or not the lobby offered them.

The shipped rules set `Multiplay=yes` on exactly those first two countries, so games on the shipped rules draw the same countries as before.
