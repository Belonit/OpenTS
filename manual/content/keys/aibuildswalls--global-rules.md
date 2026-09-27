---
key: AIBuildsWalls
scope: global-rules
label: Global wall planning
see_also: [NodAIBuildsWalls, "system:ai-base-building"]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="rules.ini"
[General]
AIBuildsWalls=yes
```

Whether computer houses may plan a [perimeter wall](/systems/ai-base-building/#walls-and-gates) around their bases. With `yes`, each side decides with its [`AIBuildsWalls`](/keys/aibuildswalls/#scope-side). With `no`, no computer house plans a wall, whatever its side sets.

A house that plans no wall adds its side's [`AIBaseDefensePlaceholders`](/keys/aibasedefenseplaceholders/) block of extra base defenses to its plan instead, when its plan holds at least three structures.
