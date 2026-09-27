---
key: AtomDamage
summary: Raw damage of a fallback nuclear blast that never occurs in play.
no_effect: true
see_also: ["NukeWarhead", "MaxDamage", "ExpSpread"]
when_omitted:
  kind: value
  value: "1000"
---

No detonation in play deals this damage. The value belongs to a fallback nuclear blast that runs only when a nuclear shot's explosion animation cannot be created, and creating an animation never fails.

If the fallback did run, it would be a [wide-area blast](/systems/warheads/#the-wide-area-blast) through [`[SpecialWeapons] NukeWarhead`](/keys/nukewarhead/) around the detonation cell, credited to no house:

| Game | Radius | Raw damage |
| --- | --- | --- |
| Campaign | 4 cells | The value as written |
| Skirmish or multiplayer | 3 cells | One fifth of the value, rounded down |

Each cell's share of a wide-area blast rises toward the rim, as [`ExpSpread`](/keys/expspread/) describes. The center and rim cells take the full raw damage or more, and the cells between them take less.

Every nuclear shot deals the ordinary blast of its weapon's damage, like any other shot. The fallback would only have added the wide-area blast on top of it.
