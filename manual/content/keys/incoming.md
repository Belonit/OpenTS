---
key: Incoming
summary: The projectile speed below which infantry fire can make the target cell's occupants scatter.
see_also: ["Speed", "Primary", "PlayerScatter", "Scatter"]
when_omitted:
  kind: value
  value: "0"
---

When an infantryman's firing animation reaches its launch point, the target's cell is warned that a threat is coming if the infantryman's weapon is slow. The warning is raised even when the shot is called off at that point.

The weapon tested is always the infantry type's [`Primary`](/keys/primary/) weapon, or its [`Elite`](/keys/elite/) weapon once the infantryman is elite, whichever weapon it fires. It counts as slow when its speed is strictly below this value. The stock rules use `10`. At `0` no weapon is slow enough, so infantry fire never raises the warning.

Only infantry fire reads this setting. Aircraft fire also warns the target's cell, but does not check this value.

This value uses the same 0 to 100 scale as a weapon's [`Speed`](/keys/speed/#scope-weapontype). Values outside that range are clamped into it.

A weapon whose projectile has [`ROT=0`](/keys/rot/#scope-bullettype) does not use its written `Speed`. Its launch speed is worked out from its range and gravity once the rules are read, and that speed is the one compared.

Occupants of a warned cell scatter under the conditions in [`PlayerScatter`](/keys/playerscatter/#when-a-threat-is-coming).
