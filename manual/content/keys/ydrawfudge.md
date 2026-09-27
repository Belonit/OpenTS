---
key: YDrawFudge
summary: Pixels a terrain object's artwork is shifted down the screen by.
when_omitted:
  kind: value
  value: "0"
---

A positive value moves the artwork down the screen by that many pixels, and a negative value lifts it. The screen area the game redraws for the object moves with the artwork.

```ini title="rules.ini"
[MYROCK]         ; example boulder whose artwork sits high in its frame
YDrawFudge=6     ; push it six pixels down so it meets the ground
```

The value also shifts the object's depth, which decides how it overlaps nearby objects, but only by a third of the value with the remainder dropped. Any value from `-2` to `2` therefore leaves the depth unchanged.
