---
key: Anim
summary: The animations played at the firing coordinate when the weapon goes off, either one fixed entry or one per facing.
see_also: ["Report", "PrimaryFireFLH"]
when_omitted:
  kind: value
  value: ""
---

The number of entries decides which animation a shot plays:

- A list of `8`, `16`, `32` or `64` entries gives one animation per direction, and each shot plays the entry for the direction the object fires in.
- A list of any other length plays its first entry on every shot and ignores the rest.

```ini title="rules.ini"
[MyGatling] ; example WeaponType
Anim=GUNFIRE1,GUNFIRE2,GUNFIRE3,GUNFIRE4,GUNFIRE5,GUNFIRE6,GUNFIRE7,GUNFIRE8 ; AnimTypes registered in [Animations]
```

A directional list starts at north-west and runs clockwise. An eight-entry list therefore runs north-west, north, north-east, east, south-east, south, south-west, west. A longer list also starts at north-west and divides the circle into as many equal steps as it has entries.

The direction used is the one the weapon is aiming in:

- A vehicle with a turret uses the turret's facing. A vehicle without one uses its body's facing.
- Infantry and aircraft use the direction they face.
- A structure with a turret uses the turret's facing. A structure with no turret, or whose turret animation is a voxel, uses the direction to its target.

The animation appears at the weapon's muzzle. On a vehicle, infantry or aircraft it is attached to the firing object and moves with it. On a structure it stays where it appeared. On a burst weapon it can appear at the opposite muzzle from the projectile, as [Firing geometry](/systems/firing-geometry/#how-a-burst-alternates-muzzles) describes.

`Anim=none` empties the list, and the weapon plays no firing animation. A `none` entry inside a longer list is dropped, which shortens the list and can change how entries are chosen. An empty value after the `=` keeps whatever an earlier rules file set. A name the game does not already know is registered as a new animation type, so a misspelled entry is not rejected and still takes its place in the list.

The animation plays on an object's regular weapon shots. A weapon that goes off another way plays none. That includes the [Do Explosion At](/mapping/actions/taction-do-explosion/) trigger action, the EM pulse cannon's shot at its chosen cell, and a mobile EM pulse discharge.
