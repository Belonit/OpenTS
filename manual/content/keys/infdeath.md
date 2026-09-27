---
key: InfDeath
summary: The death sequence an infantryman killed by the warhead performs.
see_also: [Doggie, DeadBodies, InfantryExplode, FlamingInfantry, "system:laser-fences"]
when_omitted:
  kind: value
  value: "0"
---

The value selects one of six deaths:

| Value | Result |
| --- | --- |
| `0` | The soldier is removed at once, with no death sequence |
| `1` | The soldier plays its gun death sequence |
| `2` | The soldier plays its explosion death sequence |
| `3` | The soldier is removed and leaves the [`InfantryExplode`](/keys/infantryexplode/) animation |
| `4` | A [`Doggie=yes`](/keys/doggie/) type plays its burning death. Any other type is removed and leaves the [`FlamingInfantry`](/keys/flaminginfantry/) animation |
| `5` | A `Doggie=yes` type plays its burning death. Any other type is removed and leaves the electrocution animation |

Any other value behaves as `0`.

```ini title="rules.ini"
[MyFlameWH] ; example WarheadType
InfDeath=4
```

A soldier that plays a death sequence stays in place until the sequence ends, and is then removed. Every type except a dog drops one of the [`DeadBodies`](/keys/deadbodies/) corpses at that point. A soldier removed at once leaves no corpse.

These deaths ignore the warhead's value:

- A prone cyborg or a jump-jet infantryman leaves the `InfantryExplode` animation.
- A soldier that falls from a height and dies over water leaves a wake and a splash.
- A soldier killed by a [laser fence](/systems/laser-fences/) dies as if the value were `5`.

A cyborg killed by forced damage is removed at once, whatever the value. With `1` or `2` its death sequence starts, but the body disappears in the same game frame.

:::caution[The electrocution animation is fixed to a slot]
`InfDeath=5` does not name its animation. It plays the second animation in the [`[Animations]` list](/formats/rules-registries/), which is `ELECTRO` in the shipped rules. Inserting, removing or reordering entries ahead of that position changes what an electrocuted soldier leaves behind.
:::

:::caution[A burning soldier uses the viewer's colors]
The `FlamingInfantry` animation of `InfDeath=4` is drawn in the local player's color scheme, not the dead soldier's house colors. The same death therefore looks different on each player's screen.
:::
