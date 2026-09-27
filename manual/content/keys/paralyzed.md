---
key: Paralyzed
summary: Keeps a soldier or an armed vehicle on this mission from being given a new one when it runs out of things to do.
see_also: [Zombie, Scatter, NoThreat]
when_omitted:
  kind: value
  value: "no"
---

`Paralyzed` is set in a mission's section and applies to every object while it is on that mission.

```ini title="rules.ini"
[Sticky]      ; the section of the Sticky mission
Paralyzed=yes
```

A soldier, or a vehicle with a weapon in its first weapon slot, normally switches to a guard mission when it has no target and no destination left. If its current mission sets `Paralyzed=yes`, it stays on that mission instead. An object on Guard, Area Guard or Patrol stays on that mission anyway, so the setting matters only for other missions.

Vehicles with `Harvester=yes` or `Weeder=yes`, and vehicles without a weapon, ignore the setting. When they run out of orders, they switch to harvesting, unloading or guard under the same conditions as on a mission without the setting.

A vehicle on a `Paralyzed=yes` mission does not scatter away from a threat. A scatter with no threat to move away from, such as the player's scatter command, still sends it to a nearby cell. Infantry ignore the setting when they scatter.

Despite its name, the setting does not stop the object from moving. A player order, a team script or an override mission moves it as usual.
