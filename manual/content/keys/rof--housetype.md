---
key: ROF
scope: housetype
label: Country reload multiplier
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1.0"
---

The value scales the delay between shots for every object owned by a house of this country, so a value above 1 fires more slowly. It applies in skirmish and multiplayer games only. There, [the weapon's `ROF`](/keys/rof/#scope-weapontype) is multiplied by this value and by the [difficulty multiplier](/keys/rof/#scope-difficulty-settings) before the weapon page's other adjustments. A campaign game ignores this value and uses the difficulty multiplier alone.

```ini title="rules.ini"
[Nod]
ROF=1.25 ; outside a campaign, Nod objects wait about 25% longer between shots
```

The multiplier does not reach a shot inside a burst, a beam or particle weapon's delay, or a structure still holding more than one round. The weapon's `ROF` page describes each of these cases, and [the difficulty page](/systems/difficulty/#how-the-figures-are-combined) shows how the country and difficulty figures combine.
