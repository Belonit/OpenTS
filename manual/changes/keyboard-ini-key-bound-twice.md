---
title: Keep the first binding of a key KEYBOARD.INI binds twice
category: fix
release: 0.2.0
targets:
- type: format
  id: keyboard-ini
  effect: changed
credit: [ZivDero]
---

A `KEYBOARD.INI` that gave one key to two entries left it unpredictable which command the key ran, and stopped a Debug build at startup. The earlier entry now keeps the key and the later one is ignored.
