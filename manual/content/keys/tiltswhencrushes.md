---
key: TiltsWhenCrushes
summary: Makes a crushing vehicle tilt as it drives into a sandbag wall.
see_also: ["Crusher"]
when_omitted:
  kind: value
  value: "yes"
---

With the flag set, a vehicle tilts its hull as it starts to crush a sandbag wall. The vehicle must be [`Crusher=yes`](/keys/crusher/) or have the crusher ability from its rank. The moment depends on the locomotor:

- **Drive:** as the vehicle enters the wall's cell. A drive vehicle always enters a crushable cell in a straight line, without turning.
- **Mech:** when the next cell on its path holds sandbag wall. The mech tilt is half as strong as the drive tilt.

With the flag cleared, the vehicle still crushes the wall and skips only this extra tilt. Every crushable overlay, sandbag wall included, also rocks the hull when the vehicle flattens it; this flag does not control that rocking.

The flag does not change speed. The drive locomotor holds an [`Accelerates=yes`](/keys/accelerates/) vehicle to a fifth of its top speed while it crushes sandbag wall, whatever this flag says.

The stock rules clear the flag on one type, the Mammoth Mk. II.
