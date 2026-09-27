---
title: Draw the objectives screen as a UI document
category: feature
release: 0.2.0
targets:
- type: command
  id: fixed:dismiss-mission-restatement
  effect: removed
- type: system
  id: ui-files
  effect: changed
- type: key
  id: Brief
  effect: changed
credit:
- ZivDero
---

The objectives screen, which shows the mission's written briefing, is now drawn from `restate.rml` in the `ui` directory. It keeps the side's backdrop, its buttons and their places, and the old fade: each line comes up as a white blob, then a pale shape, then text in the side's color, with a bleep as it settles.

Its colors come from `side-gdi.rcss` and `side-nod.rcss`: a style sheet named after the player's side, which every screen now takes after its own. A mod can give any side its own colors, or restyle any screen per side, with such a file.

The text is set in Arial, or in the shipped Arimo where Windows' Arial is missing, instead of the game's own lettering. A word too wide for the text box is split across lines. The first line of a page no longer shows the wrong letters for a moment before it fades in, and the pointer stays on screen while a page fades in.

Space, Enter, Escape or a click during the fade now finishes the page at once. The old screen ignored input until the page was done. Enter now works as Space does.
