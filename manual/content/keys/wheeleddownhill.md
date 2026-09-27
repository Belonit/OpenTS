---
key: WheeledDownhill
summary: Speed multiplier for a vehicle that is not tracked stepping to a lower cell.
see_also: [WheeledUphill, TrackedUphill, TrackedDownhill, SpeedType]
when_omitted:
  kind: value
  value: "1"
---

`WheeledDownhill` scales a vehicle's speed on a descent. As a vehicle starts a step into a cell whose ground is lower than the ground under it, the speed that cell's [terrain](/systems/movement-and-terrain/#the-terrain-table) allows is multiplied by this value. At `0.5`, every descent is made at half the speed the terrain allows. A step between cells at the same height uses neither this value nor [`WheeledUphill`](/keys/wheeleduphill/).

```ini title="rules.ini"
[General]
WheeledDownhill=0.5
```

Despite its name, the value applies to every vehicle whose [`SpeedType`](/keys/speedtype/) is not `Track`. Tracked vehicles use [`TrackedDownhill`](/keys/trackeddownhill/) instead. Only the drive [`Locomotor`](/keys/locomotor/) applies either value, so infantry, aircraft and vehicles with another locomotor, such as hover or tunnel, descend at unmodified speed.

The terrain speed is capped at full speed before this value applies, and the final speed is capped at full speed again. A value above `1` therefore speeds up a descent only when the vehicle would otherwise move below full speed: across slower terrain, or when damage has cut its speed to three quarters. It never raises the speed beyond full speed.

Only the speed of the step changes. The route search does not read this value, so a fast descent does not draw a vehicle toward downhill routes. [Why it is slower than its Speed says](/systems/movement-and-terrain/#why-it-is-slower-than-its-speed-says) gives the other factors in a vehicle's speed.

:::caution[Keep WheeledDownhill above 0]
A descent whose speed works out to exactly zero is given half speed instead, before the damage penalty, so `WheeledDownhill=0` does not forbid descending. A negative value gives the step a target speed of zero. The vehicle stops as it starts the step, unless it is already close to the end of its move.
:::
