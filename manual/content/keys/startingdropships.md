---
key: StartingDropships
summary: How many dropships the player fills before a campaign mission begins.
see_also: [AllowableUnits, AllowableUnitMaximums]
when_omitted:
  kind: value
  value: "0"
---

```ini title="map file"
[Basic]
StartingDropships=2
```

Any value above zero opens the dropship loadout screen after the briefing and before the action movie. Each dropship holds five units, and the units the player picks fill the player's three dropship loadouts in order. Zero skips the screen, which is what nearly every mission does.

[`AllowableUnits`](/keys/allowableunits/) decides what the screen offers.

:::danger[Keep the value at 3 or below]
The screen has pictures and slot positions for one to three dropships only. A value of 4 or more reads past the end of both tables, and any units chosen for a fourth dropship are written past the end of the player's three loadouts.
:::

The mission's triggers deliver the loadouts as reinforcements. A reinforcement whose task force is a single `DSHP` entry arrives as a loaded dropship. Each dropship reinforcement moves that house on to its next loadout, even when the team then cannot be created and nothing arrives. A refused one, described below, does not. After a house's third delivery, a `DSHP` reinforcement is sent as an ordinary reinforcement with no cargo.

The player's next loadout decides whether a dropship arrives and how many units it carries, whichever house it is sent for:

- While the player's next loadout is empty, the reinforcement is refused.
- Otherwise the dropship carries one unit per unit in the player's next loadout, taken from the loadout of the house it is sent for.

A dropship sent for the player therefore carries exactly what the player chose. Only the player's house has loadouts.

:::danger[Send dropship reinforcements only for the player]
A `DSHP` reinforcement sent for any other house while the player's next loadout holds units crashes the game.
:::
