---
key: BlockagePathDelay
summary: Frames a ground object spends preferring to wait out a moving obstruction before it insists on routing around one.
see_also: [PathDelay]
when_omitted:
  kind: value
  value: "60"
---

`BlockagePathDelay` sets how long an object blocked by another moving object prefers to wait for it before routing around it. It applies to infantry, walkers, hovercraft and driven vehicles. The value is a frame count, so the default is four seconds at 15 frames a second. For a two-second wait:

```ini title="rules.ini"
[AI]
BlockagePathDelay=30
```

A higher value keeps traffic queued behind a blocker for longer. A lower value sends objects around each other sooner and spreads them over more ground.

Each object has its own countdown, which starts again from the full value in two cases:

- the object is given a new destination;
- a moving object blocks it for the first time since it last moved.

While the countdown runs, a new path search costs a cell held by a moving object at up to four times a clear cell. The search usually finds the same route, so the object waits for the blocker to clear. After the countdown reaches zero, the same cell costs a thousand times a clear cell. The search then takes almost any detour, but still goes through the blocker when no detour exists.

Reaching zero does not reroute the object by itself. It changes only how the next path search treats blockers. That search runs the next time the object is blocked after its [`PathDelay`](/keys/pathdelay/) countdown has ended.
