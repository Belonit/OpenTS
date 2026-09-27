---
key: Conventional
summary: A blast landing on water plays a splash from the shared list instead of the warhead's own animations.
see_also: [AnimList, SplashList, EMEffect]
when_omitted:
  kind: value
  value: "no"
---

`Conventional` changes only the impact animation. Damage, cratering, particles and the blast's other effects are the same as without it.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Conventional=yes
AnimList=MYBANG16,MYBANG24 ; not used over water
```

The splash is chosen from [`SplashList`](/keys/splashlist/) by damage, in 35-point bands: the first entry covers 1 to 34 damage, the second 35 to 69, and the last covers everything above. [`AnimList`](/keys/animlist/) uses 25-point bands instead.

A blast splashes only when the ground under the impact is water. It still plays the warhead's own animation when it is at or above the deck of a bridge, or when a projectile bursts two or more height levels above the ground.

:::danger[An empty splash list gives no animation]
A blast that splashes while `SplashList` is empty plays no animation. It does not fall back to `AnimList`. Four explosions that crash without an animation can land on water, so they crash here too when their warhead is `Conventional=yes`. Three use [`C4Warhead`](/keys/c4warhead/): a flying object that falls to the ground, a stranded vehicle, and a destroyed Tiberium-spawning terrain object. The fourth is lightning, which uses [`IonStormWarhead`](/keys/ionstormwarhead/).
:::
