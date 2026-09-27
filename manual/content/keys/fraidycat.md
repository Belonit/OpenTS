---
key: Fraidycat
summary: Makes the soldier panic at its first hit and run instead of fighting.
see_also: [Fearless, Doggie, Ammo, Scatter]
when_omitted:
  kind: value
  value: "no"
---

Fear is a value from `0` to `255` that rises when a soldier is shot at and falls by one each logic frame. At `10` a soldier goes to ground, unless it is a dog or a human player's soldier on the move. An ordinary soldier's first hit from an attacker raises it to `100`. `200` is panic, and `255` is the ceiling.

A `Fraidycat=yes` soldier panics in two cases:

- a hit from an attacker while its fear is below `100` sets fear to `200`;
- firing its last round of [`Ammo`](/keys/ammo/) sets fear to `255`, and an Attack or Hunt mission changes to Guard.

An armed `Fraidycat=yes` soldier therefore stops fighting when its clip is empty. It reloads a full clip once its fear has fallen back to `0`.

While its fear is above `10`, a `Fraidycat=yes` soldier that stands still with no destination scatters on every logic frame. A computer-owned one also scatters in place of an idle animation while its fear is above `10`, and on one idle animation in eleven even with no fear at all.

A `Fraidycat=yes` soldier also obeys scatters that other soldiers ignore, including while it holds a target or is moving. It still ignores them during a mission with [`Scatter=no`](/keys/scatter/#scope-mission-behavior). A human player's one outside a team obeys them only when [`PlayerScatter`](/keys/playerscatter/) is on or it has earned the scatter ability.

:::caution[A human player cannot make a prone one get up]
A prone soldier owned by a human player normally stands up and runs when it is ordered twice to the same destination. A `Fraidycat=yes` soldier stays prone, as a [`Cyborg=yes`](/keys/cyborg/) one does.
:::

:::caution[Do not combine `Fraidycat=yes` with `Fearless=yes`]
Both panic cases set fear without checking [`Fearless=yes`](/keys/fearless/). Fear then never falls, because a `Fearless=yes` type skips both the per-frame recovery and the [Unpanic](/mapping/missions/tmission-unpanic/) team mission. A type that sets both flags stays panicked from its first hit.
:::
