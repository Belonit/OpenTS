---
key: Sound
scope: themes
label: Track file
see_also: [Name, Volume]
when_omitted:
  kind: computed
  note: The track's ID, which is also its section name.
---

`Sound=` names the file the music track plays, without an extension. The game looks for the name with `.WAV`, `.OGG`, `.FLAC`, `.MP3` and `.AUD` in that order and uses the first file it finds, as a loose file in the game directory or as a member of a mounted archive. [AUD audio](/formats/aud/) explains where the game looks.

```ini title="theme01.ini"
[Themes]
30=MYTHEME

[MYTHEME]
Name=Example theme
Sound=MYSONG
```

Here the track's ID stays `MYTHEME`, so triggers, scenarios and other tracks keep naming it that way, and the game plays the first `MYSONG` file it finds, such as `MYSONG.OGG`. Two tracks can name the same file. When no file with any of the extensions exists, the track is not available and is never played.
