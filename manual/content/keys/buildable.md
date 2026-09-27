---
key: Buildable
summary: Allows buildings and new Tiberium growth on a land type.
see_also: ["system:tiberium", "AllowTiberium"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[Rough]
Buildable=yes
```

A land type set to `no` refuses both buildings and new Tiberium:

- A cell can take part of a building's foundation only when its land type is buildable. Two placements skip this test. A [laser fence segment](/keys/laserfence/) may cross Tiberium or veins, and a wall, gate or wall tower may go on a cell holding a wall its house owns, under the conditions in [Walls and gates](/systems/walls-and-gates/). A [`DeployToFire=yes`](/keys/deploytofire/) vehicle also deploys to attack only from a buildable cell.
- A cell accepts [new Tiberium](/systems/tiberium/#spread) only when its land type is buildable.
