---
key: IonCannonDamage
summary: The raw damage an ion cannon blast applies, and the strength ceiling the computer rates a target against.
see_also: [IonCannonWarhead, "system:superweapons"]
when_omitted:
  kind: value
  value: "700"
---

An ion cannon blast deals this damage through [`IonCannonWarhead`](/keys/ioncannonwarhead/). The blast has no attacker, so no house is credited with its kills. Otherwise it damages like any explosion: the warhead's [`Verses`](/keys/verses/) table and [`Spread`](/keys/spread/#scope-warheadtype) falloff apply, and objects with [`Immune=yes`](/keys/immune/#scope-aircrafttype) take none. A cell under a bridge is hit twice at full damage, once at the bridge deck and once at ground level.

When the warhead sets [`Bright=yes`](/keys/bright/#scope-warheadtype), this figure also sets the size of the flash. The flash grows between 88 and 252 damage, so the default `700` already gives the largest.

The computer reads the same value when it [aims an ion cannon](/systems/superweapons/#the-computers-use). An enemy object whose current strength is at or below this figure takes its rating from the computer's target table instead of its base rating. Raising the damage therefore also changes which objects the computer prefers to strike.
