---
key: Image
scope: buildingtype
label: Building main shape
when_omitted:
  kind: computed
  note: Uses the building's Image ID as the main SHP basename.
---

`Image=` in a building's art section changes only the file name of its main shape. The building keeps its Image ID, and its other art keys are still read from the `[<Image ID>]` section. This name is adjusted for the theater in the same way as the Image ID would be. [`Theater=`](/keys/theater/) and [`NewTheater=`](/keys/newtheater/) describe the adjustment. A building with `Theater=yes` ignores this key in a new game: once the map is read, it draws `<Image ID>` with the theater's extension. After a saved game loads, it draws the file this key names again.
