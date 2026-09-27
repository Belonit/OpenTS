---
key: TalkBubbleTime
summary: How long a scripted talk bubble stays above the unit that is speaking.
when_omitted:
  kind: value
  value: "5"
---

The value is in seconds, and fractions are accepted. The time is measured on the computer's clock, so game speed does not change it and it keeps running while the game is paused.

A bubble lasts slightly less than the number written: each written second becomes 60 clock ticks, and the clock runs 62.5 ticks a second. `5` becomes 300 ticks, which run out after 4.8 seconds.

```ini title="rules.ini"
[General]
TalkBubbleTime=8  ; a bubble stays up for about 7.7 seconds
```

The [Talk Bubble](/mapping/missions/tmission-talk-bubble/) team mission puts a bubble up, and so can the [Talk Bubble...](/mapping/actions/taction-talk-bubble/) trigger action. Only one bubble exists at a time, so placing a second takes the first away. The bubble disappears when the time runs out, or earlier when the trigger action runs from a trigger that has no team.

Placing a bubble also uncovers two cells of ground around the speaker for every human player, so the player can see who is talking.
