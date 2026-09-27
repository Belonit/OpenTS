---
key: Official
scope: scenarios-2
label: Starting-point selection
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
Official=yes
```

`Official=yes` limits which of the placed waypoints `0` through `7` can be [start positions](/systems/starting-forces/#the-start-position) in a multiplayer or skirmish game. Only placed waypoints numbered below a cutoff are eligible. The cutoff is the larger of these two numbers:

- the number of playing houses;
- the number of waypoints placed in an unbroken run starting at `0`.

With `Official=no`, every placed waypoint from `0` to `7` is eligible.

For example, take a map with waypoints `0`, `1`, `2`, `5` and `6` placed, played by four houses. With `Official=yes` the cutoff is 4, so only `0`, `1` and `2` are eligible and the fourth house starts on open ground. With `Official=no`, all five waypoints are eligible.

The limit does not apply when any playing seat in the [launch file](/formats/spawn-ini/#who-is-playing) names a start position. Every placed waypoint is then eligible. A generated random map counts as `Official=yes`, whatever its file sets.

[The start position](/systems/starting-forces/#the-start-position) covers how houses choose among the eligible waypoints.

:::danger[Leave open ground for houses without a waypoint]
A house left without an eligible waypoint needs open ground (see [the start position](/systems/starting-forces/#the-start-position)). The game searches until it finds some, so on a map without it the scenario never finishes loading.
:::
