---
key: CurleyShuffle
summary: Whether an attacking aircraft moves to a new firing position after every second shot.
when_omitted:
  kind: value
  value: "no"
---

`CurleyShuffle` decides whether an attacking aircraft fires from one position or moves between shots. It matters only while the aircraft is in range of its target and is not strafing.

- With `CurleyShuffle=no`, the aircraft stays at its firing position and keeps firing until it loses the target or the target leaves range. If it is not facing the target, it turns where it is.
- With `CurleyShuffle=yes`, the aircraft fires up to two shots from each position, then picks a new position and flies there. If it is not facing the target, it moves to a new position instead of turning.

An aircraft that is out of range of its target picks a new position under either setting.

An attacking aircraft spends one round of [`Ammo`](/keys/ammo/) per firing position, however many shots it fires there. With `CurleyShuffle=yes`, that is one round for every two shots. With `CurleyShuffle=no`, the round is spent only when the aircraft leaves the position, so it never runs out of ammunition while it stays.

An aircraft strafes when the projectile of its primary weapon has a [`ROT`](/keys/rot/#scope-bullettype) of `1` or less and is not [`Inviso=yes`](/keys/inviso/). A strafing run ignores `CurleyShuffle`. It fires up to five shots spaced by the weapon's rate of fire and spends one round.
