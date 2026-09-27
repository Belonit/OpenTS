---
title: Read an INI line of any length
category: fix
release: 0.2.0
targets:
- type: format
  id: ini-syntax
  effect: changed
credit: [ZivDero, CCHyper, tomsons26]
---

The game now reads an INI line of any length. A line longer than 511 characters used to lose its end. List values in `rules.ini`, such as `Prerequisite`, `Explosion`, `DebrisTypes`, `Owner` and the voice lists, were also cut at 128 characters, losing the entries past that point. Every such list is now read whole.

A key whose value is still copied into fixed-size storage keeps as much as fits, and the debug log names the key the first time it is cut. An INI file the game writes back keeps a long line whole.

`ColorList` in a particle type's section used to lose the first digit of each red value and the last digit of each blue value when a color had no parentheses. It now reads such a list correctly.

A `[Tubes]` line in a map that is cut short used to crash the game. A missing position or facing now reads as `0`, and the tunnel's path ends at the last direction the line gives.

CCHyper and tomsons26 are credited for the Vinifera fix that widened the `Owner` buffer.
