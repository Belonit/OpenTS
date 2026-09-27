---
key: AIWallDefenseCoefficient
scope: side
label: Side wall defense coefficient
see_also: [AIWallDefense, AIWallTowers, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side takes GDIWallDefenseCoefficient as each rules file sets it; any other side uses 0.
---

```ini title="rules.ini"
[GDI]
AIWallDefenseCoefficient=3
```

The part of the limit on wall tower and defense pairs that grows with the game's difficulty. A computer house playing for this side adds at most `(3 - Difficulty) * AIWallDefenseCoefficient + `[`AIWallDefense`](/keys/aiwalldefense/) pairs along its [perimeter wall](/systems/ai-base-building/#walls-and-gates), rounded down. The house adds pairs only when the side's [`AIWallTowers`](/keys/aiwalltowers/) names a type its country may own.

`Difficulty` is the house's [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). On a Hard game the computer normally holds slot 0, so this value counts three times; on Easy it counts once. The limit matters only for a wall long enough to want more pairs, at one pair per five wall cells.
