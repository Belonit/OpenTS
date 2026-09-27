---
key: AIWallTowers
scope: side
label: Side wall towers
see_also: [WallTower, AIWallDefense, AIWallDefenseCoefficient, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side takes WallTower as each rules file sets it; every other side lists none.
---

```ini title="rules.ini"
[GDI]
AIWallTowers=GACTWR
```

The wall towers a computer house playing for this side builds, each meant to carry a base defense that plugs into it. The house uses the first entry its country may own:

- In its [generated base plan](/systems/ai-base-building/#building-the-plan), a tower goes ahead of every `-1` base-defense placeholder.
- After planning a [perimeter wall](/systems/ai-base-building/#walls-and-gates), it adds tower and placeholder pairs along the wall, up to the limit that [`AIWallDefense`](/keys/aiwalldefense/) and [`AIWallDefenseCoefficient`](/keys/aiwalldefensecoefficient/) set. The wall cells also become the [threat ring](/systems/ai-base-building/#base-defenses), the cells where the house places its later defenses.

When the list names nothing the country may own, the house plans its placeholders without towers, adds no pairs along its wall, and has no threat ring.

Every listed type counts as already owned when the defense planner checks a defense's prerequisites, whether or not the country may own it.

The planner arms a tower with a defense that [plugs into](/keys/powersupbuilding/) that tower type, chosen by the same rules as for a `-1` placeholder. It puts that defense in the placeholder after the tower, when that placeholder is still unfilled. When that placeholder is already filled, as it can be after the computer takes over a departed player's house, the tower is built without a defense.

When none of the country's candidate defenses plug into the tower, the planner builds a standalone defense in the tower's place. When the country may own no defense that plugs into its tower, the house therefore builds no towers, although the list still supplies the threat ring and the prerequisites.
