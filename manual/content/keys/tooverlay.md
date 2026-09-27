---
key: ToOverlay
summary: The cell overlay a wall structure turns into when it is placed.
see_also: ["system:walls-and-gates", "Wall"]
when_omitted:
  kind: value
  value: none
---

```ini title="art.ini"
[GAWALL]
ToOverlay=GAWALL ; the OverlayType of the same name
```

A [`Wall=yes`](/keys/wall/#scope-buildingtype) BuildingType [turns into this overlay](/systems/walls-and-gates/#from-structure-to-overlay) when it is placed, and the structure itself is deleted.

The named overlay also decides three other things:

- Whether placing the type [fills the gap to the next wall](/systems/walls-and-gates/#filling-the-gap-to-the-next-wall). The fill runs when the named overlay is a wall, whether or not the structure is `Wall=yes`.
- Which damaged wall segments the type can be placed over.
- Whether that overlay can be sold at all. Only the first BuildingType in the rules that names a given overlay decides this.

A name that matches no OverlayType listed in `[OverlayTypes]` registers a new overlay type under that name. It takes its settings from a rules section of the same name if one exists. With no such section it is not a wall, and its cells count as clear terrain.

The values `none` and `<none>` name no overlay, the same as leaving the key out.

:::danger[A wall structure with no overlay named crashes on placement]
Give every `Wall=yes` BuildingType a `ToOverlay=` that names an overlay. If the key is missing or set to `none`, the game crashes the first time a structure of that type is placed. A computer house crashes earlier, when its base plan holds that type and it checks whether the plan entry is built.
:::
