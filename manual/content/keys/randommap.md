---
key: RandomMap
summary: Builds the scenario's map with the random map generator instead of reading it from the file.
see_also: [Seed, NumPlayers, FreeRadar]
when_omitted:
  kind: value
  value: "no"
---

With `RandomMap=yes` in a scenario file's `[Basic]` section, the [random map generator](/systems/map-generation/) builds the map. The generator takes its settings from the file's `[RandomMap]` section, which uses the same keys as a [map seed file](/formats/map-seed/). A setting the section leaves out takes its default, and a value outside a setting's allowed range is moved to the nearest limit. Some settings also change with whether the Firestorm expansion is enabled; [missing and out-of-range settings](/formats/map-seed/#missing-and-out-of-range-settings) lists them.

```ini title="map file"
[Basic]
Name=Random desert
RandomMap=yes
FreeRadar=yes

[RandomMap]
Width=2
Height=2
NumPlayers=2
Biome=3         ; desert

[MCV]           ; a rules section, applied to this match
Speed=5
```

The file's other sections are still read. Rules sections such as `[MCV]` above change the rules for the match, and `[Basic]` settings such as [`FreeRadar`](/keys/freeradar/) work as on an ordinary map.

The generator places the start points and replaces these values, whatever the file gives for them:

- `Theater`, `Size`, `LocalSize`, `Level` and `Fill` in `[Map]`;
- `Ambient`, `Red`, `Green`, `Blue`, `Ground` and `Level` in `[Lighting]`;
- `Player` in `[Basic]`, which it sets to the first house type (GDI in the shipped rules), and that house's `TechLevel`, which it sets to `0`.

The map is built from the match's seed, not from the `[RandomMap]` section's [`Seed`](/keys/seed/). In a [game against other machines](/formats/spawn-ini/#a-game-against-other-machines), every machine takes the seed from its launch file, so all of them build the same map. In a skirmish or a campaign mission, a nonzero launch-file `Seed` builds the same map at every launch, and `0` draws a new seed each time. Without a launch file, the seed and so the map change from one match to the next.

A `.SED` seed file needs no `RandomMap` key. It is always generated, from its own `Seed`, so it builds the same map every time.
