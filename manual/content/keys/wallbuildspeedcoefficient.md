---
key: WallBuildSpeedCoefficient
summary: The multiplier applied to a wall's build time.
when_omitted:
  kind: value
  value: ".5"
---

A BuildingType marked [`Wall=yes`](/keys/wall/#scope-buildingtype) takes this fraction of its normal build time. The default halves it, and a value above `1` makes walls slower to build. The multiplier applies last, after the house's build-speed multiplier and the effects of low power and multiple factories. No other object type reads it.
