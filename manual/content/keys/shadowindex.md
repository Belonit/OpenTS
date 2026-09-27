---
key: ShadowIndex
summary: Selects the voxel section a vehicle casts its shadow from.
see_also: ["Voxel"]
when_omitted:
  kind: value
  value: "0"
---

A `.vxl` model is a stack of numbered sections, counted from `0`. A vehicle's shadow is drawn from one section, not from the whole model. Point this key at the section that dominates the silhouette to give the vehicle a shadow shaped like that part.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
Voxel=yes
ShadowIndex=1 ; the second section of MYTANK.VXL throws the shadow
```

Use a section number the model has. A negative number, or one past the model's last section, reads outside the model's data and can draw a garbage shadow or crash the game.

Only a vehicle drawn from a voxel model reads this key. An aircraft always casts its shadow from section `0`, and structures and infantry cast no voxel shadow.
