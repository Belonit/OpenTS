---
key: UseTurretShadow
summary: Parsed shadow flag that the engine never uses.
no_effect: true
see_also: ["Turret", "ShadowIndex", "Voxel"]
when_omitted:
  kind: value
  value: "no"
---

A [`Turret=yes`](/keys/turret/) vehicle drawn from shape artwork always casts the shadow of its hull, not of its turret. The shadow frame is the hull's current frame plus half the frame count of the shape file: hull frame `45` in a `240`-frame file casts its shadow from frame `165`. No setting selects a different frame. A voxel vehicle uses [`ShadowIndex`](/keys/shadowindex/) to choose the section its shadow is drawn from.

Stock art sets `UseTurretShadow=yes` only on the Mammoth Mk. II, a voxel vehicle.
