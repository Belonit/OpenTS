---
title: Place control group numbers from UI.INI
category: feature
release: 0.2.0
targets:
- type: key
  id: UnitGroupNumberOffset
  effect: added
- type: key
  id: InfantryGroupNumberOffset
  effect: added
- type: key
  id: BuildingGroupNumberOffset
  effect: added
- type: key
  id: AircraftGroupNumberOffset
  effect: added
- type: key
  id: UnitWithPipGroupNumberOffset
  effect: added
- type: key
  id: InfantryWithPipGroupNumberOffset
  effect: added
- type: key
  id: BuildingWithPipGroupNumberOffset
  effect: added
- type: key
  id: AircraftWithPipGroupNumberOffset
  effect: added
- type: format
  id: ui-ini
  effect: changed
credit: [ZivDero]
---

Eight keys in the new `[Pips]` section of [UI.INI](/formats/ui-ini/#control-group-numbers) set where a selected object prints its control group number, separately for vehicles, infantry, structures and aircraft, with and without pips. Their defaults keep the original position. The keys have Vinifera's names, which Vinifera reads from `[Ingame]`.
