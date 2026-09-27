---
key: AlwaysShowActionLines
summary: Keeps a selected object's action lines drawn for as long as it stays selected.
see_also: ["system:action-lines", UnitActionLines, ShowNavComQueueLines]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, a selected object's action lines stay drawn for as long as it is selected. With `no`, they show for 25 game frames after the player selects objects or gives an order with the mouse, and while the queue-move key is held.

[`UnitActionLines=no`](/keys/unitactionlines/) in `sun.ini` still turns the lines off. [Action lines](/systems/action-lines/) covers which lines are drawn.

```ini title="UI.INI"
[Ingame]
AlwaysShowActionLines=yes
```
