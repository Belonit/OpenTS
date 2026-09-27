---
key: ShroudRate
summary: Game minutes between shroud regrowth passes.
see_also: ["system:map-visibility", ShroudGrow]
when_omitted:
  kind: value
  value: "4"
---

While [`ShroudGrow=yes`](/keys/shroudgrow/), a [shroud pass](/systems/map-visibility/#shroud-regrowth) runs every `ShroudRate` game minutes, 900 frames each. Each pass covers one more unwatched cell at the edge of the revealed area, so a smaller value closes the shroud in faster. `ShroudRate=0` stops the regrowth, the same as `ShroudGrow=no`.

```ini title="rules.ini"
[AudioVisual]
ShroudRate=2 ; the shroud creeps back one cell every two game minutes
```

On a map revealed only by the starting units, the first pass changes nothing visible, because those units still see every cell they revealed.
