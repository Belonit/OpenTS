---
key: RadialColor
scope: aircrafttype
label: Ring color
when_omitted:
  kind: value
  value: 0,0,0
---

`RadialColor` colors the [radius ring](/keys/hasradialindicator/) that a selected cloak generator or sensor array draws: both the ellipse and the line sweeping round it. Only a structure draws a ring, so the value matters only on a BuildingType.

```ini title="rules.ini"
[MYCLOAK] ; example BuildingType
CloakGenerator=yes
CloakRadiusInCells=12
HasRadialIndicator=yes
RadialColor=0,168,240
```

A structure that sets `HasRadialIndicator=yes` without a `RadialColor` draws the ellipse in black.
