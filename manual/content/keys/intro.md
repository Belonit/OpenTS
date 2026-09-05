---
key: Intro
summary: The movie played first when a campaign mission is started with its briefing.
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

The value names an entry of the art file's `[Movies]` list rather than a file. The engine applies the [movie lookup order](/systems/movie-playback/#finding-and-opening-a-movie) to the registered name. `<none>`, an empty value, and any name the list does not carry all leave the setting as it was, which is what omitting the key does too.

The movie runs once the scenario has been read and just before [`Brief`](/keys/brief/), and only when the mission was started fresh. A mission replayed after a loss or restarted from the menu passes over both. Movies are never played outside a campaign, and a registered name with no supported movie file, or whose picture is both narrower than 320 and shorter than 200, is skipped in silence.
