---
title: Resume the music after an ion storm, or play a storm sound over it
category: feature
release: 0.2.0
targets:
- type: key
  id: IonStormVolume
  effect: added
- type: system
  id: ion-storms
  effect: changed
- type: system
  id: music
  effect: changed
credit: [ZivDero]
---

The music track that was playing when an ion storm broke now resumes from where it paused when the storm ends, instead of starting over. A mod can instead register an `IONSTORM` sound in SOUND.INI; the storm then plays that sound and keeps the music playing at THEME.INI's `IonStormVolume=`. A game loaded during a storm starts the storm's audio again.
