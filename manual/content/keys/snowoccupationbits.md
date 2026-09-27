---
key: SnowOccupationBits
summary: Which of a cell's three infantry standing places a terrain object fills in an arctic theater.
see_also: [TemperateOccupationBits, Foundation]
when_omitted:
  kind: value
  value: "7"
  note: All three standing places are filled, which is also the figure that makes the cell fully blocked.
---

The value is used in a theater with [`IsArctic=yes`](/keys/isarctic/), as `SNOW` is. Every other theater uses [`TemperateOccupationBits`](/keys/temperateoccupationbits/) instead. The value works the same way as that key: it decides which standing places the object fills and whether its cells count as fully or partly blocked. That page covers both.

```ini title="rules.ini"
[MYROCK]                     ; example boulder that infantry can squeeze past
TemperateOccupationBits=4    ; only the south-east standing place is filled
SnowOccupationBits=4
```
