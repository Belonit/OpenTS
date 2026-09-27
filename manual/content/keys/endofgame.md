---
key: EndOfGame
summary: Whether winning this mission closes the campaign with its ending movie and credits.
see_also: [OneTimeOnly, SkipMapSelect, PreMapSelect]
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
EndOfGame=yes
```

Winning a mission that sets this key ends the campaign. The campaign's closing movie, set by [`FinalMovie`](/keys/finalmovie/), plays, the credits roll, and the game returns to the main menu without advancing to another mission. This happens after the score screen, if the mission shows one, and after the mission's [`PostScore`](/keys/postscore/) and [`PreMapSelect`](/keys/premapselect/) movies.

The closing movie belongs to the campaign, not to the mission, so it plays only when the mission was started as part of a campaign. A mission outside a campaign still rolls the credits and returns to the main menu, but shows no movie first.

[`OneTimeOnly`](/keys/onetimeonly/) takes precedence. A mission that sets both returns to the main menu with neither the movie nor the credits.

Multiplayer and skirmish games end before this key is checked, so it has no effect there.
