---
key: AIWallDefense
scope: side
label: Side wall defense count
see_also: [AIWallDefenseCoefficient, AIWallTowers, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side takes GDIWallDefense as each rules file sets it; any other side uses 0.
---

```ini title="rules.ini"
[GDI]
AIWallDefense=6
```

Along its [perimeter wall](/systems/ai-base-building/#walls-and-gates), a computer house playing for this side adds pairs of a wall tower and a base defense. This value is the fixed part of the limit on how many pairs it adds. Raising it lets a long wall carry more pairs.

The house adds one pair for every five wall cells it plans, rounded down. The limit is `(3 - Difficulty) * `[`AIWallDefenseCoefficient`](/keys/aiwalldefensecoefficient/)` + AIWallDefense`, also rounded down, where `Difficulty` is the house's [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). A wall too short to reach the limit is unaffected by this key.

The house adds pairs only when the side's [`AIWallTowers`](/keys/aiwalltowers/) names a type its country may own.
