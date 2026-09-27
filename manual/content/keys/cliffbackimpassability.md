---
key: CliffBackImpassability
summary: Mode that turns a cell standing a cliff step below a neighbor into rock.
see_also: [Land, NoUseTileLandType]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[General]
CliffBackImpassability=2
```

`CliffBackImpassability=2` turns a cell into `Rock` when a nearby cell stands at least a full cliff step, four height levels, above it. Movement costs and the buildable test then read `Rock` in place of the cell's earlier [land type](/reference/enums/land-type/).

Only `2` changes anything. `0` turns the rule off, and any other value runs the height test and ignores the result. The value is stored as a single signed byte, so a number outside `-128` to `127` wraps before it is compared. For example, `258` acts as `2`.

The test covers six cells, not the eight that surround the cell. Written as (x, y) offsets from the cell, it checks `(0,-1)`, `(-1,0)`, `(+1,-1)`, `(-1,+1)` and `(+1,+1)`, and also `(+2,+2)`, two steps away. The cells at `(+1,0)`, `(0,+1)` and `(-1,-1)` are never checked.

The rule is the last step in working out a cell's land type, so it overrides the earlier steps. Whether it replaces the land type the cell has so far depends on where that land type came from:

- **An overlay whose land type is `Wall` or `Railroad`, or one set to [`NoUseTileLandType=yes`](/keys/nousetilelandtype/):** the cell becomes `Rock` whatever land type the overlay gave it.
- **A tile with no artwork for that part of the tile:** the cell has already been reset to `Clear`, and it becomes `Rock`.
- **Any other cell:** only `Clear`, `Water`, `Beach` and `Ice` become `Rock`. A cell that is already `Road`, `Rough`, `Tiberium`, `Weeds`, `Tunnel`, `Wall` or `Railroad` keeps its land type.
