---
key: Action
scope: scenarios
label: Scenario movie
see_also: [Intro, Brief, Theme, PostScore]
when_omitted:
  kind: value
  value: "<none>"
---

```ini title="map file"
[Basic]
Action=NOD_M04
Theme=APPROACH
```

The movie plays just before the mission begins. It follows the mission's briefing, either the [`Brief`](/keys/brief/) movie or the objectives screen, and the dropship loadout screen if the mission has one. It plays only on a fresh start. A restart from the menu or a replay after a loss skips it.

The movie queues the mission's [`Theme`](/keys/theme/) track as it opens. If the `Theme` track is already playing behind the objectives screen, it fades out before the movie. A mission that names no action movie queues its `Theme` at the same point instead.

If the movie does not play, the mission starts with a track from normal rotation. This happens on a restart, when the movie's file is missing, and in a multiplayer or skirmish game launched without movies.

[`Theme`](/keys/theme/) covers what happens to the track once the movie ends. [`Intro`](/keys/intro/) covers how a movie name is resolved and what happens to one that cannot be found.
