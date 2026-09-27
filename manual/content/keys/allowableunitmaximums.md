---
key: AllowableUnitMaximums
summary: How many of each restricted type a mission's dropship loadout may hold.
see_also: [AllowableUnits, StartingDropships]
when_omitted:
  kind: computed
  note: "Half the names, rounded up, receive -1, starting from the front of the list. The names after them get no number, and their limits are unpredictable."
---

```ini title="map file"
[Basic]
AllowableUnits=E1,E2,SMECH
AllowableUnitMaximums=-1,-1,2
```

Each number caps how many of one type may be loaded across all of the mission's dropships together. It applies to the name at the same position in [`AllowableUnits`](/keys/allowableunits/).

| Value | Effect |
| --- | --- |
| `-1` | The type is offered and never counted, so it may fill the whole loadout |
| `0` | The type is left off the cameo list and cannot be loaded |
| Positive | The type is offered until that many are aboard, then its cameo stops responding |
| Other negative | The type is offered, but its cameo never responds |

:::caution[Give every name a number]
Write one number for each name in [`AllowableUnits`](/keys/allowableunits/). A shorter number list is padded with `-1`, but the padding supplies only half of the missing numbers, rounded up. For example, four names and one number gain two `-1` entries, and the fourth name has none. A name without a number gets an unpredictable limit.
:::

Extra numbers beyond the last name have no effect.

:::caution[Keep both lists in the same order]
Nothing checks that the two lists match. If they are written in a different order, or a name is removed and its number left in place, each later limit applies to whichever type now sits at that position.
:::
