---
key: HasRadialIndicator
scope: aircrafttype
label: Radius ring
when_omitted:
  kind: value
  value: "no"
---

`HasRadialIndicator=yes` draws a ring around a selected [`CloakGenerator=yes`](/keys/cloakgenerator/) or [`SensorArray=yes`](/keys/sensorarray/) structure. No other type draws anything, whatever this key says.

The ring appears while such a structure is selected and switched on, and only for the player who owns it. It is an ellipse sized from [`CloakRadiusInCells`](/keys/cloakradiusincells/) and drawn in [`RadialColor`](/keys/radialcolor/), with a single line sweeping round it like a radar. A type can change only the ring's color and its radius; its shape is fixed.
