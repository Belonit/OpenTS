---
key: PlayIntro
summary: Controls the one-time `EVA.VQA` startup movie.
when_omitted:
  kind: value
  value: "yes"
---

With `PlayIntro=yes`, the game plays `EVA.VQA` before the other startup movies, which play whatever this setting says. Before the movie starts, the game writes `PlayIntro=no` back to the settings file, so later starts skip it even if this one is closed during the movie. Set it to `yes` again to see the movie once more.

Starting the game with [`FROMINSTALL`](/using/command-line/from-install/) plays `EVA.VQA` whatever this setting says, and still writes `PlayIntro=no`. A game started with [`-SPAWN`](/using/command-line/spawn/) plays no startup movies and neither reads nor changes this setting.
