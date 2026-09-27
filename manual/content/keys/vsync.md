---
key: VSync
summary: Whether the renderer waits for the display's refresh before showing a finished frame.
when_omitted:
  kind: value
  value: "no"
---

With `VSync=yes`, each present waits for the display's next refresh. This removes tearing, the horizontal seam that can appear while the map scrolls.

The wait adds delay between an input, such as a scroll, and seeing its result, because the game loop pauses for each present. The mouse pointer moves without that delay, because the system draws it over the game's picture.

Whatever this setting says, the game presents at most about once per display refresh. It uses the refresh rate Windows reports for the display, or 60 Hz when none is reported, and skips a present that would come too early. The next present then shows the newest picture.

A change takes effect at the next launch.
