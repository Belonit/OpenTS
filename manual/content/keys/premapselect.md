---
key: PreMapSelect
summary: The movie played on the way from a won campaign mission to the next map choice.
see_also: [PostScore, SkipMapSelect, OneTimeOnly, Intro]
when_omitted:
  kind: value
  value: "<none>"
---

```ini title="map file"
[Basic]
PreMapSelect=GDI_M11
```

The movie plays after [`PostScore`](/keys/postscore/) and before the campaign moves on. It plays even when the mission skips the map selection screen with [`SkipMapSelect`](/keys/skipmapselect/), or ends the campaign with [`OneTimeOnly`](/keys/onetimeonly/) or [`EndOfGame`](/keys/endofgame/).

[`Intro`](/keys/intro/) covers how a movie name is resolved and what happens to one that cannot be found.
