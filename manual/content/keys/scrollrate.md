---
key: ScrollRate
summary: How fast the tactical map is allowed to scroll, from 0 to 7, where a lower figure scrolls faster.
see_also: [ScrollMethod, AutoScroll, ScrollMultiplier]
when_omitted:
  kind: value
  value: "3"
---

`ScrollRate` limits the speed of both kinds of scrolling: edge scrolling and coast scrolling with the right mouse button. A lower value scrolls faster.

Unless [`AutoScroll`](/keys/autoscroll/) is off, resting the pointer against the edge of the screen scrolls the map, slowly at first and faster the longer the pointer stays there. The speed climbs through nine fixed steps, and `ScrollRate` sets the fastest step it may reach:

- `0` allows the second-fastest step. No value of `0` or more reaches the fastest.
- `6` allows up to the second-slowest step.
- `7` is outside the dialog's range but still valid, and holds edge scrolling to the slowest step.

Each step is a distance per sixtieth of a second, so the speed does not depend on the frame rate while the game draws at least 15 frames a second. [`ScrollMultiplier`](/keys/scrollmultiplier/) scales the step reached.

A right-button press on the map switches to coast scrolling. If the button went down off the map and is still held while edge scrolling, the speed drops by one step and cannot exceed the middle step of the nine.

For coast scrolling, `ScrollRate` plus one divides the distance the map moves for a given drag, as described on [`ScrollMethod`](/keys/scrollmethod/). `0` gives the full distance and `3` a quarter of it.

The game controls dialog offers seven positions and saves the choice to `sun.ini` when accepted. The slider's fastest position, at its right end, stores `0`, and its slowest stores `6`.

:::caution[Keep the value between 0 and 7]
The value is not range-checked. A value of `8` or more, or `-2` or less, makes edge scrolling read past the end of its table of steps, so the map scrolls by an unpredictable distance. `-1` lets edge scrolling reach the fastest step, but makes coast scrolling divide by zero, with the same unpredictable result.
:::
