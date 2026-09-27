---
key: AIBaseDefensePlaceholders
scope: side
label: Side defense placeholders
see_also: [AIBaseDefensesWithWalls, AIBaseDefenseCoefficient, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: 3 for the first side and 2 for every other.
---

```ini title="rules.ini"
[GDI]
AIBaseDefensePlaceholders=3
```

Sets how many extra base defenses a computer house playing for this side adds at the end of its [generated base plan](/systems/ai-base-building/#building-the-plan). The house adds `(3 - Difficulty)` times this value as `-1` placeholders, where `Difficulty` is its [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). On a Hard game the computer normally holds slot 0, so it adds three times this value; on Easy it adds the value once.

When its plan holds at least three structures, the house adds this block in either of these cases:

- it plans no perimeter wall, because the side's or the global [`AIBuildsWalls`](/keys/aibuildswalls/) is `no`;
- the side sets [`AIBaseDefensesWithWalls=yes`](/keys/aibasedefenseswithwalls/).

When the side's [`AIWallTowers`](/keys/aiwalltowers/) names a type the house's country may own, a node of that tower precedes each placeholder.

The [defense planner](/systems/ai-base-building/#base-defenses) later fills each placeholder with an [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype) type the country may own, chosen by its defense values. The side does not list which defenses to build.
