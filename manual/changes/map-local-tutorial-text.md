---
title: Read a map's own tutorial lines
category: feature
release: 0.2.0
targets:
- type: format
  id: tutorial-ini
  effect: added
- type: action
  id: TACTION_TEXT_TRIGGER
  effect: changed
- type: format
  id: save-games
  effect: changed
credit:
- ZivDero
- CCHyper
---

A scenario file can now carry its own `[Tutorial]` section. Each line in it replaces the `TUTORIAL.INI` line with the same number, or adds a new one, for as long as that mission is played, and the mission's saved games keep those lines. A line is no longer cut at 299 characters, and a key that is not a whole number is skipped, with a note in the debug log, instead of being read as line 0.

CCHyper is credited for the Vinifera feature this ports.
