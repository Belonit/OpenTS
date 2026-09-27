---
title: Let a base plan satisfy a side factory prerequisite
category: fix
release: 0.2.0
targets:
- type: key
  id: PrerequisiteGDIFactory
  effect: changed
- type: key
  id: PrerequisiteNodFactory
  effect: changed
- type: system
  id: ai-base-building
  effect: changed
credit: [ZivDero]
---

A computer house's generated base plan used to leave out every structure with a `GDIFACTORY` or `NODFACTORY` prerequisite, because the plan treated both as never met. The plan now counts either prerequisite as met once it includes any structure from the matching `PrerequisiteGDIFactory` or `PrerequisiteNodFactory` list under `[General]` in `rules.ini`. Production already accepted a structure from those lists that the house owns.
