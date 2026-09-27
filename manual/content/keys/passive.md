---
key: Passive
summary: Makes a vehicle take its speed from the vehicle it follows and refuse routes that stop short of its destination.
see_also: ["IsTrain", "Accelerates", "MovementRestrictedTo"]
when_omitted:
  kind: value
  value: "no"
---

`Passive=yes` changes three things about how a vehicle drives.

A passive vehicle does not set its own speed while [`Accelerates=yes`](/keys/accelerates/) is on. It is neither sped up nor braked near its destination, and keeps the speed it was last given. A vehicle at the head of a line hands its speed to each vehicle following it on every step, as long as the leader has `Accelerates=yes` and is not passive itself. That is how cars keep pace with a locomotive. Without `Accelerates=yes`, the flag does not affect speed.

A passive vehicle needs a route that reaches its destination. When the destination cell is blocked, an ordinary vehicle accepts a route that ends beside it. A passive vehicle does not, so a blocked destination leaves it with no route at all.

Partway through a turn, when the next cell of its route is enterable, a passive vehicle starts the following turn at once. An ordinary vehicle finishes its current turn first.

```ini title="rules.ini"
[MYORECAR] ; a UnitType registered in [VehicleTypes]
Passive=yes
IsTrain=yes
MovementRestrictedTo=Railroad
```
