---
key: FireSupress
summary: How far around a candidate target allied buildings are searched for when the firing weapon suppresses friendly fire.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "1"
  note: One cell leaves no ring for the search to walk, so the penalty never applies until the value is raised.
---

The search runs only while an object is choosing a target, and only when its primary weapon sets [`Supress=yes`](/keys/supress/). Once the object is elite, its [`Elite=`](/keys/elite/) weapon, if it has one, takes the primary weapon's place in that test.

For each candidate target, the search walks the square rings of cells around the candidate's cell, from radius `1` out to one cell short of this distance. Every ring cell that holds a building of the object's house or an ally halves the candidate's threat score, so four such cells leave a sixteenth of the score. A building that covers several ring cells halves the score once for each of them. A candidate whose score drops below one point is no longer considered at all.

The value is a distance in cells, and fractions are accepted. The search truncates it to whole cells: `2` walks one ring, `3` walks two, and anything below `2` walks none.

```ini title="rules.ini"
[CombatDamage]
FireSupress=3
```
