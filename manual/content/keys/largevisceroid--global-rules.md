---
key: LargeVisceroid
scope: global-rules
label: Merged visceroid type
see_also: ["SmallVisceroid"]
when_omitted:
  kind: value
  value: none
---

The named UnitType is what two small visceroids become when they merge. The one that was standing still becomes this type at the type's maximum strength and keeps its position and its house. The one that drove onto it is deleted. [`SmallVisceroid=yes`](/keys/smallvisceroid/#scope-unittype) covers how the two come together.

A merge produces exactly the type named here. Nothing checks that the type sets [`LargeVisceroid=yes`](/keys/largevisceroid/#scope-unittype), and the result behaves as a large visceroid only if its own section does.

A name that matches no declared UnitType creates a UnitType of that name. It is configured by a section of the same name if the rules supply one, and left blank if they do not. Only the values `none` and `<none>` name no type.

:::caution[Name a type while small visceroids can meet]
With no type named, the first merge crashes the game.
:::
