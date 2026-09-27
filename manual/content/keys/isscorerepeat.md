---
key: IsScoreRepeat
summary: Repeats the playing music track instead of moving on to the next one.
see_also: [IsScoreShuffle, ScoreVolume]
when_omitted:
  kind: value
  value: "no"
---

`IsScoreRepeat=yes` plays the current music track again each time it ends, until something else changes the music. A track whose theme entry sets [`Repeat=yes`](/keys/repeat/) repeats even with this off. [Choosing the next track](/systems/music/#choosing-the-next-track) describes what can still interrupt a repeating track.

While this is on, [`IsScoreShuffle`](/keys/isscoreshuffle/) affects only the first track after silence, because each track that ends plays again.

The sound options dialog shows repeat and shuffle as two check boxes, and checking one clears the other. A file that sets both is read as written, and both take effect. Both settings are written to `sun.ini` when the player leaves the options menu or, during a game, closes the game controls dialog with OK.
