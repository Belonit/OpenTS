---
key: UnitCount
summary: Starting figure for the unit count a multiplayer or skirmish match opens with.
see_also: [AllowedToStartInMultiplayer, BaseUnit, Bases, "system:starting-forces"]
when_omitted:
  kind: value
  value: "10"
---

`UnitCount` is the figure the unit count slider starts at the first time a skirmish or network setup screen opens after the game starts. Later setup screens start at the count last used: that of the last skirmish started, or wherever the slider was last set in a network lobby. A skirmish uses the count set on its setup screen.

The slider runs from `1` to `10`. Keep `UnitCount` in that range. The setup screens bring the figure into range when the player moves the slider, and an out-of-range figure may reach the match if the player does not.

A match started from a launch file takes its unit count from the [launch file's `UnitCount`](/formats/spawn-ini/#the-options-every-house-plays-under) and ignores this one.

The unit count is not a number of objects. Each house gets a budget of the unit count times the average price of the vehicle and infantry types [allowed to start](/keys/allowedtostartinmultiplayer/), and spends it one object at a time. When bases are enabled and a [`BaseUnit`](/keys/baseunit/) is listed, the count is reduced by one first to pay for the base unit each house is placed with. [Starting forces](/systems/starting-forces/#the-budget) explains the average and the order the budget is spent in.
