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

No value of this setting shakes the view. The game computes a number of shakes from it when an object is destroyed, but the shake itself does nothing. The value still matters because three values crash the game.

Two kinds of object compute a shake count:

- A destroyed structure divides its [`Cost`](/keys/cost/), adjusted for its owner, by this value.
- A destroyed vehicle whose type names an explosion animation and whose [`Strength`](/keys/strength/) is above this value divides that strength by half of this value, adds three, and caps the result at six.

The only jolt the view still receives is a fixed ten-pixel one when an ion cannon blast lands on screen, and that does not read this setting.

:::danger[Keep ShakeScreen at 2 or above]
The divisions have no guard against zero. At `0`, the first structure destroyed crashes the game. At `0`, `1` or `-1`, half the value rounds to zero, so the first vehicle destroyed that names an explosion animation crashes the game.
:::
