---
key: RadarInvisible
scope: aircrafttype
label: Object types
no_effect: true
when_omitted:
  kind: context-dependent
  note: A BulletType, OverlayType, SmudgeType, TerrainType or VoxelAnimType section starts at yes. Every other object type starts at no.
---

The [radar test](/systems/cloaking/#on-the-radar) ignores this key. It reads [`Invisible`](/keys/invisible/) and [`RadarVisible`](/keys/radarvisible/) from the type instead.

To keep an aircraft, infantry unit or vehicle in plain view off other players' radar, list `RADAR_INVISIBLE` among its type's [veteran abilities](/systems/veterancy/#abilities). It takes effect once the object reaches the rank whose list names it. Another player's radar still plots the object while that player senses its cell, and always plots it when its type sets `RadarVisible=yes`. The ability has no effect on a structure's radar plot.
