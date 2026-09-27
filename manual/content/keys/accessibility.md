---
key: Accessibility
summary: The chance that neighboring pieces of high and low ground are joined by more than one ramp, as a figure from 0 to 100.
see_also: [RegionSize, Ruggedness]
when_omitted:
  kind: value
  value: "0"
  note: Every pair of neighboring regions at different heights aims for a single ramp and never more.
---

`Accessibility` sets how often a generated map joins high and low ground with extra ramps. The generator splits the map into regions of ground at one height. For each pair of neighboring regions at different heights, it aims for one ramp. With a chance of about `Accessibility` percent, rolled once per pair, it aims for two or three instead, each equally likely. At `100` almost every pair aims for two or three. [Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="map seed file"
[RandomMap]
Accessibility=75
```

A pair can end with fewer ramps than the generator aimed for. Each ramp is carved around a cell picked at random from the higher region's border, and a ramp shape must fit the ground there. The generator makes up to 100 picks per pair. A pick outside the playable area is skipped but still counts toward the 100. From the 52nd pick on, it also accepts one of the four straight ramps at a fixed position around the picked cell when no shape fits. A pair that still has no ramp after 100 picks is left without a direct ramp between its two regions, and the generator does not repair it.

Water is joined differently and ignores `Accessibility`. A region of water gets bridges between the dry regions on its banks, but only where both banks stand at the water's height and each bank borders another region besides the water or covers more than 50 cells.

When a map is [generated from a file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `100` becomes `100`.
