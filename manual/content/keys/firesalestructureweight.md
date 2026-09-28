---
key: FireSaleStructureWeight
summary: What each structure adds to a house's forces when a Short Game fire sale decides whether to keep one.
see_also: [FireSaleKeepThreshold]
when_omitted:
  kind: value
  value: "2"
---

```ini title="rules.ini"
[AI]
FireSaleStructureWeight=1
```

Each of the selling house's structures on the map adds this value to the count that [`FireSaleKeepThreshold`](/keys/firesalekeepthreshold/) compares against, while each vehicle and infantry unit adds `1`. The default of `2` stands for the crew a sold structure releases. `0` leaves structures out of the count.

Two kinds of structure do not add the weight:

- a structure already being sold adds nothing, because any crew has left it and counts as infantry;
- a structure with an [`UndeploysInto`](/keys/undeploysinto/) type that is not a construction yard counts `1`, as a vehicle.
