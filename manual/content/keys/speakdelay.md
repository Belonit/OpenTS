---
key: SpeakDelay
summary: Minutes an EVA announcement waits before it may be repeated.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "2"
---

After EVA announces one of these warnings, the same warning waits this many minutes before it can be announced again:

- the player's base is under attack, or an ally's base is under attack;
- funds are low;
- Tiberium storage is nearly full;
- [power is low](/systems/power/#player-feedback).

The funds and storage warnings share one wait, so either one holds back the other. The attack warnings and the power warning each wait separately. A larger value spaces the warnings further apart.

The wait is scaled by the game speed setting, so it lasts roughly the same real time at any speed.
