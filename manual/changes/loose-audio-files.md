---
title: Load sound effects from loose files and any archive
category: fix
release: 0.2.0
targets:
- type: format
  id: aud
  effect: changed
credit: [ZivDero, CCHyper]
---

The game now finds a sound effect's sample by name through the normal file search the first time the sound plays. A loose file in the game directory plays, as does a member of any mounted archive, and a loose file replaces an archived one of the same name. Before, a sample had to be in an archive cached in memory at startup.

A `.WAV`, `.OGG`, `.FLAC` or `.MP3` sample is now accepted as well as `.AUD`, and is used in place of an `.AUD` sample with the same name.

CCHyper is credited for the Vinifera sound loading this follows, which accepts the same formats from loose files.
