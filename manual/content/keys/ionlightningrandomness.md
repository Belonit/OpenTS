---
key: IonLightningRandomness
summary: The percent chance that an ion storm lightning bolt strikes a random cell instead of an object.
see_also: [IonLightningFrequency, IonImmune, LightningRod, "system:ion-storms"]
when_omitted:
  kind: value
  value: "75"
---

```ini title="rules.ini"
[General]
IonLightningRandomness=75
```

Each called bolt strikes a random cell with this percent chance. Otherwise it is aimed at an object.

A random bolt strikes any cell of the playfield. It can hit empty ground, including the map border outside the playable area.

An aimed bolt strikes one object from a [list of candidates](/systems/ion-storms/#where-it-strikes). When the list comes up empty, no bolt falls that frame.

At `100` every bolt is random, so [`LightningRod`](/keys/lightningrod/) and [`IonImmune`](/keys/ionimmune/) no longer affect where lightning falls. At `0` every bolt is aimed, so a storm over a map with no candidates never strikes.
