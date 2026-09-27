---
key: Root
scope: theater
label: Theater archive root
see_also: [IsoRoot, Suffix]
when_omitted:
  kind: context-dependent
  note: "`TEMPERAT` for TEMPERATE and `SNOW` for SNOW, which keep their original settings; for any other theater, the theater's own name."
---

`Root` names three theater files:

- `<Root>.MIX`, the theater's main archive
- `<Root>.PAL`, the theater palette
- `<Root>.INI`, the [theater control file](/formats/theater-control/), which lists the theater's tile sets

```ini title="rules.ini"
[DESERT]
Root=DESERT     ; DESERT.MIX, DESERT.PAL and DESERT.INI
```

The game reads up to 16 characters of the value and cuts a longer one short.

A theater with no `<Root>.PAL` still loads in a Release build, which substitutes a placeholder gradient palette. A Debug build stops at an assertion first.

A theater with no `<Root>.INI` has no tile sets, so give every theater a control file.
