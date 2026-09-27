---
key: Brief
summary: The mission briefing movie, replayable from the objectives screen.
see_also: [Intro, Action, Win, Lose, PostScore, PreMapSelect]
when_omitted:
  kind: value
  value: "<none>"
---

```ini title="map file"
[Basic]
Brief=GDI_M02
```

The movie plays directly after [`Intro`](/keys/intro/) when a mission is started fresh. A restart from the menu or a replay after a loss skips it.

The objectives screen offers the movie again during the mission. When a briefing movie is named, the screen shows a second button beside the resume button. That button stops the current music track, replays the movie, and then starts the same track again. With no briefing movie, the resume button sits alone in the center.

The screen fades the written briefing in a line at a time. A briefing longer than one page shows a More button below each page but the last. Space, Enter, Escape or a click during the fade finishes the page at once. On a finished page, Space, Enter or Escape does what More or the resume button does.

A campaign mission with no briefing movie shows the objectives screen at the start instead. The same happens when the movie's file is missing, although the replay button still appears and then plays nothing. The mission's [`Theme`](/keys/theme/) track plays behind the screen. This screen appears only on a fresh start, not on a restart or a replay after a loss.

A name missing from the art file's `[Movies]` list has the same effect as omitting the key. [`Intro`](/keys/intro/) covers how a movie name is resolved and what happens to one that cannot be found.
