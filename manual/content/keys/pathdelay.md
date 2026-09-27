---
key: PathDelay
summary: How long a ground object waits before searching for a route again after a search that failed.
see_also: [BlockagePathDelay]
when_omitted:
  kind: value
  value: ".016"
---

The value is in minutes and becomes a whole number of frames, so the default is 14 frames at 900 frames to the game minute.

After a route search fails, the object waits this long before it may search again. Each object keeps its own countdown. Driven vehicles, infantry, walkers and hovercraft all use it, and an object that needs a route cannot move on until its countdown ends.

A successful route search clears the countdown, with two exceptions that start it again right away: any route search a hovercraft makes, and any object's retry of a route around a blocking object. That retry also waits for the countdown before it runs. Giving an object a new destination clears the countdown too, so a new order never waits out the last one's delay.

What an object does after a failed search depends on where it is:

- If its destination lies in an area it cannot reach, it drops the order at once.
- If it is already near its destination, it may stop there, as [`CloseEnough`](/keys/closeenough/) describes.
- Otherwise it keeps the order and searches again each time the countdown ends. A driven vehicle or hovercraft gives up at the eleventh failed search since its last successful one. Infantry and walkers keep retrying.

:::caution[Low values cost search time]
At `0` there is no wait. An object that cannot be routed then runs a full route search on every frame it tries to move, and each such object pays that cost separately.
:::
