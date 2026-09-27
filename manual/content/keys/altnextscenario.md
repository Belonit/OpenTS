---
key: AltNextScenario
summary: The mission the campaign advances to instead, when the second global flag is set.
see_also: [NextScenario, SkipMapSelect]
when_omitted:
  kind: context-dependent
  note: The name the game already holds. It comes from the most recent mission that set this key, or from a loaded save, and is empty until one of those sets it.
---

```ini title="map file"
[Basic]
SkipMapSelect=yes
NextScenario=Maps/Missions/GDI2A.MAP
AltNextScenario=Maps/Missions/GDI9C.MAP
```

The campaign advances to this mission in place of [`NextScenario`](/keys/nextscenario/) when global flag `1` is set at the moment the player wins. A campaign can use it to fork on something the player did, because any trigger that sets global flag `1` before the win redirects the advance.

:::caution[Clear global flag 1 in a mission that should not fork]
Global flags [carry over](/systems/campaign-progression/#what-survives-the-boundary) from one campaign mission to the next, so flag `1` set in an earlier mission still redirects the advance. [Clear it](/mapping/actions/taction-clear-global/) before the win in any mission that should advance to `NextScenario`. Otherwise the campaign advances to this key's mission, or, when this mission omits the key, to the name an earlier mission set, which may be empty.
:::

The key applies only where [`NextScenario`](/keys/nextscenario/) does, after a won mission that sets [`SkipMapSelect`](/keys/skipmapselect/). A mission that shows the map selection screen ignores both keys.

[`NextScenario`](/keys/nextscenario/) covers how the name is resolved against the campaign's progression data and what happens when it matches nothing.
