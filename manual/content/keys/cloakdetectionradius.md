---
key: CloakDetectionRadius
summary: The distance in cells out from a flying jumpjet at which hidden objects are forced back into view.
see_also: ["system:cloaking"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[JumpjetControls]
CloakDetectionRadius=3
```

`CloakDetectionRadius` sets how far a moving jumpjet reveals hidden objects around it. Each frame a jumpjet takes off, flies or lands, it uncloaks every vehicle, infantryman and structure in a square of cells centered on the jumpjet's cell. The square extends this many cells out on each side, so `2` covers a five-by-five block and the Firestorm rules' `3` covers seven by seven.

At the engine default of `0`, the square is only the jumpjet's own cell. A negative value turns the sweep off.

:::caution[A jumpjet also reveals its own side]
The sweep does not check ownership. A jumpjet flying over its own base uncloaks its owner's and allies' hidden objects as well as enemies'. [Losing a cloak](/systems/cloaking/#losing-a-cloak) lists what that costs the objects caught underneath.
:::
