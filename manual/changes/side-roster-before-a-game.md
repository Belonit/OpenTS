---
title: Read the side roster on the network game paths
category: fix
release: 0.2.0
targets: []
credit: [ZivDero]
---

In network and internet games, the sides now take their order from `[Sides]` in `rules.ini`, as they already did in skirmish and client-launched games. Those games used to read only the countries, so the sides took the order in which the countries named them. The two orders differ only when `[Houses]` does not list the countries in the order of their sides.
