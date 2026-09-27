---
key: StretchMovies
summary: Scales a full screen movie to fit the display instead of playing it at its native size.
see_also: [ScreenWidth, ScreenHeight]
when_omitted:
  kind: value
  value: "no"
---

`StretchMovies=yes` scales every full screen movie to fit the game screen, which is [`ScreenWidth`](/keys/screenwidth/) by [`ScreenHeight`](/keys/screenheight/) pixels. A movie that plays in a fixed rectangle, such as one in the radar pane, keeps its size either way.

A stretched movie keeps its proportions. It is scaled until it meets the screen's edges in one direction, and is centered in the other. A 640 by 400 movie on a 1920 by 1080 screen therefore plays at 1728 by 1080, with a black band down each side. At 1280 by 800 the same movie fills the screen.

Any full screen movie that does not cover the whole screen, stretched or not, is surrounded by black.

The display options screen has the same switch. Accepting that screen changes the setting, and leaving the options menu saves it to `sun.ini`.
