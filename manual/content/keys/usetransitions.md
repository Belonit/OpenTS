---
key: UseTransitions
summary: Loads the hour file for a generated map's hour, whose triggers can change the map's lighting during play.
see_also: [Time, UseIonStorms, Biome]
when_omitted:
  kind: value
  value: "no"
  note: No hour file is loaded, and each start point gets the number of floodlights its hour gives.
---

With `UseTransitions=yes`, the generator loads the hour file for the hour [`Time`](/keys/time/) names. The flag does not change the map's ambient lighting; the triggers in that file do. [Map seed files](/formats/map-seed/) covers the section it is written in.

| `Time` | Hour file |
| --- | --- |
| `0` morning | `MORNING.INI` |
| `1` afternoon | `DAY.INI` |
| `2` dusk | `DUSK.INI` |
| `3` night | `NIGHT.INI` |

```ini title="map seed file"
[RandomMap]
Time=1
UseTransitions=yes
```

The map takes two things from the hour file:

- its trigger types and tag types, which are added to the map;
- its local variables from `[VariableNames]`, which replace any the map already had.

The flag also sets every start point's floodlight ring to four lights, whatever the hour; [Floodlights](/systems/map-generation/#floodlights) gives the placement conditions. Each light is attached to the tag type named `Light On/Off`, so the hour file's triggers can switch the lights. Define a tag type named `Light On/Off` in each hour file. Without it, each light gets a tag with no type, and the game can crash.

Without the Firestorm addon, the flag is turned off before any map is built, whether it comes from a seed file or the dialog. The dialog shows its check box only with Firestorm, and its randomize button checks the box about half the time.
