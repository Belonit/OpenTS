---
key: Description
scope: random-map-generation
label: Saved map name
see_also: [Seed, NumPlayers]
when_omitted:
  kind: context-dependent
  note: The name the language files give a random map, so the text follows the language the game is running in.
---

The text is the name a saved map seed is listed under in the load, save and delete dialogs. Saving a seed writes the description the player types in the save dialog. At most 127 characters are kept; a longer value is cut. [Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="MyMap.SED"
[RandomMap]
Description=Four player temperate map
```

When a player sets up a game on a map generated from a loaded seed, their game setup screen shows this text as the scenario name. Players who join them over the network see the language's name for a random map instead.

A seed file whose `Description` is missing or empty appears in the dialogs as a blank row. Loading it still works, and the loaded seed is then described by the language's name for a random map. Saving onto a blank row writes a new file and leaves the old one in place.

`RandMap.Sed`, the file the game writes for the generated map being played, is never listed.

The text does not affect the map that is built. It is left out of the identifier that network games use to match maps, so changing a seed's description does not make it a different map.
