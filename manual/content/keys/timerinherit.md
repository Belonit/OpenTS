---
key: TimerInherit
summary: Whether this mission resumes the countdown timer the previous one finished with.
see_also: [CarryOverMoney]
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
TimerInherit=yes
```

With the switch on, a campaign mission starts with the countdown the previous mission had left when it was won. The timer starts running from that value. A countdown that a trigger had stopped with time left is carried over too, and it runs in the new mission. If the captured countdown had no time left, or the switch is off, the mission starts with its countdown stopped, and a trigger action has to start one.

The countdown is captured when a campaign mission is won, together with the money [`CarryOverMoney`](/keys/carryovermoney/) passes on. The money settings do not affect the timer.

Losing and replaying a mission captures nothing new. Each restart reapplies the countdown stored when the previous mission was won.
