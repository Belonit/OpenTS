---
key: IonStormWarhead
summary: The WarheadType every ion storm lightning bolt detonates with.
see_also: [IonLightningDamage, IonImmune, "system:ion-storms"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[General]
IonStormWarhead=MyStormWH ; a WarheadType registered in [Warheads]
```

Every lightning bolt, from a storm or from the [Lightning strike at...](/mapping/actions/taction-ion-lightning-strike/) trigger action, detonates with this warhead. Its [`Verses`](/keys/verses/) table and [`Spread`](/keys/spread/#scope-warheadtype) falloff decide what each object near the strike loses, its [`AnimList`](/keys/animlist/) supplies the explosion animation, and [`Bright=yes`](/keys/bright/#scope-warheadtype) adds a flash. [What a strike does](/systems/ion-storms/#what-a-strike-does) lists the whole effect.

:::caution[This assignment also decides who is immune]
An explosion with this warhead does no damage to a vehicle, infantryman or aircraft on a team whose TeamType sets [`IonImmune=yes`](/keys/ionimmune/). A weapon that uses this same warhead also spares those objects, and pointing this key at a different warhead moves the exemption with it.
:::

:::danger[Name a warhead that has an `AnimList`]
With the key unset, or naming a warhead whose `AnimList` is empty, the game crashes at the first bolt. A [`Conventional=yes`](/keys/conventional/) warhead that strikes water takes its animation from [`SplashList`](/keys/splashlist/) instead, and crashes there if that list is empty.
:::
