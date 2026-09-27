---
key: AIBaseDefensesWithWalls
scope: side
label: Side defenses beside walls
see_also: [AIBaseDefensePlaceholders, AIBuildsWalls, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: yes for the second side and no for every other.
---

```ini title="rules.ini"
[Nod]
AIBaseDefensesWithWalls=yes
```

Whether a computer house playing for this side adds its [`AIBaseDefensePlaceholders`](/keys/aibasedefenseplaceholders/) block of extra base defenses even when it also plans a perimeter wall. With `no`, the house adds that block only when it plans no wall.

This key does not control the tower and defense pairs placed along a wall. [`AIWallTowers`](/keys/aiwalltowers/), [`AIWallDefense`](/keys/aiwalldefense/) and [`AIWallDefenseCoefficient`](/keys/aiwalldefensecoefficient/) set those.
