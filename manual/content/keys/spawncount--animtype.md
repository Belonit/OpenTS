---
key: SpawnCount
scope: animtype
label: Animation spawn count
see_also: ["Spawns", "Bouncer", "IsMeteor"]
when_omitted:
  kind: value
  value: "0"
---

The number of [`Spawns`](/keys/spawns/#scope-animtype) animations created at the impact is the sum of two random picks, each from `0` to this value. With `SpawnCount=3`, for example, an impact creates between 0 and 6 animations, 3 on average. A value of `0` or below creates none.

Only a thrown animation spawns anything: one with [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype). A thrown animation that lands in water creates nothing, unless it lands on a bridge.
