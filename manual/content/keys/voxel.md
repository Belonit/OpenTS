---
key: Voxel
summary: Draws a vehicle, aircraft, or projectile from a voxel model instead of a shape file.
see_also: ["Image", "ShadowIndex", "Turret", "Theater"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle, aircraft, projectile, infantry, or structure type marked here loads `<Image ID>.VXL` together with its `<Image ID>.HVA` motion file. Vehicles, aircraft, and projectiles draw their body from that model. Infantry and structures load it but go on drawing their shape. An aircraft draws its body only from a voxel model, so an AircraftType without `Voxel=yes` has no body drawn at all.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
Voxel=yes ; draws MYTANK.VXL and MYTANK.HVA
```

The engine also looks for companion models, each a `.VXL` and `.HVA` pair:

- A [`Turret=yes`](/keys/turret/) vehicle loads `<Image ID>TUR` for its turret and `<Image ID>BARL` for its barrel.
- A vehicle with no turret loads neither. The exception is the amphibious transport, whose rules section is named exactly `APC`: it loads an `<Image ID>W` pair instead.
- An aircraft, projectile, infantry, or structure type looks for both the `TUR` and `BARL` pairs, whether or not it has a turret.

A companion whose `.VXL` is missing is not drawn, and nothing else changes, so a model can ship without companions. A companion `.VXL` shipped without its `.HVA` makes the engine discard the main model too, so a vehicle or aircraft has no voxel body to draw. A main `.VXL` without its `.HVA` has the same result.

On a ParticleType the flag stops the particle's shape from loading when a scenario starts, so the particle is not drawn. Loading a saved game brings the shape back. Leave the flag off particle types.

Voxel models have no theater variants. [`Theater=yes`](/keys/theater/) and [`NewTheater=yes`](/keys/newtheater/) never change which `.VXL` and `.HVA` files load.

:::caution[A voxel type has no shape to fall back on]
A vehicle or aircraft marked here is drawn from its model or not at all. A missing or misnamed `.VXL` leaves its body undrawn while it goes on fighting.

Ship both the `.VXL` and the `.HVA` for a `Voxel=yes` projectile, and ship any companion `.VXL` with its `.HVA`. If a file is missing or broken, the game can crash when the projectile is drawn.
:::
