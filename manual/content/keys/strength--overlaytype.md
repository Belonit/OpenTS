---
key: Strength
scope: overlaytype
label: Wall damage threshold
see_also: ["system:walls-and-gates", "DamageLevels"]
when_omitted:
  kind: value
  value: "1"
  note: Every hit of at least 1 damage then advances the wall a stage.
---

```ini title="rules.ini"
[MYWALL]       ; example wall overlay
Strength=100
```

For a [`Wall=yes`](/keys/wall/#scope-overlaytype) overlay, `Strength` sets how hard a single hit must be to advance the wall one [damage stage](/systems/walls-and-gates/#stepping-through-the-stages). It is not a pool of hit points. Each hit is tested on its own:

- Damage of at least `Strength` always advances the wall one stage.
- A smaller positive hit advances it with a chance of damage ÷ (`Strength` + 1). With `Strength=100`, a 20-damage hit succeeds 20 times in 101, about 19.8%.
- A failed hit leaves nothing behind for the next hit.

No hit advances a wall more than one stage, however large. [`DamageLevels`](/keys/damagelevels/) sets how many landed hits remove a segment. A segment with no connections needs one fewer, but never fewer than one (see [Stepping through the stages](/systems/walls-and-gates/#stepping-through-the-stages)). A higher `Strength` makes each hit less likely to count, so the wall lasts longer on average. No figure makes a wall invulnerable, because any positive hit keeps some chance.

A crushing vehicle removes a [`Crushable=yes`](/keys/crushable/#scope-aircrafttype) segment outright, whatever its `Strength`. The cascade into neighboring segments and the removal of a wall tower each hit for 200, which always lands against a `Strength` of 200 or less. [Walls and gates](/systems/walls-and-gates/#whether-a-hit-lands) lists every source of wall damage.

An overlay without `Wall=yes` ignores `Strength`.
