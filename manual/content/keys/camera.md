---
key: Camera
summary: Makes an aircraft that carries the weapon in its first slot a loaner the player cannot select.
see_also: ["Landable", "Selectable", "Primary"]
when_omitted:
  kind: value
  value: "no"
---

`Camera=yes` makes an aircraft a [loaner](/keys/landable/#what-a-loaner-does) when the weapon is in the aircraft's first weapon slot as it enters the map. A loaner's owner cannot select it while it can move, it may leave the map, and when idle with no team it never settles into guard. [`Landable=no`](/keys/landable/) and [`Selectable=no`](/keys/selectable/#scope-aircrafttype) make an aircraft a loaner in the same way, and any one of the three is enough.

```ini title="rules.ini"
[MySpyCamera] ; example WeaponType
Camera=yes
```

The flag changes nothing else. Despite its name, the weapon reveals no area and fires as an ordinary shot. The same weapon in the second slot, or on a vehicle, infantry or structure, has no effect.
