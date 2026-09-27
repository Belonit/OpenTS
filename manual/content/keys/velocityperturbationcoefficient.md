---
key: VelocityPerturbationCoefficient
summary: How much a railgun trace randomly varies its particles' speed.
see_also: [BehavesLike, MovementPerturbationCoefficient, PositionPerturbationCoefficient, Velocity]
when_omitted:
  kind: value
  value: "0.0"
---

A railgun trace adds a random speed offset to each particle's [`Velocity`](/keys/velocity/) as it lays the particle. The offset changes only how fast a `Railgun` particle travels; its direction is set separately, as [`MovementPerturbationCoefficient`](/keys/movementperturbationcoefficient/) describes. The offset is a fixed amount of speed, not a share of `Velocity`, so the same setting varies a slow particle proportionally more than a fast one. A `Spark` particle ignores its speed, and particles of other behaviors do not move in a railgun trace, as [The turn](/systems/particle-systems/#the-turn) describes. Only the `Railgun` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads this key.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
MovementPerturbationCoefficient=.3
VelocityPerturbationCoefficient=.6 ; speeds vary by at most about .21 either way
```

The trace lays its particles from the muzzle outward, and each offset builds on the one before:

1. Start from the previous particle's offset, or from zero for the first particle.
2. Add a random amount between `-0.5` and `0.5`.
3. Multiply the sum by half this value.
4. Cap the result at this value, and hold it at or above `MovementPerturbationCoefficient` negated.

From `0` up to `2`, step 3 shrinks the carried offset, so it stays within plus or minus this value divided by (4 minus twice this value). At the stock `.6` that bound is about `.21`, against the stock railgun particles' `Velocity` of `.4` and `.3`. The cap in step 4 is higher than that bound for any positive value below `1.5`, so it only takes effect from `1.5` up. From `2` up, the carried offset no longer shrinks and drifts out to the cap or the floor.

Below `0`, the cap in step 4 is negative. Every particle then starts slower than its `Velocity`, unless `MovementPerturbationCoefficient` is `0` or less and the floor in step 4 lifts the offset back up.

Step 3 also sets how closely neighboring particles match. Each particle carries over a fraction of the previous particle's offset equal to half this value: three tenths at `.6`. At stock settings each speed is therefore mostly a fresh draw.

The floor in step 4 comes from `MovementPerturbationCoefficient`, not from this key, so the two limits differ unless the keys are equal. At stock settings the floor never takes effect, because the stock `MovementPerturbationCoefficient` values of `.3` and `.4` both lie beyond the `.21` bound. Setting `MovementPerturbationCoefficient` below the bound cuts off the slow side of the range, and at `0` no particle starts slower than its `Velocity`.

At zero, every particle starts at exactly its `Velocity`, unless `MovementPerturbationCoefficient` is negative.

A negative `MovementPerturbationCoefficient` raises the floor in step 4 above zero, so every particle starts faster than its `Velocity` by at least the floor: at `-.1`, at least `.1` faster. Where the floor is at or above this value, as it always is when this value is `0`, every particle starts exactly the floor faster.
