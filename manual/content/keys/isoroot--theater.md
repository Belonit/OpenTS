---
key: IsoRoot
scope: theater
label: Theater tile archive root
see_also: [Root, Suffix]
when_omitted:
  kind: context-dependent
  note: "`ISOTEMP` for TEMPERATE and `ISOSNOW` for SNOW, which keep their original settings; for any other theater, the theater's own name."
---

`IsoRoot` names the archive `<IsoRoot>.MIX`, which the game opens together with the theater's other two archives, `<Root>.MIX` from [`Root`](/keys/root/) and `<Suffix>.MIX` from [`Suffix`](/keys/suffix/#scope-theater). The original theaters keep their isometric tile artwork in it.

```ini title="rules.ini"
[DESERT]
IsoRoot=ISODES  ; ISODES.MIX
```

The game reads up to 16 characters of the value and cuts a longer one short.
