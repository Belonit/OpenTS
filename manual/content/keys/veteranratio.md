---
key: VeteranRatio
summary: The multiple of its own cost an object must destroy to earn one point of experience.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "10"
---

Experience per kill is inversely proportional to the value: doubling it halves the experience each kill gives, and halving it doubles that experience. Each credited kill adds `victim cost / (killer cost * VeteranRatio)` experience. At the default, an object must destroy enemies worth ten times its own cost to reach veteran, and twenty times to reach elite when [`VeteranCap`](/keys/veterancap/) allows it. A cheap killer therefore needs fewer kills than an expensive one against the same enemies.

[Earning experience](/systems/veterancy/#earning-experience) covers which kills count and which costs are used. The value has no bearing on ranks given by crates, armories, triggers or any other [promotion without kills](/systems/veterancy/#promotion-without-kills).

:::caution[Keep VeteranRatio and killer costs above 0]
The formula divides by this value times the killer's [`Cost`](/keys/cost/). When either is `0`, a kill of a victim that costs anything lifts the killer straight to `VeteranCap`. A kill of a victim that costs nothing leaves the killer with an unusable experience total: it behaves as a rookie, and neither later kills nor veterancy crates promote it.
:::
