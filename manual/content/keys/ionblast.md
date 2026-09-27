---
key: IonBlast
summary: The ring of fire drawn where an ion cannon strike meets the ground.
see_also: [IonBeam, IonCannonDamage, IonCannonWarhead, SplashList, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
IonBlast=MYIONRING ; an AnimType registered in [Animations]
```

The ring plays centered on the impact point on the frame an ion cannon blast lands on land. A blast that lands on water plays the last entry of [`SplashList`](/keys/splashlist/) instead. [`IonBeam`](/keys/ionbeam/) plays with either.

A superweapon with [`Type=IonCannon`](/keys/type/#scope-superweapontype) and the [Ion-cannon strike...](/mapping/actions/taction-ion-cannon/) trigger action both set off the same blast, so both play the ring.

:::danger[Name an animation before an ion cannon can fire]
With the key unset, the game crashes as soon as an ion cannon blast lands anywhere but water.
:::
