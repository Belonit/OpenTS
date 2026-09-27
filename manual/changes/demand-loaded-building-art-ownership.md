---
title: Keep demand-loaded artwork under its owner's lifetime
category: fix
release: 0.2.0
targets:
- type: key
  id: DemandLoad
  scope: buildingtype
  effect: changed
- type: key
  id: DemandLoad
  scope: animtype
  effect: changed
- type: key
  id: DemandLoad
  scope: overlaytype
  effect: changed
- type: key
  id: DemandLoadBuildup
  effect: changed
- type: key
  id: FreeBuildup
  effect: changed
credit: [Krisztiaan, ZivDero]
---

`DemandLoad=yes` in an `art.ini` section loads that art only when it is first needed. A structure with it could corrupt the game's memory when a theater was set up, when its construction art was released, or at shutdown, because the game released art that belonged to an archive. It now loads and releases only its own copy of the art. Animations and overlays with `DemandLoad=yes` are fixed the same way.

`DemandLoadBuildup=yes` in a structure's `art.ini` section loads its construction art on first use. `FreeBuildup=yes` in the same section now releases that art only when `DemandLoadBuildup=yes` is also set. Set alone, it used to release the archive's copy, so later structures of that type lost their construction and deconstruction animations, could not be sold, and left no technicians among the survivors when destroyed.

A demand-loaded overlay that is not theater-specific now loads the `.SHP` file its Image ID names. The file name used to be built from uninitialized memory.
