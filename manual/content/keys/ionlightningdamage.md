---
key: IonLightningDamage
summary: The raw damage each ion storm lightning bolt delivers.
see_also: [IonStormWarhead, "system:ion-storms"]
when_omitted:
  kind: value
  value: "500"
---

```ini title="rules.ini"
[General]
IonLightningDamage=500
```

Each lightning bolt deals this damage through [`IonStormWarhead`](/keys/ionstormwarhead/) to every object within 1.5 cells of the strike point. Objects with [`Immune=yes`](/keys/immune/#scope-aircrafttype), and members of a team whose TeamType sets [`IonImmune=yes`](/keys/ionimmune/), take none. The bolt has no attacker, so no house is credited with its kills. The warhead's [`Verses`](/keys/verses/) table and [`Spread`](/keys/spread/#scope-warheadtype) falloff decide what each object loses. [What a strike does](/systems/ion-storms/#what-a-strike-does) lists the rest of the strike.

The same figure picks the bolt's explosion animation from the warhead's [`AnimList`](/keys/animlist/), or from [`SplashList`](/keys/splashlist/) when a [`Conventional=yes`](/keys/conventional/) warhead strikes open water. An [`EMEffect=yes`](/keys/emeffect/) warhead picks its `AnimList` entry at random instead of by damage. A bolt on a bridge cell strikes the bridge deck, so it uses `AnimList` even over water.

When the warhead sets [`Bright=yes`](/keys/bright/#scope-warheadtype), the figure also sets the size of the flash. The flash grows between 88 and 252 damage, so the default `500` already gives the largest.

The [Lightning strike at...](/mapping/actions/taction-ion-lightning-strike/) trigger action strikes with the same damage at a waypoint, whether or not a storm is running.

:::danger[Keep the damage above 0]
At `0`, a bolt selects no explosion animation, and the game crashes at the first strike.
:::
