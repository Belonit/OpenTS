---
key: Gravity
summary: The downward pull applied each frame to ballistic shots, hovering and levitating objects, and some particles.
see_also: [Arcing, Floater, HoverHeight, HoverDampen, Elasticity]
when_omitted:
  kind: value
  value: "3"
---

```ini title="rules.ini"
[AudioVisual]
Gravity=6
```

Each game frame, a falling object's vertical speed drops by this value, in leptons per frame. A higher value makes things fall faster. Ballistic projectiles, hovering and levitating objects, and three kinds of particle read it.

**Ballistic projectiles.** A projectile with [`ROT=0`](/keys/rot/#scope-bullettype) loses this much vertical speed each frame, and a [`Floater=yes`](/keys/floater/) projectile loses half as much. [Ballistic flight](/systems/projectile-flight/#ballistic-flight) describes the rest of the flight.

**Launch speed.** When the rules are read, each weapon that fires a ballistic projectile gets a launch speed worked out from its [`Range`](/keys/range/) and this value, as described under [what the shot leaves with](/systems/projectile-flight/#what-the-shot-leaves-with). A higher `Gravity` in a rules file raises those launch speeds with it, so weapons keep their reach and their shots land sooner. A weapon whose projectile is [`Arcing=yes`](/keys/arcing/) aims with the same value, or half of it for a `Floater=yes` projectile. It reports a target that no arc at its launch speed can reach as out of range. The EM pulse cannon works out its launch speed from this value and the distance to its target.

:::caution[A map file's `Gravity` leaves launch speeds unchanged]
Launch speeds always use the `Gravity` from the rules files. A `Gravity=` in a map file changes how fast shots fall but not how fast they leave. A higher value there shortens how far ballistic shots can carry, and a lower one lengthens it.
:::

**Hovering and levitating objects.** A hover vehicle, or an object using the levitation locomotor, loses this much vertical speed each frame. While powered and below [`HoverHeight`](/keys/hoverheight/), it gains between one and two times this value each frame, more the further below it sits, and twice this value at ground level. Its net push upward is therefore proportional to how far below `HoverHeight` it sits. Below a quarter of `HoverHeight` it gains an extra third of this value each frame, powered or not. That third is rounded down to a whole number: `2` at `6`, `1` from `3` to `5`, and nothing at `2` or less. [`HoverDampen`](/keys/hoverdampen/) then scales the result.

**Gas and weak-gas particles.** On every other frame, these particles sink by 2 leptons plus this value. Their launch speed does not carry over, so this value sets the whole of their fall.

**Spark particles.** A spark falls faster than this value suggests. Each frame a spark's vertical speed drops by this value, and the spark then moves vertically by that speed less one more `Gravity`.

Thrown debris and bouncing animations ignore this setting and fall at a fixed rate.
