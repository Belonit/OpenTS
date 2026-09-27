---
key: Armor
scope: difficulty-settings
label: Difficulty damage divisor
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section but not this key resets the figure to 1.
---

Damage to a house's vehicles, infantry, aircraft and structures is divided by this figure, so a figure above 1 makes the house tougher and one below 1 more fragile. `[Easy]`, `[Normal]` and `[Difficult]` each set a figure, and a house uses the one for [the difficulty slot it is assigned](/systems/difficulty/#from-the-setting-to-a-slot).

Outside a campaign, the figure is multiplied by the house's [country `Armor=`](/keys/armor/#scope-housetype) when the house is given its slot. In a campaign, the country figure is ignored and this one is used alone. [How the figures are combined](/systems/difficulty/#how-the-figures-are-combined) covers both cases.

The division skips healing and forced damage. Any armor crate bonus the object has picked up divides the damage in the same step, and the veteran armor bonus divides it afterward. If these divisions leave less than one point, the hit deals one point, so no figure here can reduce a hit to nothing. [What the target loses](/systems/warheads/#what-the-target-loses) lists the remaining steps.

:::caution[A zero makes the house nearly invulnerable]
Keep all three difficulty sections present and the figure above `0`. A difficulty section missing from every rules file leaves its figure at `0`, and so does writing `0` directly. A house in that slot has every hit cut to one point before the warhead's [`Verses`](/keys/verses/) apply, so even the heaviest shot deals no more than a one-point hit would.
:::
