---
key: NewTheater
scope: aircrafttype
label: Theater artwork naming
see_also: ["Theater", "Image", "Voxel"]
when_omitted:
  kind: value
  value: "no"
---

`NewTheater=yes` looks for the type's shape under a theater-specific name. The name is `<Image ID>.SHP` with its second letter replaced by the scenario theater's [`ImageLetter`](/keys/imageletter/): `T` in temperate and `A` in snow. A name is rewritten only when its second letter is already the image letter of some declared theater, ignoring case. Any other name, such as `CITY01` with the stock theaters, is looked up as written in every theater.

```ini title="art.ini"
[GAFENC] ; example Image ID of an OverlayType
NewTheater=yes ; draws GTFENC.SHP in temperate and GAFENC.SHP in snow
```

Whether the renamed shape is drawn depends on the kind of type:

- Overlays, projectiles and particles draw the renamed shape.
- Structures are renamed whether or not the flag is set. The rename covers the structure's shape and the art named by [`Buildup`](/keys/buildup/), [`DeployingAnim`](/keys/deployinganim/), [`DoorAnim`](/keys/dooranim/), [`UnderDoorAnim`](/keys/underdooranim/), [`SpecialZOverlay`](/keys/specialzoverlay/) and [`BibShape`](/keys/bibshape/).
- Aircraft, infantry, vehicles, smudges and terrain objects ignore the flag in a new game. They draw `<Image ID>.SHP`, and have no shape if only the renamed file exists.

Where the renamed shape is drawn, it is the only name tried. A type whose file for the current theater is missing has no shape, so provide one file for each theater.

:::caution[A loaded game can draw different art]
Loading a saved game fetches shapes again. These types can then draw a different file from the one the saved game drew:

- A flagged aircraft, infantry or vehicle type draws its renamed shape when that file exists. Otherwise it keeps `<Image ID>.SHP`.
- A flagged smudge or terrain type draws its renamed shape when that file exists. Otherwise it has no shape.
- Every OverlayType that sets neither [`Theater=yes`](/keys/theater/) nor [`DemandLoad=yes`](/keys/demandload/#scope-overlaytype) is renamed whether or not it sets this flag. It has no shape when the renamed file is missing.

To make a loaded game draw the same art, leave `NewTheater=yes` off aircraft, infantry, vehicle, smudge and terrain types, where it has no effect in a new game. Give each such overlay its file under the renamed name as well as `<Image ID>.SHP`.
:::
