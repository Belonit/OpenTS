---
title: Let the rules aim a healing weapon at vehicles
category: feature
release: 0.2.0
targets:
- type: key
  id: Mechanic
  effect: added
- type: key
  id: OmniHealer
  effect: added
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, CCHyper, Rampastring]
---

`Mechanic=yes` in an infantry type's section of `rules.ini` makes its healing weapon mend vehicles in place of infantry. `OmniHealer=yes` on an infantry or vehicle type makes its healing weapon mend both, for the heal cursor and for the targets it picks by itself.

A healing vehicle now keeps a landed aircraft or a deployed vehicle as its target until the job is done. It used to drop such a target as soon as it could not fire at it, although it was allowed to mend it.
