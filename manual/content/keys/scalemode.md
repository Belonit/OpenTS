---
key: ScaleMode
summary: How the picture is filtered when it is scaled into the window.
when_omitted:
  kind: value
  value: PixelArt
---

The game renders at [`ScreenWidth`](/keys/screenwidth/) by [`ScreenHeight`](/keys/screenheight/) and scales that picture into the window. This setting chooses the filter used for the scaling. It accepts three names, in any capitalization:

| Value | Result |
| --- | --- |
| `PixelArt` | Sharp, evenly sized pixels whenever the picture is enlarged |
| `Nearest` | Sharp pixels, but at fractional sizes some come out larger than others |
| `Linear` | Smooth, at the cost of blurring the artwork |

`PixelArt` combines the other two filters. At an exact whole multiple, such as a 640 by 400 picture in 1280 by 800, it samples the way `Nearest` does. At any other enlargement, it first magnifies the picture with hard edges to the next whole multiple, then shrinks that smoothly into the window. The artwork stays sharp without the uneven pixel sizes that `Nearest` produces at fractional scales.

When the picture is not enlarged, `PixelArt` filters the way `Linear` does. `Nearest` samples the same way at every size.

A name the game does not recognize is read as `PixelArt`, and the setting is written back to `sun.ini` that way.

To keep the picture at whole multiples and accept unused space around it, set [`IntegerScaling`](/keys/integerscaling/).
