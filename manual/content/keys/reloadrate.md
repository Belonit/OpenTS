---
key: ReloadRate
summary: The interval between the ammunition points a rearming building hands the object docked with it.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".05"
---

```ini title="rules.ini"
[General]
ReloadRate=.1   ; one ammunition point every 90 frames
```

A [`UnitReload=yes`](/keys/unitreload/) building gives the object docked with it one point of [`Ammo`](/keys/ammo/) per interval, and this key sets the interval. A building that is also [`UnitRepair=yes`](/keys/unitrepair/) repairs instead and never gives these points, as [the service order](/systems/repair/#unitreload-is-a-different-service) describes. The value is a fraction of a minute: the game multiplies it by 900 frames and truncates, so the default gives one point every 45 frames. The first point arrives one interval after the object docks.

It does not affect a weapon's delay between shots, or a vehicle that refills its ammunition by itself away from any building.
