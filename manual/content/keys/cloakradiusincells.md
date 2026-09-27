---
key: CloakRadiusInCells
summary: The radius in cells of a cloak generator's field or a sensor array's coverage.
when_omitted:
  kind: value
  value: "20"
---

A [`CloakGenerator=yes`](/keys/cloakgenerator/) structure grows its field out to this radius, one cell per game frame. A [`SensorArray=yes`](/keys/sensorarray/) structure marks every cell closer than this radius as sensed, all in one frame. The value is stored in a single byte, so values above `127` wrap to negative numbers.

Every cloaking field is cut off at the edge of a square centered on its generator. The square's side is the largest `CloakRadiusInCells` of any BuildingType plus sixteen cells, counting types that are neither generators nor arrays. So when no type sets more than the default, even a default 20-cell field is cut off. [What a field covers](/systems/cloaking/#what-a-field-covers) gives the sizes. Sensor coverage is not cut off.

The same radius sizes the ellipse drawn on the tactical map for a selected cloak generator or sensor array whose type also sets [`HasRadialIndicator=yes`](/keys/hasradialindicator/). The ellipse appears only while that structure is switched on and its house is player-controlled.
