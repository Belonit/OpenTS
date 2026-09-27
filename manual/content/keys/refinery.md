---
key: Refinery
summary: Marks a structure as a Tiberium refinery, which decides when its production animation plays for a docked harvester.
see_also: ["system:tiberium", "DockUnload", "Storage"]
when_omitted:
  kind: value
  value: "no"
---

`Refinery=yes` changes how Tiberium harvesters use the structure:

- The structure's docking point is half a cell east of its center. When the structure is captured, a harvester docking with it changes owner with it only if the harvester is standing still within a quarter of a cell of that point; [What changes hands](/systems/capture/#what-changes-hands) covers the rule. The flag does not move the cell where a harvester parks to unload.
- The structure plays its [`ProductionAnim`](/keys/productionanim/) when a docked harvester finishes unloading or is ordered elsewhere. The harvester waits at the dock until that animation ends.
- A harvester that has nothing left to harvest and is standing on the structure moves off to a nearby cell.
- A harvester standing on one of the structure's cells is drawn with a depth bias that puts it in front of the structure's artwork. A harvester unloading at a structure gets a smaller bias instead, whatever this flag says.
- On a [`Bib=yes`](/keys/bib/) structure, a harvester may also drive onto the cell two east and one south of the foundation's north-west corner, if its house and the structure's house are allied both ways.

The flag does not let a harvester dock; that is [`DockUnload=yes`](/keys/dockunload/). It does not store Tiberium either; that is [`Storage`](/keys/storage/). [Unloading](/systems/tiberium/#unloading) covers the whole unloading sequence.
