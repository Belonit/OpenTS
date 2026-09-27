---
key: SkipMapSelect
summary: Whether the campaign advances straight to a named mission instead of offering the map screen.
see_also: [NextScenario, AltNextScenario, OneTimeOnly, EndOfGame]
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
SkipMapSelect=yes
NextScenario=Maps/Missions/GDI2A.MAP
AltNextScenario=Maps/Missions/GDI9C.MAP
```

With `SkipMapSelect=yes`, winning the mission skips the map selection screen. The campaign advances to [`NextScenario`](/keys/nextscenario/), or to [`AltNextScenario`](/keys/altnextscenario/) when global variable 1 is set. At the default, the map selection screen opens and the player chooses the next mission.

The named map must be one of the next missions the campaign's map selection data offers from the current stage, and the campaign moves to that stage. [`NextScenario`](/keys/nextscenario/) covers what happens when the name is not among them.

A mission that also sets [`OneTimeOnly`](/keys/onetimeonly/) or [`EndOfGame`](/keys/endofgame/) ends the campaign instead, and this key has no effect.
