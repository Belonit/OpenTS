---
key: IsBigLaser
summary: Widens the screen glow drawn along a laser beam.
see_also: ["IsLaser", "LaserDuration"]
when_omitted:
  kind: value
  value: "no"
---

`IsBigLaser=yes` draws a wider glow along the beam of an [`IsLaser=yes`](/keys/islaser/) weapon. The glow brightens the red of the ground and objects along the beam's line. It is separate from the colored beam itself, and this flag does not change the beam's colors, damage or reach. The glow is drawn only at the high [detail level](/keys/detaillevel/#scope-client-settings).

```ini title="rules.ini"
[MyObeliskRay] ; example WeaponType
IsLaser=yes
IsBigLaser=yes
```

The wide glow is 88 leptons across, and the ordinary one 68; a cell is 256 leptons. The wide glow is also slightly shorter, ending 7 leptons further in from each end than the ordinary one.

The glow fades out over about 22 frames, whatever [`LaserDuration`](/keys/laserduration/) says.

Like the other beam settings, this flag is read from the weapon in the object's first weapon slot, whichever slot fired.
