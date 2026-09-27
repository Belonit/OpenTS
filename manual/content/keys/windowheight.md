---
key: WindowHeight
summary: The height of the drawable area of the game window, in pixels.
when_omitted:
  kind: value
  value: "-1"
  note: The window opens at the height the game renders at, ScreenHeight.
---

The height is that of the window's drawable area. The border and title bar are added outside it. The window opens centered on the main display. A window taller than the display opens against its top edge.

[`WindowWidth`](/keys/windowwidth/) explains how the pair sizes the window, when the window stops following the rendering resolution, and how a picture that does not match the window's shape is fitted.

The value applies only while the game is windowed; a full-screen game ignores it.
