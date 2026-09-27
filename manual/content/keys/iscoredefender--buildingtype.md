---
key: IsCoreDefender
scope: buildingtype
label: Core defender structure
see_also: [DeploysInto, UndeploysInto, "ImmuneToEMP", "system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

`IsCoreDefender=yes` makes the structure one of the [deployed-vehicle kinds](/keys/deploysinto/). A vehicle that deploys into it places it on the vehicle's cell, not one cell away, and the structure undeploys back onto that cell. It can be undeployed whether or not the session allows redeploying.

When the type leaves out [`ImmuneToEMP`](/keys/immunetoemp/), the flag also makes the structure immune to [EM pulses](/systems/emp-pulse/#what-a-pulse-reaches). A pulse that powers off and stuns other structures leaves it running and only springs its [Paralyzed](/mapping/events/tevent-paralyzed/) trigger event. Set `ImmuneToEMP=no` to remove the immunity.
