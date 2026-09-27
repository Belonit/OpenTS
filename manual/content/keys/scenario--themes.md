---
key: Scenario
scope: themes
label: Track unlock level
see_also: [Normal, Side]
when_omitted:
  kind: value
  value: "0"
---

`Scenario=` holds the music track back until a single-player game reaches this [campaign level number](/systems/campaign-progression/#the-campaign-level-number). The track is allowed once the number is equal to or higher than the value. The number is `1` when the game starts and goes up by one with each campaign mission won, so `Scenario=3` allows the track from the third mission of the first campaign played after the game starts. A campaign started later in the same run can begin with a higher number and allow the track sooner.

```ini title="theme.ini"
[VALVES1B]
Name=Valves
Length=3.27
Scenario=1
```

A track held back is missing from the automatic playlist and from the sound options track list, and the [next track](/commands/nexttheme/) and [previous track](/commands/prevtheme/) commands skip it. Other ways of starting the track, listed under [`Normal`](/keys/normal/), still play it.

Skirmish and multiplayer games skip the test, so this key holds back no track there.
