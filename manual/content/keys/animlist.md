---
key: AnimList
summary: The impact animations of the warhead, chosen by the damage the blast deals.
see_also: [EMEffect, Conventional, SplashList, C4Warhead, IonStormWarhead, DropPodWeapon]
when_omitted:
  kind: value
  value: none
---

The blast's damage picks one entry. Each entry covers a 25-point band in list order: the first covers 1 to 24 damage, the second 25 to 49, and so on. The last entry also covers all damage above its band.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
AnimList=MYBANG16,MYBANG24,MYBANG34 ; 1-24, 25-49, 50 and above
```

A blast that deals exactly zero damage plays no animation. So does a warhead with an empty list; `AnimList=none` empties it.

Two settings change the choice. [`EMEffect=yes`](/keys/emeffect/) picks an entry at random instead of by damage. [`Conventional=yes`](/keys/conventional/) plays a splash from the shared splash list instead when the blast lands on water.

An entry that names an animation missing from the [`[Animations]` list](/formats/rules-registries/) is added as a new animation, not rejected. A misspelled entry therefore gives no error and shows no explosion.

:::danger[Give these warheads a list]
Some explosions play their animation without checking that one was chosen. The game crashes the first time one of them has no animation. They are certain blasts of [`C4Warhead`](/keys/c4warhead/), the lightning of [`IonStormWarhead`](/keys/ionstormwarhead/), and the blasts of the weapon that [`DropPodWeapon`](/keys/droppodweapon/) names. Each of those pages lists its events. Give each of these warheads a non-empty list. A blast from them that deals zero damage also has no animation and crashes the same way.
:::

:::danger[Keep healing weapons off warheads with a list]
Negative damage also picks an entry by band. When the weapon's [`Damage`](/keys/damage/#scope-weapontype) is between `-1` and `-24`, the first entry plays as normal. At `-25` or lower, the game reads before the start of the list. A Debug build stops on an assertion, and a Release build reads an invalid animation and typically crashes on impact.
:::
