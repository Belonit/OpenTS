---
key: ChargeToDrainRatio
summary: The exchange rate between a charge-draining superweapon's stored charge and the time its effect runs.
see_also: [UseChargeDrain, RechargeTime, "system:superweapons"]
when_omitted:
  kind: value
  value: "3"
---

`ChargeToDrainRatio` sets how long a [`UseChargeDrain=yes`](/keys/usechargedrain/) superweapon's effect runs for the charge it spends. Fired from a full charge, the effect runs for [`RechargeTime`](/keys/rechargetime/) multiplied by this value. Switching the effect off early converts the time left back into charge at the same rate, so the unused share of the charge is kept. While the effect runs, the cameo clock shows the time left as a share of that full run time.

A value below `1` makes the effect shorter than the time the charge took to build, and a value above `1` makes it longer. The shipped `rules.ini` sets `.333`, so the firestorm's three-minute charge keeps the wall up for one minute.

One value in `[General]` covers every charge-draining weapon. It applies only to a house a human is playing, because a computer house's wall never drains. [Charge and drain](/systems/laser-fences/#charge-and-drain) gives both formulas as the firestorm wall uses them.
