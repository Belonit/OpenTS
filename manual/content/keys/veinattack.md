---
key: VeinAttack
summary: AnimType a vein cell attaches to itself to hurt what stands in it.
see_also: ["system:veins", "IsVeins", "VeinDamage", "VeinholeWarhead"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
VeinAttack=VEINATAC
```

This animation is the [vein attack](/systems/veins/#standing-in-veins): while it plays over a cell, it damages the objects standing there.

A vein cell starts the animation when a vulnerable object moves into it or is placed there, and when its vein matures under a vulnerable object already standing in it. Only mature vein on flat ground attacks. Thin vein, vein on a slope and the veinhole itself never do.

A vulnerable object is a building, vehicle, infantryman or aircraft within 5 leptons of the ground. An object is not vulnerable if its type sets [`ImmuneToVeins=yes`](/keys/immunetoveins/) or it has the [`VEIN_PROOF`](/systems/veterancy/#abilities) veteran ability.

On every other frame, the animation deals [`VeinDamage`](/keys/veindamage/) to each vulnerable object in its cell. It removes itself once the cell is empty, the cell no longer holds flat mature vein, the object that entered the cell last is off the ground, or it has played all the passes its [`LoopCount`](/keys/loopcount/) gives it. A cell starts no new attack while one is running.

A cell starts one animation for each vulnerable object standing in it when the attack starts, and each animation damages every vulnerable object there. Objects that arrive later start none. Three infantry standing in vein that matures under them each take damage three times every other frame. Three that walk in one after another each take it once.

:::danger[Name an animation that sets IsVeins]
Set `VeinAttack` to an existing animation. If it is not set, the game crashes the first time a vulnerable object and flat mature vein share a cell, whether the object arrives or the vein matures under it.

Set [`IsVeins=yes`](/keys/isveins/#scope-animtype) in that animation's `art.ini` section. Otherwise the animation plays as ordinary artwork, deals no damage, and its cell never starts another attack.

Set `LoopCount=-1` in that section as well. With a finite count the attack stops after that many passes, and an object standing still in the vein takes no more damage until an object moves into the cell or is placed there.
:::
