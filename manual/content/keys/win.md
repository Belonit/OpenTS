---
key: Win
summary: The movie played when a campaign mission is won.
see_also: [Lose, SkipScore, PostScore, Intro]
when_omitted:
  kind: value
  value: "<none>"
---

```ini title="map file"
[Basic]
Win=UNSTPBLE
Lose=KILLMECH
```

In a campaign, the movie is the first thing shown once the mission has been won, before the score screen and everything that follows it.

In a multiplayer or skirmish game, the movie plays after that game's own score screen, and only when the launch file asked for movies. [Multiplayer movies](/systems/multiplayer-movies/) covers that case.

[`Intro`](/keys/intro/) covers how a movie name is resolved and what happens to one that cannot be found.
