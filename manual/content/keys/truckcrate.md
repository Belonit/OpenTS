---
key: TruckCrate
summary: Whether a destroyed non-train vehicle drops a crate in this scenario.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

With the switch on, a destroyed [`CarriesCrate=yes`](/keys/carriescrate/) vehicle drops a crate on a free cell near where it died, unless its type sets [`IsTrain=yes`](/keys/istrain/). Trains follow [`TrainCrate`](/keys/traincrate/) instead.

The setting is read once as the scenario loads, and no trigger action changes it.
