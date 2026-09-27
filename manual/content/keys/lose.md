---
key: Lose
summary: The movie played when the player loses the mission.
see_also: [Win, Intro]
when_omitted:
  kind: value
  value: "<none>"
---

```ini title="map file"
[Basic]
Lose=KILLMECH
```

In a campaign, the movie plays once the defeat announcement has finished speaking, or after five seconds if it is still speaking. The game then offers to replay the mission. A replay restarts the scenario without its briefing, so [`Intro`](/keys/intro/), [`Brief`](/keys/brief/) and [`Action`](/keys/action/#scope-scenarios) do not play again.

In skirmish and multiplayer games, the movie plays after the score screen, or straight after the announcement when the score screen is skipped. It plays only when the launch file asks for movies. [Multiplayer movies](/systems/multiplayer-movies/) covers that path.

[`Intro`](/keys/intro/) covers how a movie name is resolved and what happens to one that cannot be found.
