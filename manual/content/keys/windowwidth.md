---
key: WindowWidth
summary: The width of the drawable area of the game window, in pixels.
when_omitted:
  kind: value
  value: "-1"
  note: The window opens at the width the game renders at, ScreenWidth.
---

The width is that of the window's drawable area. The border and title bar are added outside it. The value applies only while the game is windowed; a full-screen game ignores it.

The window opens centered on the main display. A window wider than the display opens against its left edge, and one taller than the display opens against its top edge.

While both this and [`WindowHeight`](/keys/windowheight/) are unset or at zero or below, the window follows the rendering resolution. It opens at [`ScreenWidth`](/keys/screenwidth/) by [`ScreenHeight`](/keys/screenheight/). When the resolution changes, the window resizes about its center, and is moved if needed so it stays on its display and clear of the taskbar.

When either value is above zero, the window does not follow the rendering resolution. A dimension set here opens at that many pixels. A dimension left at zero or below opens at the matching `ScreenWidth` or `ScreenHeight`. Changing the resolution later leaves the window as it is, and the picture is scaled to fit it.

Resizing the window by dragging its edge does not change this setting, so the next launch opens at the size the settings give.

The picture keeps its shape in any window. A window with different proportions shows bars on two sides instead of stretching the picture, and [`IntegerScaling`](/keys/integerscaling/) can add bars on all four. [`ScaleMode`](/keys/scalemode/) chooses how the picture is filtered when it is scaled.
