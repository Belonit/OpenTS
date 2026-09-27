---
key: StartFacing
summary: The facing a structure snaps to when its construction animation ends, in eighths of a turn.
see_also: [StartPitch, IsJuggernaut, Artillary, LaserFence]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[DJUGG] ; the stock deployed Juggernaut
IsJuggernaut=yes
StartFacing=4 ; south
```

A structure snaps to this facing the moment its construction animation finishes. The facing shows only on a structure with a part that turns, such as a turret.

The value counts eighths of a turn: `0` is north, `2` east, `4` south and `6` west. Each step is 45 degrees, and no value selects a facing between two steps. Values outside `0` to `7` wrap around, so `8` is north again.

Two kinds of structure never take this facing:

- A [`LaserFence=yes`](/keys/laserfence/) structure keeps the facing it was placed with.
- A structure that starts the scenario on the map plays no construction animation.

An [`IsJuggernaut=yes`](/keys/isjuggernaut/) or [`Artillary=yes`](/keys/artillary/) structure also turns back to this facing when it packs up; [`StartPitch`](/keys/startpitch/) covers when.
