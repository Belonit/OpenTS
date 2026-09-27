---
key: AIBuildsWalls
scope: side
label: Side wall planning
see_also: [AIBaseDefensesWithWalls, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The second side takes NodAIBuildsWalls as each rules file sets it; every other side builds walls.
---

```ini title="rules.ini"
[Nod]
AIBuildsWalls=no
```

Whether a computer house playing for this side ends its generated base plan with a [perimeter wall](/systems/ai-base-building/#walls-and-gates). The house plans a wall only when both this key and the global [`AIBuildsWalls`](/keys/aibuildswalls/#scope-global-rules) are `yes`.

A house that plans no wall adds the side's [`AIBaseDefensePlaceholders`](/keys/aibasedefenseplaceholders/) block of extra base defenses instead, when its plan holds at least three structures. A side that sets [`AIBaseDefensesWithWalls=yes`](/keys/aibasedefenseswithwalls/) gets that block together with the wall.
