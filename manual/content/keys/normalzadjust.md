---
key: NormalZAdjust
summary: The depth bias applied to the structure's main shape.
see_also: ["ZShapePointMove", "DeployingAnim", "SpecialZOverlayZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

The value shifts the depth at which the structure's main shape is drawn, which decides what the structure covers and what covers it. A negative value brings the structure toward the viewer, so it covers more of what surrounds it. A positive value pushes it back. The direction matches an animation's depth bias, such as [`ActiveAnimZAdjust`](/keys/activeanimzadjust/).

```ini title="art.ini"
[MYWEAP] ; example war factory, drawn from its own Image ID
NormalZAdjust=-10
```

The bias applies to the main shape wherever it is drawn, including the frames a [`Gate=yes`](/keys/gate/) structure draws while its gate moves and the copy of the structure shown under fog. Three other shapes use fixed biases: the [`BibShape`](/keys/bibshape/) apron is drawn one pixel toward the viewer, the [`DoorAnim`](/keys/dooranim/) frames five pixels toward the viewer, and the [`UnderDoorAnim`](/keys/underdooranim/) shape with no bias.

The main shape ignores this value in three cases:

- The frames drawn from [`DeployingAnim`](/keys/deployinganim/) while the structure is unloading use no bias.
- A [`FirestormWall=yes`](/keys/firestormwall/) structure is always drawn one pixel toward the viewer.
- A [`LaserFence=yes`](/keys/laserfence/) segment is drawn one pixel toward the viewer while its run is slack. Its live frames use this value.
