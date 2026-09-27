---
key: IsVeinholeMonster
summary: Lets explosions centered on the veinhole monster's cell damage it.
see_also: ["system:veins", "IsVeins"]
when_omitted:
  kind: value
  value: "no"
---

Set `IsVeinholeMonster=yes` on the veinhole overlay to let explosions damage the [veinhole monster](/systems/veins/#destruction). The monster takes damage only from an explosion centered on the monster's cell. That cell or one of the eight around it must also hold an overlay with this key. The shipped `VEINHOLE` overlay sets it, and that overlay stands in the monster's cell. The key has no other effect.

:::caution[Set it on the veinhole overlay only]
An explosion centered on the monster damages it once for each cell in the three-by-three block around it that holds an overlay with this key. If the `VEINHOLEDUMMY` overlays around the monster also set it, one explosion damages the monster up to nine times.
:::
