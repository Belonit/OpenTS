---
key: Color
scope: bullettype
label: Voxel projectile remap
see_also: [Inviso, Voxel]
when_omitted:
  kind: computed
  note: "The first color scheme declared in [Colors]."
---

The value names a color scheme declared in [`[Colors]`](/keys/color/), in any letter case. A name that `[Colors]` does not declare leaves the projectile on the scheme it already had.

Only a projectile drawn as a voxel model uses the scheme. The model is drawn through it, so the scheme sets the model's remap colors. A projectile drawn from a shape, or one marked [`Inviso=yes`](/keys/inviso/), takes no color from this setting.

```ini title="rules.ini"
[ChemMissile]
Image=MISLCHEM ; an art section marked Voxel=yes
Color=DarkGreen
```

The scheme belongs to the projectile type. It does not follow the house that fired the projectile, as a unit's colors do.
