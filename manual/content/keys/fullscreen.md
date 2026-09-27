---
key: Fullscreen
summary: Whether the game covers the whole screen instead of running in a resizable window.
when_omitted:
  kind: value
  value: "yes"
---

With this setting on, the game covers the main display with a borderless window. With it off, the game opens an ordinary framed window that can be moved, resized, and maximized. [`WindowWidth`](/keys/windowwidth/) and [`WindowHeight`](/keys/windowheight/) set that window's starting size and are ignored in full screen.

Neither mode changes the desktop's resolution. The game renders at [`ScreenWidth`](/keys/screenwidth/) by [`ScreenHeight`](/keys/screenheight/) and scales that picture into its window, so switching away from the game leaves the desktop as it was.

The [`-WIN`](/using/command-line/windowed/) command line option opens a window for that run whatever this setting says. It does not change the stored value, so a launcher can offer a window without overriding the player's choice.

A change takes effect at the next launch. Edit the file while the game is closed, because saving options in the game writes back the value the game started with.
