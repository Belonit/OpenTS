---
key: OneTimeOnly
summary: Whether winning this mission ends the session instead of advancing the campaign.
see_also: [EndOfGame, SkipMapSelect, NextScenario]
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
OneTimeOnly=yes
```

Winning a campaign mission that sets `OneTimeOnly=yes` ends the game. The player returns to the main menu, or the game exits if a client launched it. The score screen and the [`PostScore`](/keys/postscore/) and [`PreMapSelect`](/keys/premapselect/) movies still play first. The campaign does not advance: there is no map selection, no next mission, and no closing movie.

:::caution[Do not combine it with EndOfGame]
A mission that sets both `OneTimeOnly` and [`EndOfGame`](/keys/endofgame/) ends as a `OneTimeOnly` mission. The campaign's closing movie and the credits never play.
:::
