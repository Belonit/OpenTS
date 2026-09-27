---
key: AutoScroll
summary: Scrolls the tactical map while the pointer rests against the edge of the screen.
see_also: [ScrollRate, ScrollMethod, ScrollMultiplier]
when_omitted:
  kind: value
  value: "yes"
---

`AutoScroll=no` turns edge scrolling off. Resting the pointer against the edge of the screen no longer moves the view, and the pointer keeps its normal shape instead of turning into a scroll arrow. The keyboard scroll keys, dragging with the right mouse button as [`ScrollMethod`](/keys/scrollmethod/) describes, and clicking the radar still move the view.

[`ScrollMultiplier`](/keys/scrollmultiplier/) scales only edge scrolling, so it has no effect while this is off. [`ScrollRate`](/keys/scrollrate/) also sets the speed of right-button dragging, and keeps that effect.

The game controls dialog has the same switch. Closing the dialog with OK, or leaving it through its Sound or Keyboard button, applies the change and writes it to `sun.ini`. Cancel discards it.
