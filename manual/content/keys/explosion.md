---
key: Explosion
summary: The explosion animations a destroyed vehicle, structure or aircraft plays.
see_also: [ScrapExplosion, ScrapMetal, Explodes, DebrisTypes, MaxDebris, FirestormWarhead, Ammo]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
Explosion=TWLT070,FRAG1,FRAG3 ; AnimTypes registered in [Animations]
```

A destroyed object plays entries from this list. How many it plays, and where, depends on the kind of object:

- A **vehicle** plays one entry, picked at random, at its position. Three cases change that:
  - A vehicle whose art declares [`DeathFrames`](/keys/deathframes/) first stands as a wreck, and plays its entry when the wreck explodes.
  - A kill by [`[CombatDamage] FirestormWarhead`](/keys/firestormwarhead/) plays seven to nine firestorm particle systems instead.
  - A vehicle that dies in water after falling leaves a wake and the last entry of [`SplashList`](/keys/splashlist/) instead.
- A **structure** plays one entry, picked separately, on every cell of its footprint. Each is placed a quarter cell from its cell's center in a random direction and starts zero to three frames late. A large structure therefore plays many entries.
- An **aircraft** plays one entry, picked at random, where it was hit. A kill by the firestorm warhead plays seven to nine firestorm particle systems instead.
- **Infantry** never play this list.

A vehicle that is [`Explodes=yes`](/keys/explodes/#scope-aircrafttype), or whose rank grants the `EXPLODES` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/), plays the **last** entry whenever it still has ammunition. It has ammunition when its [`Ammo`](/keys/ammo/) is unlimited or its count is above zero. Put the biggest explosion at the end of the list.

In a match with [`ScrapMetal`](/keys/scrapmetal/) on, the type's [`ScrapExplosion`](/keys/scrapexplosion/) list replaces this one in every case above. A type with no `ScrapExplosion` entries keeps this list.

An empty list plays no animation. The wreckage, the death voice and any `Explodes=yes` blast still happen. A vehicle with an empty list also skips two effects that come with its death animation: the [`TiberiumExplosive`](/keys/tiberiumexplosive/#scope-global-rules) blast of its load and the [screen shake](/keys/shakescreen/) of a strong vehicle.

`Explosion=none` empties the list. A key with nothing after the `=` counts as absent, so the type keeps the list an earlier rules file set. An unknown name is registered as a new animation type instead of being rejected, so a misspelled name adds an animation of its own to the list.
