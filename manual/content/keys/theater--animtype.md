---
key: Theater
scope: animtype
label: Theater-specific animation artwork
see_also: ["NewTheater", "Image"]
when_omitted:
  kind: value
  value: "no"
---

The animation's shape file is named after its AnimType ID, with the extension set by the scenario theater's [`Suffix`](/keys/suffix/#scope-theater) in place of `.SHP`. By default that is `.TEM` in temperate and `.SNO` in snow.

```ini title="art.ini"
[MYBLAST] ; an AnimType ID
Theater=yes ; draws MYBLAST.TEM or MYBLAST.SNO
```

When the theater's file is missing, the animation draws `<AnimType ID>.SHP` instead. That fallback applies when the scenario's theater differs from the previous scenario's, and after a saved game loads. The animation draws nothing in that theater in two cases:

- The scenario repeats the previous scenario's theater.
- The animation sets [`DemandLoad=yes`](/keys/demandload/#scope-animtype).

The file is looked up again for every scenario and every loaded saved game, so its extension always matches the current theater.

An animation that also sets [`NewTheater=yes`](/keys/newtheater/#scope-animtype) uses this flag and ignores that one.

:::caution[Leave Image= unset on a theater animation]
With an [`Image=`](/keys/image/#scope-animtype) that differs from the AnimType ID, the name the theater file is looked up under can depend on the previous scenario. When the theater differs from the previous scenario's, or a saved game is loaded, the lookup uses the AnimType ID. When the theater repeats, it uses the Image ID. A [`DemandLoad=yes`](/keys/demandload/#scope-animtype) animation always uses the AnimType ID.
:::
