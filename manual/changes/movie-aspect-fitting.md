---
title: Fit a stretched movie to the display without distorting it
category: fix
release: 0.2.0
targets:
- type: key
  id: StretchMovies
  effect: changed
credit: [ZivDero, CCHyper]
---

A full-screen movie played with `StretchMovies=yes` under `[Video]` in `sun.ini`, which scales movies up to the display, now keeps its shape. It used to be scaled to the display's width and then squeezed into its height, so it looked flattened on any display proportionally wider than the movie. A 640 by 400 movie on a 1920 by 1080 display, for example, used to fill the whole screen and now plays at 1728 by 1080 with a black band down each side. A display with the movie's proportions, such as 1280 by 800, shows it as before.

The Tiberian Sun and Firestorm title movies the main menu plays now have black around them when they do not cover the display; they used to show whatever the display last held. Other full-screen movies already cleared the screen before playing.

CCHyper is credited for the Vinifera fix this one follows.
