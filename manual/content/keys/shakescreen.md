---
key: ShakeScreen
summary: Divisor for a shake count that nothing acts on.
see_also: [Cost, Strength]
when_omitted:
  kind: value
  value: "400"
---

```ini title="rules.ini"
[AudioVisual]
ShakeScreen=400
```

No value of this setting shakes the view. The game computes a number of shakes from it when an object is destroyed, but the shake itself does nothing.

Two kinds of object compute a shake count:

- A destroyed structure divides its [`Cost`](/keys/cost/), adjusted for its owner, by this value.
- A destroyed vehicle whose type names an explosion animation and whose [`Strength`](/keys/strength/) is above this value divides that strength by half of this value, adds three, and caps the result at six.

The only jolt the view still receives is a fixed ten-pixel one when an ion cannon blast lands on screen, and that does not read this setting.

A structure computes no count when this value is `0` or less. A vehicle computes none when half the value, rounded toward zero, is `0` or less, which includes `1`.
