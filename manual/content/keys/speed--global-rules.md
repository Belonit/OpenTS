---
key: Speed
scope: global-rules
label: Jumpjet travel ceiling
see_also: [Acceleration, TurnRate]
when_omitted:
  kind: value
  value: "30"
---

Every jumpjet unit travels at no more than this many leptons per game frame. There are 256 leptons to a cell and 15 game frames to the second, so the default of `30` is a little under two cells a second. [`Acceleration`](/keys/acceleration/#scope-global-rules) sets how quickly a jumpjet reaches this speed.

```ini title="rules.ini"
[JumpjetControls]
Speed=20  ; about 1.2 cells a second
```

A jumpjet unit's own [`Speed=`](/keys/speed/#scope-aircrafttype) does not set how fast it travels. It still matters when another object aims ahead of a moving jumpjet vehicle. The lead is worked out from `Speed=` with the same modifiers a ground vehicle's speed gets, multiplied by the jumpjet's current speed as a fraction of this ceiling.

A jumpjet slows down as it arrives, to fractions of this value. Within two cells of its destination it flies at half this speed, and within one cell at three tenths. Within 20 leptons it stops.
