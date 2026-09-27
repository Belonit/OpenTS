---
key: TreeFlammability
summary: Chance a burning terrain object sets fire to each unburnt terrain object beside it.
when_omitted:
  kind: value
  value: ".1"
---

A burning terrain object tries to spread fire on roughly one game frame in a hundred, and no setting changes that interval. On each attempt, each neighboring terrain object that is not burning gets a draw with this chance, from 0 to 1. The stock `.05` gives each such neighbor a one-in-twenty chance per attempt. At `1` or more, practically every neighbor wins its draw on every attempt.

A burning tree with terrain objects in all eight neighboring cells makes eight separate draws on each attempt, one for each neighbor.

A neighbor that wins the draw catches fire only if it can burn. [`TreeFire`](/keys/treefire/) lists the conditions, describes the other way a terrain object catches fire, and sets the flames a burning object shows.
