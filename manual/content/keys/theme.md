---
key: Theme
summary: The music track a mission starts with.
see_also: [Action, Intro]
when_omitted:
  kind: value
  value: "No theme"
---

```ini title="map file"
[Basic]
Action=NOD_M04
Theme=APPROACH
```

The value names a music track declared in [the theme control file](/formats/theme-ini/). The mission normally opens with that track, and when it ends, normal track rotation picks the next allowed track.

When the track starts, and whether it plays, depends on how the mission begins:

- **Written briefing.** A campaign mission that shows its written briefing on a fresh start, as described under [`Brief`](/keys/brief/), starts the track on that page.
- **With an action movie.** When the mission names an [`Action`](/keys/action/#scope-scenarios) movie, a track playing on the briefing page fades out before the movie. The movie queues the track as it opens, and the track starts once the mission is under way.
- **When the action movie does not play.** The mission starts with the next track in rotation. The movie does not play on a restart, when its file is missing or cannot be played, and outside a campaign unless the launch file asked for movies.
- **Without an action movie.** The track is queued as the mission begins, on a restart too, and starts once the mission is under way. A track that started on the briefing page keeps playing only if it repeats, through its [`Repeat`](/keys/repeat/) setting or the repeat option on the sound options screen. Otherwise it fades out as the mission begins and the next track in rotation follows.

:::caution[A partial title can select a different track]
The name is matched against each track's identifier first, ignoring case. If that fails, it is matched as text within each track's displayed title, with case respected, and the first track whose title contains it wins. A name that matches neither selects no track, which is the same as leaving the key out.
:::
