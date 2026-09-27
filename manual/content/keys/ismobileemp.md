---
key: IsMobileEMP
summary: Makes a vehicle build up an EM pulse charge and discharge it where it stands when it is deployed.
see_also: ["system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

Deploying the vehicle with a full charge [fires the hard-coded pulse weapon](/systems/emp-pulse/#mobile-emp-vehicle) at its position and returns it to guard. The deploy cursor is refused until the charge reaches [`MaxCharge`](/keys/maxcharge/). A deploy order given with the deploy key before then fires nothing and also returns the vehicle to guard.

The flag is what lets a vehicle with no [`DeploysInto`](/keys/deploysinto/) type and no passenger capacity take a deploy order at all. A vehicle that has a `DeploysInto` type, carries passengers, or harvests performs that deploy action instead and never fires the pulse.
