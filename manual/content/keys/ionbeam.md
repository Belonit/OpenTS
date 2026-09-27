---
key: IonBeam
summary: The column of light drawn where an ion cannon strike lands.
see_also: [IonBlast, IonCannonDamage, IonCannonWarhead, SplashList, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
IonBeam=MYIONBEAM ; an AnimType registered in [Animations]
```

The beam plays centered on the impact point on the frame an ion cannon blast lands. It plays over land and water alike. [`IonBlast`](/keys/ionblast/), which plays with it, is replaced by a splash over water.

A superweapon with [`Type=IonCannon`](/keys/type/#scope-superweapontype) and the [Ion-cannon strike...](/mapping/actions/taction-ion-cannon/) trigger action both set off the same blast, so both play the beam.

:::danger[Name an animation before an ion cannon can fire]
With the key unset, the game crashes as soon as an ion cannon blast lands, whether the superweapon or the trigger action set it off.
:::
