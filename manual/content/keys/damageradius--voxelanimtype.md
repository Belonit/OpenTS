---
key: DamageRadius
scope: voxelanimtype
label: Voxel debris bounce reach
see_also: ["Damage", "Warhead", "BounceAnim", "MinDamage"]
when_omitted:
  kind: value
  value: "0"
---

The reach of a piece's bounce damage, in leptons (256 to a cell). Each time the piece strikes something outside water, every object in the struck cell within this reach of the strike point takes [`Damage`](/keys/damage/#scope-voxelanimtype) through the piece's [`Warhead`](/keys/warhead/#scope-voxelanimtype). A piece with no warhead deals no bounce damage.

```ini title="rules.ini"
[MetalShard]     ; a voxel animation type
Warhead=AP
Damage=15
DamageRadius=256 ; objects in the struck cell up to 256 leptons from the strike take the damage
```

The reach is measured as the east-west distance plus the north-south distance, not the straight line, so it covers a diamond, not a circle. Height is ignored. At `0`, only an object standing at exactly the strike point is hit.

Only objects in the struck cell are checked. A reach wider than a cell still cannot hit an object in the next cell.

Objects on a bridge deck are never hit. A strike on the deck damages objects on the ground beneath it instead.

Each hit is adjusted for the target's armor and for distance, as warhead damage always is. The distance falloff is much gentler than a blast's, because the distance counts at roughly a ninth of its true length.

The blast at the end of the piece's life does not read this setting. It is an ordinary explosion, as [`Warhead`](/keys/warhead/#scope-voxelanimtype) describes, with the warhead's [`Spread`](/keys/spread/#scope-warheadtype) setting its falloff.
