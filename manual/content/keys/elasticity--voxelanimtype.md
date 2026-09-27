---
key: Elasticity
scope: voxelanimtype
label: Voxel debris bounciness
see_also: ["BounceAnim", "BounceSound", "Duration", "DamageRadius"]
when_omitted:
  kind: value
  value: "0.8"
---

The fraction of its speed a piece keeps each time it strikes something. The piece rebounds off the slope of the cell it struck, and this setting scales its whole velocity. It changes how fast the piece leaves the contact, not the direction it leaves in.

A value above `1` returns more speed than the piece arrived with, so the piece bounces higher after each contact until [`Duration`](/keys/duration/) runs out.

A piece stops bouncing when its remaining motion falls below `2.5`. Remaining motion combines the piece's speed with its height: each lepton of height above the ground, or above a bridge deck the piece is over, counts as 1.4 leptons per frame of upward speed. When the figure falls below the threshold, the piece settles. Its lifetime ends and the impact follows on the next frame. A contact that settles the piece does not count as a strike.

:::caution[A value of zero suppresses the bounce effects on a landing]
A piece that keeps none of its speed settles the first time it lands, so that landing is not a strike. [`BounceAnim`](/keys/bounceanim/#scope-voxelanimtype), [`BounceSound`](/keys/bouncesound/#scope-voxelanimtype) and the bounce damage all need a strike, so a piece that falls and stops triggers none of them.
:::
