---
key: IntegerScaling
summary: Whether the picture is only ever enlarged by whole multiples.
when_omitted:
  kind: value
  value: "no"
---

`IntegerScaling=yes` rounds the picture's enlargement down to a whole number. With the `PixelArt` or `Nearest` [`ScaleMode`](/keys/scalemode/), every rendered pixel then becomes an equal square block on screen. With `Linear`, the pixels are still blurred.

Without `IntegerScaling`, the picture keeps its shape and grows by whatever fraction fills as much of the window as possible.

The cost is unused space around the picture, and it can be large. For a 640 by 400 picture:

- In a 1280 by 800 window, the picture doubles exactly and fills the window either way.
- In a 1400 by 900 window, it doubles instead of growing 2.19 times, leaving a border on every side.
- In a 1200 by 900 window, it cannot reach a second whole multiple, so it is drawn at its rendered size in the middle of the window.

A window smaller than the rendering resolution shrinks the picture as usual, because rounding the enlargement down would leave nothing to show.

[`ScaleMode`](/keys/scalemode/) chooses how the picture is filtered. Its `PixelArt` setting already keeps pixels sharp at fractional sizes, so this setting is needed only when exactly equal pixels matter more than window space.
