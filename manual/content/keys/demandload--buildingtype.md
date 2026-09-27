---
key: DemandLoad
scope: buildingtype
label: Structure shape
see_also: ["DemandLoadBuildup", "Image", "Theater"]
when_omitted:
  kind: value
  value: "no"
---

With `DemandLoad=yes`, a structure type's main shape is not loaded with the rules. The game records the [main-shape filename](/keys/image/#scope-buildingtype), resolved for the current theater, and loads the file the first time the shape is needed, usually to draw a structure of the type. A type nothing uses loads nothing, and a shape the game cannot find is not drawn.

The loaded shape is released when any of these happens:

- the type's rules are read again;
- the type is destroyed;
- a theater is set up and the type is [`Theater=yes`](/keys/theater/) or [`NewTheater=yes`](/keys/newtheater/).

The next use loads it again.

The flag covers only the main shape. The construction animation has its own setting, [`DemandLoadBuildup`](/keys/demandloadbuildup/). The deploying, door, under-door, bib and special Z overlay shapes are always loaded with the rules.
