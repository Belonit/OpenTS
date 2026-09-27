---
key: GateCloseDelay
summary: The time in game minutes a gate stands open once its footprint is clear.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: "0"
---

Only a [`Gate=yes`](/keys/gate/) BuildingType reads the value. A game minute is 900 frames.

```ini title="rules.ini"
[GAGATE_A] ; a stock GDI gate
Gate=yes
GateCloseDelay=.2
```

The timer starts when the door starts to open, so the door's travel time, [`DeployTime`](/keys/deploytime/), counts against it. While the door stands fully open and anything other than the gate occupies its footprint, the timer restarts, so the gate never closes on traffic. Once the footprint is clear and the timer has run out, the door closes. With the stock `.2`, the timer is 180 frames. A gate whose footprint stays clear while it is fully open starts closing 180 frames after it began to open. Otherwise it starts closing 180 frames after its footprint last cleared. At `0` it starts closing as soon as the door is fully open and the footprint is clear.

Once the door has started to close, something standing in the footprint no longer holds it open. Only an allied unit asking to pass reverses the door.
