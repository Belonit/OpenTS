---
title: Add the developer overlays
category: internal
release: 0.2.0
targets:
  - type: command
    id: fixed:debug-benchmark-overlay
    effect: added
credit: [ZivDero]
---

A Debug build with the debug keys armed shows a frame benchmark window on F6, drawn over the game and its menus. The window reports the logic frames and presents of the last second, how long each timed step of a frame takes, and the rules and scenario load times. It takes the mouse while the pointer is over it or a button pressed over it is held, and the keyboard only while one of its controls is in use. All other input reaches the game or menu as usual.
