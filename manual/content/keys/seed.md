---
key: Seed
summary: The number the map generator's random sequence is started from.
see_also: [NumPlayers, Width, Height]
when_omitted:
  kind: value
  value: "-1"
  note: A seed file without `Seed` builds the map `Seed=0` gives.
---

Every random choice the map generator makes comes from one sequence started from `Seed`. The same settings and game data with the same seed build the same map, cell for cell, and a different seed builds a different layout. [Map seed files](/formats/map-seed/) covers the section the key is written in.

```ini title="map seed file"
[RandomMap]
Seed=12345
Width=1
Height=1
NumPlayers=4
```

Before a map is built, `Seed` is held to `0` through `65535`: a negative value becomes `0`, and a value above `65535` becomes `65535`. This happens whether the file is loaded into the map generator dialog or played as a scenario.

:::caution[`-1` does not draw a new seed]
`-1` becomes `0` like any other negative value, so a seed file with `Seed=-1` builds the `Seed=0` map every time. Write a different number to get a different map.
:::

The map generator dialog has no seed control. It uses the seed it already holds, which starts at `0`, changes to a new number from `0` through `65535` each time **Surprise Me** is pressed, and comes from the file when saved settings are loaded. Saving the settings writes that seed to the file.

**Surprise Me** also picks new values for the other settings, so the dialog cannot change the seed alone. To try a new seed with the same settings, save them, change `Seed` in the saved file and load it again.

A scenario file with [`RandomMap=yes`](/keys/randommap/) ignores `Seed` and builds its map from the match's seed.
