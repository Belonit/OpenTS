---
key: MMSuffix
scope: theater
label: Theater marble madness extension
see_also: [Suffix, NonMarbleMadness]
when_omitted:
  kind: context-dependent
  note: "`MMT` for TEMPERATE and `MMS` for SNOW, which keep their original settings; empty for any other theater, which then makes no second attempt."
---

`MMSuffix` is the extension tried when a tile's own artwork is missing. The game first looks for the tile under the theater's [`Suffix`](/keys/suffix/#scope-theater). If that file does not exist, it tries the same name with this extension. This lets marble madness tile artwork stand in for tiles the theater does not draw itself.

```ini title="rules.ini"
[DESERT]
MMSuffix=MMD    ; RVCLIF01.MMD, tried after RVCLIF01.DES
```

The second attempt is skipped when the tile's set has [`NonMarbleMadness=0`](/keys/nonmarblemadness/), or when the theater has no `MMSuffix`. A tile found under neither extension has no artwork.

The game reads up to 8 characters of the value and cuts a longer one short.
