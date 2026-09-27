---
key: Suffix
scope: theater
label: Theater artwork extension
see_also: [MMSuffix, Root, IsoRoot]
when_omitted:
  kind: context-dependent
  note: "`TEM` for TEMPERATE and `SNO` for SNOW, which keep their original settings; empty for any other theater, which then looks for artwork under no extension at all and has no unit remap palette."
---

`Suffix` is the file extension of the theater's own artwork. A type marked [`Theater=yes`](/keys/theater/#scope-aircrafttype) loads `<name>.<Suffix>`, and so does each tile of a [tile set](/formats/theater-control/).

The same value names five more files:

| File | What it holds |
| --- | --- |
| `<Suffix>.MIX` | The theater's second archive |
| `ISO<Suffix>.PAL` | The palette the tiles are drawn through |
| `UNIT<Suffix>.PAL` | The palette unit and structure color schemes are built from |
| `SLOP01Z.<Suffix>` through `SLOP04Z.<Suffix>` | The depth shapes for sloped ground |
| `VEINHOLE.<Suffix>` | The veinhole monster's artwork |

```ini title="rules.ini"
[DESERT]
Suffix=DES      ; TREE01.DES, DES.MIX, ISODES.PAL, UNITDES.PAL
```

A suffix may be longer than the three characters the original theaters use. The game reads up to 8 characters and cuts a longer value short.
