---
key: Height
scope: buildingtype
label: Structure vertical extent
see_also: ["Foundation", "MidPoint"]
when_omitted:
  kind: value
  value: "1"
---

The value is the structure's height in steps of 200 leptons, a little under two terrain height levels of 104 leptons each. It is read as a whole number, so `Height=1.5` gives `1`.

```ini title="art.ini"
[MYWEAP] ; example war factory, drawn from its own Image ID
Foundation=4x3
Height=2
```

The height does not change how the structure itself is drawn. It has three effects:

- **Selection bracket and health bar.** The bracket drawn around a selected structure rises to this height, and the health bar sits at its top.
- **Jumpjet flight level.** A jumpjet sets its flight level from the top of whatever occupies the cell below it. A structure's top is 200 leptons per step above the ground it stands on. A moving jumpjet also looks at the cell ahead. It takes that cell's height when it is the higher of the two, and otherwise the average of the two.
- **Aim of straight shots.** When a projectile that neither arcs nor is a voxel is fired at a structure more than 200 leptons above or below the firing turret, it is pitched at a point 200 leptons per step above height level `0`. That point ignores the ground the structure stands on, so on raised terrain the shot aims below the structure's roof.
