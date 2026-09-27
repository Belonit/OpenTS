---
key: Intro
summary: The first movie a mission plays when it starts fresh, ahead of its briefing movie.
see_also: [Brief, Action, Win, Lose, PostScore, PreMapSelect]
when_omitted:
  kind: value
  value: "<none>"
---

```ini title="map file"
[Basic]
Intro=INTRO
Brief=GDI_M02
```

The value is a movie name from the art file's `[Movies]` list, not a filename; the engine adds `.VQA` to find the file. `<none>`, an empty value, and a name the list does not contain all leave the mission without an intro movie.

The movie plays after the map is read and just before [`Brief`](/keys/brief/), and only when the mission starts fresh. Replaying a mission after a loss, or restarting it from the menu, skips both movies. In skirmish and multiplayer games, the movie plays only when the [launch file](/formats/spawn-ini/) turns on `PlayMoviesInMultiplayer`.

The movie is skipped when its file is missing, or when its picture is both narrower than 320 pixels and shorter than 200.

Keep names registered in `[Movies]` to fifteen characters or fewer. A longer name overruns the buffer the filename is built in when the movie plays; [VQA video](/formats/vqa/) describes the overrun.
