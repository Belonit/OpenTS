---
key: ShowNavComQueueLines
summary: Draws the destinations queued behind a selected object's movement line as further lines.
see_also: ["system:action-lines", AlwaysShowActionLines, NavComQueueLineColor]
when_omitted:
  kind: value
  value: "yes"
---

The lines continue from the end of the movement line through each queued destination, in the order they will be traveled. A looping queue draws a closed ring. [Action lines](/systems/action-lines/) covers when the lines are drawn.

The player usually queues destinations with the [queue-move key](/systems/action-lines/#when-the-lines-are-shown). The game also queues some destinations itself. For example, a vehicle ordered to move while it is still leaving a weapons factory keeps that destination queued behind the factory exit.

With `no`, the queue lines are hidden. The movement line and the target line are still drawn.

```ini title="UI.INI"
[Ingame]
ShowNavComQueueLines=no
```
