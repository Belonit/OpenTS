---
key: LaserDuration
summary: How many frames a laser beam stays drawn for.
see_also: ["IsLaser", "IsBigLaser"]
when_omitted:
  kind: value
  value: "10"
---

`LaserDuration` sets how many game frames the colored beam of an [`IsLaser=yes`](/keys/islaser/) weapon stays on screen. The beam looks the same on every frame, with no fading or blinking, and disappears when the time is up. The screen glow drawn at the high detail level ignores this value and fades out over about 22 frames.

```ini title="rules.ini"
[MyObeliskRay] ; example WeaponType
IsLaser=yes
LaserDuration=15
```

Like the other beam settings, the value is read from the weapon in the object's first weapon slot, whichever slot fired.

:::caution[Keep the value between 1 and 127]
The value is stored in a single signed byte, so `127` is the longest beam you can set. Larger values wrap around: `128` through `255` become negative, and `256` becomes `0`. A value of `0` or less shows the beam for a single frame.
:::
