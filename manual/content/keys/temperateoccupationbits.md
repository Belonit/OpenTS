---
key: TemperateOccupationBits
summary: Which of a cell's three infantry standing places a terrain object fills in a theater that is not arctic.
see_also: [SnowOccupationBits, Foundation]
when_omitted:
  kind: value
  value: "7"
  note: All three standing places are filled, which is also the figure that makes the cell fully blocked.
---

A cell has three places where infantry can stand: north-east, south-west and south-east. The value is a sum of bits, one per place, and the object fills each place whose bit is set: `1` for north-east, `2` for south-west and `4` for south-east. `6`, for example, leaves the north-east place open and fills the other two.

```ini title="rules.ini"
[MYROCK]                     ; example boulder that infantry can squeeze past
TemperateOccupationBits=4    ; only the south-east standing place is filled
SnowOccupationBits=4
```

The value also decides how much the object blocks movement. With exactly `7`, its cells are fully blocked. With any other value, including `0`, they are partly blocked. [Movement zones](/reference/enums/movement-zone/) treat the two classes differently, so changing the value from `7` changes which zones can cross:

| Movement zone | Crosses a fully blocked cell | Crosses a partly blocked cell |
| --- | --- | --- |
| `Infantry` | No | Yes |
| `Destroyer`, `AmphibiousDestroyer`, `Subterannean` | Yes | No |
| `InfantryDestroyer`, `Fly` | Yes | Yes |
| `Normal`, `Crusher`, `Amphibious`, `AmphibiousCrusher` | No | No |

The value applies in every theater without [`IsArctic=yes`](/keys/isarctic/). An arctic theater, such as `SNOW`, uses [`SnowOccupationBits`](/keys/snowoccupationbits/) instead. Set both keys to get the same result in every theater.

:::caution[Only the object's top-left cell gets standing places filled]
The blocking class applies to every cell of the object's [`Foundation`](/keys/foundation/#scope-terraintype) block, but standing places are filled only in the object's top-left cell. With any value other than `7`, infantry can path into the other cells of a larger object and use all three standing places there.
:::
