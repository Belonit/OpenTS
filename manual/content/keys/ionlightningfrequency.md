---
key: IonLightningFrequency
summary: The approximate percent chance, on each frame of an ion storm, that the storm tries a lightning bolt.
see_also: [IonLightningRandomness, "system:ion-storms"]
when_omitted:
  kind: value
  value: "25"
---

```ini title="rules.ini"
[General]
IonLightningFrequency=25
```

On each frame of a storm, the storm tries a bolt with a chance of ten times this value in 1001. That is close to the value as a percentage: `25` gives 250 chances in 1001, a bolt on about one frame in four, and `100` gives 1000 in 1001. Digits beyond the first decimal place are dropped, so `25.55` acts as `25.5`.

A fraction set in `rules.ini` is lost when a later file has a `[General]` section that does not set this key, such as a map's rules overrides. Reading that file rounds the value down to a whole number, so `25.5` becomes `25`. Repeat the key in that file to keep the fraction.

A bolt the storm tries does not always strike. An aimed bolt whose [candidate list](/systems/ion-storms/#where-it-strikes) comes up empty strikes nothing that frame.
