---
key: CarriesCrate
summary: Whether a destroyed vehicle of this type drops a crate, when the scenario allows the drop.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

The scenario decides whether the drop happens at all. A destroyed vehicle with the flag can drop a crate only when **Any of:**

- **All of:** its type is not [`IsTrain=yes`](/keys/istrain/), and the scenario sets [`TruckCrate=yes`](/keys/truckcrate/);
- **All of:** its type is `IsTrain=yes`, and the scenario sets [`TrainCrate=yes`](/keys/traincrate/).

With neither scenario flag set, the type's flag has no visible consequence.

[Crates dropped by destroyed vehicles](/systems/crates/#crates-dropped-by-destroyed-vehicles) covers where the crate lands, what happens when no cell nearby is free, how long the crate lasts, and the trigger action that changes `TrainCrate` during a mission.

A type with [`DeathFrames`](/keys/deathframes/) above `0` never drops the crate, because its destroyed vehicle stays on the map as a wreck and the wreck's final explosion skips the drop.
