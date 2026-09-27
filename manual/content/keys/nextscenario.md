---
key: NextScenario
summary: The mission the campaign advances to when this one skips the map selection screen.
see_also: [AltNextScenario, SkipMapSelect, OneTimeOnly]
when_omitted:
  kind: context-dependent
  note: The name the game already holds, which carries over from mission to mission. It comes from the most recent mission that set this key, or from a loaded save, and is empty until one of those sets it.
---

```ini title="map file"
[Basic]
SkipMapSelect=yes
NextScenario=Maps/Missions/GDI2A.MAP
```

The name is used only when the won mission sets [`SkipMapSelect=yes`](/keys/skipmapselect/) and global variable `1` is clear. When that variable is set, [`AltNextScenario`](/keys/altnextscenario/) is used instead.

The game does not load the named file directly. It compares the name, ignoring case, with the scenario of each stage the current stage leads to, and advances the campaign to the first match. Write the same path the progression data records for that stage. [Campaign progression](/systems/campaign-progression/#campaigns-and-stages) covers where that data lives.

:::caution[Name a stage the current stage leads to]
A name that matches none of those stages shows an error box, and the campaign continues with its first mission instead of the map selection screen. [When the choice fails](/systems/campaign-progression/#when-the-choice-fails) covers this case and the related failures that reload the mission just won.
:::
