---
key: IsCoreDefender
scope: unittype
label: Core defender vehicle
see_also: [SensorArray, "ImmuneToEMP", "system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

On a vehicle, `IsCoreDefender=yes` has two unrelated effects.

When the type leaves out [`ImmuneToEMP`](/keys/immunetoemp/), the flag makes the vehicle immune to [EM pulses](/systems/emp-pulse/#what-a-pulse-reaches). A pulse that stops and stuns other vehicles leaves it moving and only springs its [Paralyzed](/mapping/events/tevent-paralyzed/) trigger event. Set `ImmuneToEMP=no` to remove the immunity.

The vehicle is also drawn the way a structure is. When selected, it gets a box-shaped selection outline and a structure's pip bar along the near edge of its footprint, where other vehicles get a bracket and a row of health pips. The outline is 700 leptons tall, a little under three cell widths.

An unselected core defender vehicle is drawn the same way while it is underground on a cell that the player's [sensor array](/keys/sensorarray/) detects.
