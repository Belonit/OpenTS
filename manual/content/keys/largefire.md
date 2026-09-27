---
key: LargeFire
summary: The greater of the two flames the engine lights for itself.
see_also: [SmallFire, OnFire, Flamer, Sparky]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
LargeFire=MYFIRE_LG ; an AnimType registered in [Animations]
```

The engine lights this flame in two situations, each time alongside [`SmallFire`](/keys/smallfire/):

- A [`Flamer=yes`](/keys/flamer/) animation reaches its middle frame. It has an even chance of laying one just under half a cell from its center in a random direction, at the nearest free spot. The animation also lays one small flame, and a second with an even chance, whether or not it lays this one.
- A structure is destroyed. Each cell of its footprint has an even chance of a small flame, and a cell that gets one has a further even chance of this flame, a quarter of a cell from the cell's center in a random direction. About one cell in four gets one.

No object type can name a different animation for either situation, so this key is the only way to change it. A structure that only drops a damage level does not use this flame. [`Sparky`](/keys/sparky/) covers that case, where the choice is between the small flame and the [`OnFire`](/keys/onfire/) set.

:::danger[Name an animation before a structure can be destroyed]
With the key unset, the game crashes the first time either situation lays this flame.
:::
