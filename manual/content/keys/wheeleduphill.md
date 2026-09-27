---
key: WheeledUphill
summary: Speed multiplier for a vehicle that is not tracked stepping to a higher cell.
see_also: [WheeledDownhill, TrackedUphill, TrackedDownhill, SpeedType]
when_omitted:
  kind: value
  value: "1"
---

`WheeledUphill` scales a vehicle's speed on a climb. As a vehicle starts a step into a cell whose ground is higher than the ground under it, the speed that cell's [terrain](/systems/movement-and-terrain/#the-terrain-table) allows is multiplied by this value. At `0.5`, every climb is made at half the speed the terrain allows. A step between cells at the same height uses neither this value nor [`WheeledDownhill`](/keys/wheeleddownhill/).

```ini title="rules.ini"
[General]
WheeledUphill=0.5
```

Despite its name, the value applies to every vehicle whose [`SpeedType`](/keys/speedtype/) is not `Track`. Tracked vehicles use [`TrackedUphill`](/keys/trackeduphill/) instead. Only the drive [`Locomotor`](/keys/locomotor/) applies either value, so infantry, aircraft and vehicles with another locomotor, such as hover or tunnel, climb at unmodified speed.

The terrain speed is capped at full speed before this value applies, and the final speed is capped at full speed again. A value above `1` therefore speeds up a climb only when the vehicle would otherwise move below full speed: across slower terrain, or when damage has cut its speed to three quarters. It never raises the speed beyond full speed.

Only the speed of the step changes. The route search does not read this value, so a slow climb does not make a vehicle route around a hill. [Why it is slower than its Speed says](/systems/movement-and-terrain/#why-it-is-slower-than-its-speed-says) gives the other factors in a vehicle's speed.

:::caution[Keep WheeledUphill above 0]
A climb whose speed works out to exactly zero is given half speed instead, before the damage penalty, so `WheeledUphill=0` does not forbid climbing. A negative value gives the step a target speed of zero. The vehicle stops as it starts the step, unless it is already close to the end of its move.
:::
