---
title: Stop a self-healing aircraft from reviving in mid-air
category: fix
release: 0.2.0
targets:
- type: system
  id: repair
  effect: changed
credit: [ZivDero, JoyfulShush]
---

A self-healing aircraft shot down in flight used to heal on the way down and climb back to its flight level, however often it was shot down. It now falls and is destroyed like any other aircraft.

No shipped aircraft heals itself. The fix matters only for rules that give an aircraft `SelfHealing=yes` or the `SELF_HEAL` veteran or elite ability.
