---
title: Show your own chat line and draw a background behind the message list
category: feature
release: 0.2.0
targets:
- type: key
  id: TextBackgroundColor
  effect: added
credit: [ZivDero, Iran, dkeeton, CCHyper, tomsons26]
---

Each chat line you send now appears in your own message list as you send it, with the same name and tag its recipients see. `TextBackgroundColor` under `[Options]` in `sun.ini` sets the palette color drawn behind the text of the message list and of the line being typed. A line used to read `Name:text` and now reads `Name: text`, with a space after the colon.

Iran wrote the echo, adapted from his Red Alert code; dkeeton wrote the message background; CCHyper and tomsons26 are credited for the Vinifera versions of both.
