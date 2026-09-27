---
key: TechLevel
scope: house-per-scenario
label: House tech level
see_also: ["system:production"]
when_omitted:
  kind: computed
  note: The scenario number stands in, so a house in the third mission of a campaign starts at level 3.
---

The house may build an object type only when this level is at least the type's own [`TechLevel`](/keys/techlevel/#scope-aircrafttype). A computer house's base plan, harvester replacement and AI triggers are limited by the same level.

The key takes effect in campaign games only. Other games do not read the map's house sections. In those games every player's house holds [the level chosen for the game](/keys/techlevel/#scope-global-rules), and the Neutral and Special houses hold level 1.
