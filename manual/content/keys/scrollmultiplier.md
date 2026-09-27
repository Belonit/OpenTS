---
key: ScrollMultiplier
summary: Factor applied to the distance each edge scroll step moves the tactical view.
see_also: [AutoScroll, ScrollRate, ScrollMethod]
when_omitted:
  kind: value
  value: "1"
---

```ini title="rules.ini"
[AudioVisual]
ScrollMultiplier=1.5
```

`ScrollMultiplier` scales the speed of edge scrolling. A value above `1` scrolls faster and a value below `1` scrolls slower.

Unless [`AutoScroll`](/keys/autoscroll/) is off, resting the pointer against an edge of the screen scrolls the map. It moves by a step that grows the longer the pointer stays there, from 16 pixels up to the fastest step the player's [`ScrollRate`](/keys/scrollrate/) allows. Each step is a distance per sixtieth of a second. The game multiplies the step by this value and truncates the result to whole pixels. `2` therefore doubles every step without changing how quickly the speed builds up.

Only edge scrolling is scaled. Coast scrolling with the right mouse button, described on [`ScrollMethod`](/keys/scrollmethod/), ignores this value.

:::caution[Small values can stop the slowest steps]
Each step is truncated to whole pixels after the multiplication. At `0.05` the 16-pixel step becomes zero, and the map stays still until the speed reaches the 32-pixel step. At `0` edge scrolling never moves the map.
:::
