---
key: Height
scope: smudgetype
label: Smudge rows
see_also: ["Width", "Crater", "Burn"]
when_omitted:
  kind: value
  value: "1"
---

`Height` is the number of cell rows the smudge covers, and [`Width`](/keys/width/#scope-smudgetype) is the number of columns. The block's top corner is its origin, and the origin sits on the cell where the scorch or crater is requested. Columns run down and to the right from the origin, and rows run down and to the left.

```ini title="rules.ini"
[MYCRATER]     ; example two-by-two crater
Crater=yes
Width=2
Height=2
```

The game draws only the first frame of the smudge's artwork, positioned from the origin cell. A multiple-cell smudge therefore needs one image that covers the whole block.

A smudge type fits a spot only if the origin cell is inside the [playfield](/keys/size/#scope-scenarios). The rest of the block may extend past it. Every cell of the block must also meet **none of** these conditions:

- the cell is a ramp;
- the cell already has a smudge;
- the cell holds an overlay, such as Tiberium;
- a structure stands on the cell, except when the request is a destroyed structure's central mark;
- the cell's tile is [`Morphable=no`](/keys/morphable/).

Among the types that fit, the request prefers some sizes over others:

- A destroyed structure's central mark prefers multiple-cell smudges, those with both `Width` and `Height` above `1`.
- An animation prefers one-by-one smudges. If its largest frame is more than 48 pixels wide and more than 40 pixels tall, it has no preference.
- The marks a destroyed structure lays across its footprint have no preference.

If no type of the preferred size fits, the pick is made from every type that fits. A type with only one side above `1`, such as two by one, is never preferred. It is picked only by a request with no preference or when no preferred type fits.

:::caution[Keep both sizes at 1 or more]
A smudge type with `Width` or `Height` at `0` or below fits every spot and stays in the pool, but covers no cells. A request that picks it leaves no mark.
:::
