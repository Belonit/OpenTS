---
key: TrainCrate
summary: Whether a destroyed train vehicle drops a crate in this scenario.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

With the switch on, a destroyed [`CarriesCrate=yes`](/keys/carriescrate/) vehicle whose type sets [`IsTrain=yes`](/keys/istrain/) drops a crate on a free cell near where it died. Other `CarriesCrate=yes` vehicles follow [`TruckCrate`](/keys/truckcrate/) instead.

Unlike `TruckCrate`, this setting can change during a mission. Each time the [Toggle Train Cargo](/mapping/actions/taction-toggle-train-cargo/) trigger action runs, it turns the setting to the opposite state.
