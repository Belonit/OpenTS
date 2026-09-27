---
key: TargetLaser
summary: Draws a sighting line from a firing vehicle to where its shot is aimed.
see_also: [Primary, "system:action-lines", TargetLaserTime, TargetLaserColor]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYSNIPERTANK] ; a UnitType registered in [VehicleTypes]
TargetLaser=yes
```

Each shot the vehicle fires shows a sighting line for [`TargetLaserTime`](/keys/targetlasertime/) frames. The line runs from the vehicle's turret to the point it is aiming at, with a small square at each end. It follows the aim, not the projectile, so it tracks a moving target. It disappears as soon as the vehicle has no target. By default the line is dashed and dark red; [Action lines](/systems/action-lines/) lists the `UI.INI` keys that restyle it.

The line has two limits:

- Only vehicles draw it. On an aircraft, structure or infantry type the key has no visible effect.
- It appears only for a house the local player controls, so an opponent's sighting lines are never shown.
