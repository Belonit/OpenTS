---
key: Loop
scope: sounds
label: Loop count
see_also: [LoopLimit, Control, Delay]
when_omitted:
  kind: value
  value: "0"
---

How many times the body of a looping sound plays. The key takes effect only with `LOOP` in the sound's [`Control=`](/keys/control/). The attack plays once before the first cycle and the decay once after the last.

`Loop=0` repeats the body until the game stops the sound, for example when its place scrolls out of range. The game stops it with a short fade, and its decay does not play.

```ini title="sound01.ini"
[ALARM]
Sounds=ALARMIN ALARM ALARMOUT
Control=LOOP ATTACK DECAY
Loop=4
```

Each play of `ALARM` plays `ALARMIN`, then `ALARM` four times, then `ALARMOUT`.

When `Loop=` is absent or negative, [`LoopLimit=`](/keys/looplimit/) is read in its place.
