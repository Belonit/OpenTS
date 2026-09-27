---
key: Image
scope: tiberium
label: Tiberium overlay variant
when_omitted:
  kind: value
  value: "none"
  note: The type has no overlay set, which can crash the game.
---

`Image` selects the overlay set that draws this Tiberium type:

| Value | Overlay set |
| --- | --- |
| `1`, or any value not listed here | The standard Tiberium set |
| `2` | The large-Tiberium set |
| `3` | The second Tiberium set |
| `4` | The third Tiberium set |
| `-1` | None, the same as leaving the key out |

Every set has twelve growth stages. Only the large-Tiberium set has no slope overlays, so a type that uses it never spreads onto a slope and is not drawn on one.

:::caution[Give every Tiberium type an Image from 1 to 4]
A Tiberium type with `Image=-1`, or with no `Image`, has no overlay set. The game can crash as soon as any Tiberium is on the map.
:::
