---
title: Queue EVA lines instead of dropping them
category: feature
release: 0.2.0
targets:
- type: system
  id: eva-speech
  effect: added
credit: [ZivDero]
---

EVA lines now wait in a queue of up to eight and play one after another, half a second apart, with mission accomplished and mission failed ahead of the rest. A burst of different events is now heard in full; the game used to hold one pending line and drop further requests until it played. A line already playing or waiting is not queued again, and when eight lines are waiting, a new one replaces the oldest of the lowest-priority waiting lines.
