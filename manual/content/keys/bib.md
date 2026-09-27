---
key: Bib
summary: Opens the eastern edge of the structure's footprint to vehicles.
see_also: [BibShape, Foundation, Harvester, Refinery, Weeder]
when_omitted:
  kind: value
  value: "no"
---

`Bib=yes` lets vehicles drive onto the eastern column of the structure's foundation, the cells with no cell of the same structure directly east of them. Every other foundation cell still blocks them. Infantry are unaffected, because their movement never reads the flag.

Two exceptions open one more cell: the cell two east and one south of the foundation's north-west corner. They matter only when that cell is part of the foundation but not in its eastern column. Each applies only to a vehicle whose house and the structure's house are allied both ways:

- a [`Refinery=yes`](/keys/refinery/) structure lets in a vehicle that sets [`Harvester=yes`](/keys/harvester/#scope-unittype);
- a [`Weeder=yes`](/keys/weeder/#scope-buildingtype) structure lets in a vehicle that sets [`Weeder=yes`](/keys/weeder/#scope-unittype).

Both exceptions test only the two types, not the vehicle's orders, so any such harvester may drive onto the cell whether or not it is heading for the dock.

:::caution[The flag draws no apron and adds no cells]
The apron artwork is [`BibShape`](/keys/bibshape/) in the art file, which is drawn whether or not this flag is set; a structure can set either one without the other. The flag also leaves the footprint unchanged: the structure occupies exactly the cells [`Foundation`](/keys/foundation/) gives it.
:::
