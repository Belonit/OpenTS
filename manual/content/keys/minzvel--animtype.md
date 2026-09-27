---
key: MinZVel
scope: animtype
label: Animation launch speed
see_also: ["MaxXYVel", "Bouncer", "IsMeteor"]
when_omitted:
  kind: value
  value: "3.5"
---

The value is in leptons per game frame, and a cell is 256 leptons across. A [`Bouncer=yes`](/keys/bouncer/) animation is thrown upward at this speed plus a random whole number, so the setting is its slowest launch speed.

The number of possible launch speeds is the whole-number part of the gap between the setting and `4.5`, a figure no animation type key changes:

| Setting | Launch speeds |
| --- | --- |
| `3.5` (the default) | exactly `3.5` every time |
| `0` | `0` to `3` |
| `20` | `20` to `34` |
| `40` | `40` to `74` |

Below `3.5`, speeds run from the setting up to at most `3.5`. Above `5.5`, the range widens as the setting grows.

A meteor drops 1.4 leptons per frame more than this value, with no random part. The value decides where the meteor comes from and how far short of its target it lands, as [`IsMeteor`](/keys/ismeteor/#scope-animtype) describes.

:::danger[A value between 3.5 and 5.5 crashes the game]
A value above `3.5` and below `5.5` leaves the random range empty and causes a division by zero. The game crashes when a `Bouncer=yes` animation of the type is created. An `IsMeteor=yes` animation draws no random vertical speed and is unaffected.
:::
