---
key: IonStormDuration
summary: Parsed storm length that the engine never uses.
no_effect: true
see_also: [IonStormWarning, "system:ion-storms"]
when_omitted:
  kind: value
  value: "20"
---

A storm lasts as long as the number given to the [Ion Storm start...](/mapping/actions/taction-ion-storm-start/) trigger action or the [Ion storm start in...](/mapping/missions/tmission-ion-storm-start/) team mission. The two count in different units, which [Starting a storm](/systems/ion-storms/#starting-a-storm) explains.

[`IonStormWarning`](/keys/ionstormwarning/), in the same section, is the storm timing setting the engine does use.
