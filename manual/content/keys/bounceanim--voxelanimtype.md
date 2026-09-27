---
key: BounceAnim
scope: voxelanimtype
label: Voxel debris bounce effect
see_also: ["BounceSound", "Elasticity", "DamageRadius"]
when_omitted:
  kind: value
  value: none
---

An animation of the named type plays at the piece's position each time the piece strikes something outside water. A strike is contact with the ground, with the top or underside of a bridge deck, or with a building, wall or gate in the piece's path.

A strike in a water cell plays nothing. It ends the piece's life instead, and the impact follows on the next frame.

The contact that ends the bouncing is not a strike either. When a contact leaves the piece with too little motion to keep going, the piece settles and its life ends, as [`Elasticity`](/keys/elasticity/#scope-voxelanimtype) describes. A piece with `Elasticity=0` keeps no speed after a contact, so it settles the first time it lands and never plays this animation on the ground.
