---
key: SmallFire
summary: The lesser of the two flames the engine lights for itself.
see_also: [LargeFire, OnFire, Sparky, Flamer, Scorch]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
SmallFire=MYFIRE_SM ; an AnimType registered in [Animations]
```

The game creates this flame in the cases below, and no object type can choose a different flame for any of them.

- A [`Flamer=yes`](/keys/flamer/) animation lays a patch of fire when it reaches its middle frame. One flame lands a quarter of a cell away in a random direction. On an even chance, a second lands five eighths of a cell away. On a separate even chance, a [`LargeFire`](/keys/largefire/) lands seven sixteenths of a cell away. Each flame is moved to the nearest free spot.
- A [`Scorch=yes`](/keys/scorch/) animation less than ten leptons above the ground creates one at its center, unless it is over water, beach, ice or rock. If the animation is attached to an object, the flame is attached to that object too.
- A destroyed structure gives each cell of its footprint an even chance of one, half a cell from the cell's center in a random direction. Half of those cells also get a `LargeFire`.
- A structure knocked down a damage level can get one on each footprint cell. [`Sparky`](/keys/sparky/) covers that case, including the engineer damage that prevents the flame and the [`OnFire`](/keys/onfire/) set that replaces it.

:::danger[Set SmallFire to a real animation]
None of these cases checks that an animation was named. If the key is unset, the first flame crashes the game, and ordinary structure damage reaches that point within the first few exchanges of fire. `SmallFire=none` is no safer: it leaves the same empty value as an omitted key and crashes the same way.
:::
