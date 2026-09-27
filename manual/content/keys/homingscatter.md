---
key: HomingScatter
summary: Parsed scatter distance that the engine never uses.
no_effect: true
see_also: ["BallisticScatter", "Inaccurate", "ROT"]
when_omitted:
  kind: value
  value: "2"
---

No scatter is sized by this value. Firing scatters the aim point only for a projectile type that sets both [`Inaccurate=yes`](/keys/inaccurate/) and [`Arcing=yes`](/keys/arcing/), and [`BallisticScatter`](/keys/ballisticscatter/) sizes that scatter. A homing projectile, one whose [`ROT`](/keys/rot/#scope-bullettype) is above zero, is therefore not scattered by `Inaccurate=yes` alone.
