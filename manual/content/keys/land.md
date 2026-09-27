---
key: Land
summary: The land type a cell reports while this overlay is on it.
see_also: ["system:walls-and-gates", "NoUseTileLandType", "Tiberium", "CliffBackImpassability"]
when_omitted:
  kind: value
  value: Clear
---

```ini title="rules.ini"
[MYWALL]  ; example overlay; the stock walls leave Land at Clear
Land=Wall
```

An overlay can give its cell a [land type](/reference/enums/land-type/) in place of the one the tile underneath provides. Movement costs and the buildable test read the cell's land type. Which one the cell reports depends on this value and on [`NoUseTileLandType`](/keys/nousetilelandtype/):

1. `Wall` or `Railroad`: the cell reports this value, whatever `NoUseTileLandType` says.
2. Any other value with `NoUseTileLandType=yes`, the default: the cell reports this value.
3. Any other value with `NoUseTileLandType=no`: the cell usually reports the tile's land type. The `NoUseTileLandType` page lists the exceptions for cells that hold Tiberium.

In each case, [`CliffBackImpassability`](/keys/cliffbackimpassability/) can still turn the cell to `Rock` when a neighbor stands a cliff step higher.

[`Tiberium=yes`](/keys/tiberium/#scope-overlaytype) changes a `Land=Clear` setting to `Tiberium` when the section is read. A Tiberium overlay that leaves `Land` alone therefore reports `Tiberium`, which is the land type harvesters collect from.

`Land=Wall` puts the cell under the `[Wall]` movement costs, and a burning infantryman will not run into the cell. It does not make the overlay a wall. [`Wall=yes`](/keys/wall/#scope-overlaytype) does that, and it controls blocking, damage and connections.
