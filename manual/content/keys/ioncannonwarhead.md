---
key: IonCannonWarhead
summary: The WarheadType an ion cannon blast applies its damage through.
see_also: [IonCannonDamage, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

An ion cannon blast deals [`IonCannonDamage`](/keys/ioncannondamage/) through this warhead to objects within 1.5 cells of the impact point. The warhead's [`Verses`](/keys/verses/) table sets what each armor takes, its [`Spread`](/keys/spread/#scope-warheadtype) sets how quickly damage falls off with distance, and [`Bright=yes`](/keys/bright/#scope-warheadtype) adds a flash. `IonCannonDamage` covers kill credit, immune objects and cells under a bridge.

The [Ion-cannon strike...](/mapping/actions/taction-ion-cannon/) trigger action uses the same warhead. It sets off a blast directly, without a superweapon.

:::caution[This assignment also changes bridge damage]
An explosion with this warhead damages a bridge span without the [`BridgeStrength`](/keys/bridgestrength/) roll, provided the warhead sets [`Wall=yes`](/keys/wall/#scope-warheadtype) and bridge destruction is on. Any weapon that uses this same warhead also brings bridges down without the roll.
:::
