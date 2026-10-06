---
title: Present the game through bgfx instead of DirectDraw
category: feature
release: 0.1.0
breaking: true
targets:
- type: key
  id: Fullscreen
  effect: added
- type: key
  id: WindowWidth
  effect: added
- type: key
  id: WindowHeight
  effect: added
- type: key
  id: ScaleMode
  effect: added
- type: key
  id: IntegerScaling
  effect: added
- type: key
  id: VSync
  effect: added
- type: key
  id: Renderer
  effect: added
- type: key
  id: CursorScale
  effect: added
- type: key
  id: VideoBackBuffer
  effect: removed
- type: key
  id: AllowHiResModes
  effect: removed
- type: key
  id: AllowModeToggle
  effect: removed
- type: command
  id: launch:high-color
  effect: removed
credit: [ZivDero]
---

OpenTS now presents its software-rendered picture through bgfx instead of DirectDraw. Fullscreen uses a borderless window and scales the picture without changing the desktop resolution. The mouse pointer uses the game artwork as a system cursor.

The display options list resolutions from 640 by 400 through 4096 by 4096. `AllowHiResModes`, `AllowModeToggle`, `VideoBackBuffer`, the `HIRES` and `TOGGLE` cheats and the `-16` launch option have been removed.
