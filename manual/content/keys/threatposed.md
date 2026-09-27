---
key: ThreatPosed
summary: How much danger the type represents, used by the region threat map and base-defense call-ups.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "0"
---

The figure rates how dangerous an object of this type is to other houses. It is not the object's worth as a target: no part of [target scoring](/systems/target-selection/) reads it. Two systems use it:

- **The threat map.** An object adds its figure to [the threat map](/systems/base-attacked/#the-threat-map) for the region it stands in. The computer's missile strikes, its regrouping teams, and the pathfinder through [`ThreatAvoidanceCoefficient`](/keys/threatavoidancecoefficient/) read that map.
- **Base defense.** When a computer house's base is attacked, the attacker's figure multiplied by [`ComputerBaseDefenseResponse`](/keys/computerbasedefenseresponse/) is the [defensive strength](/systems/base-attacked/#the-strength-budget) the house calls back. Each defender's own figure counts toward that total.

```ini title="rules.ini"
[MYTANK] ; example UnitType
ThreatPosed=25
```

A type left at `0` adds nothing to the threat map, and an object of that type is never called back as a defender. An attacker of that type gives the [call-up](/systems/base-attacked/#the-strength-budget) a budget of zero, so no one is called back. The call-up still [empties and suspends the house's low-priority teams](/systems/base-attacked/#teams-are-emptied-first), and it does so again on every hit.
