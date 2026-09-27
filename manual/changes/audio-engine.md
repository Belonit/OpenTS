---
title: Replace DirectSound with the OpenTS audio engine
category: internal
release: 0.2.0
targets: []
credit: [ZivDero, CCHyper]
---

Sound effects, speech and music now play through a mixer built into OpenTS on the miniaudio library, in place of DirectSound. By default, up to sixteen sound effects play at once, where five did before. Switching to headphones or another output device no longer silences the game, because playback moves to the new device.

CCHyper is credited for the Vinifera audio system, which first moved the game to miniaudio and whose loudness curve and movie timing this engine keeps.
