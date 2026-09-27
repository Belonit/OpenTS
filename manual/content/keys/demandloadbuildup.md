---
key: DemandLoadBuildup
summary: Defers loading the structure's construction artwork until a structure of the type is first created.
see_also: ["Buildup", "FreeBuildup", "DemandLoad"]
when_omitted:
  kind: value
  value: "no"
---

With `DemandLoadBuildup=yes`, the file [`Buildup=`](/keys/buildup/) names is not loaded with the rules. The game loads it the first time a structure of the type is created. Unless `FreeBuildup=yes` releases it sooner, the type keeps that copy until its rules are read again, the type is destroyed, or a theater is set up for a [`Theater=yes`](/keys/theater/) or [`NewTheater=yes`](/keys/newtheater/) type. Without the flag, the file is loaded with the rules and loaded again on those theater setups.

The deferred load always looks for the name rewritten for the theater by the structure-art convention, with a `.SHP` extension, whatever the type's theater settings say. A `Theater=yes` structure that sets this flag therefore does not look for a file with the theater's own extension. The deferred load also times the animation the ordinary way `Buildup=` describes, spreading [`BuildupTime`](/keys/builduptime/) over the steps. The five-second timing of a `Theater=yes` type does not apply.

[`FreeBuildup=yes`](/keys/freebuildup/) releases only construction artwork loaded this way. Without `DemandLoadBuildup=yes`, `FreeBuildup=yes` has no effect.
