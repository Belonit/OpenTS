---
key: FinalMovie
summary: The movie that plays once a campaign's closing mission is won.
see_also: ["Scenario", "Description", "CD", "EndOfGame"]
when_omitted:
  kind: value
  value: none
---

The movie plays after a mission with [`EndOfGame=yes`](/keys/endofgame/) is won, just before the credits. A mission that also sets [`OneTimeOnly=yes`](/keys/onetimeonly/) ends the game before that point, so neither this movie nor the credits play.

The value must be a movie name registered in the `[Movies]` section of `ART.INI` or `ARTFS.INI`, matched in any letter case. The game plays the registered name with `.VQA` appended, so a custom movie plays once its name is registered there ([registering a movie](/formats/vqa/#registering-a-movie)).

A name that is not registered, `<none>` included, leaves the setting unchanged. The campaign keeps a movie that an earlier battle file set for it, or has none. With no movie, the won mission goes from its after-mission movies straight to the credits.
