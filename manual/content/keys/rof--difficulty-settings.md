---
key: ROF
scope: difficulty-settings
label: Difficulty reload multiplier
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1"
  note: Every file that contains the difficulty section resets the settings it leaves out, so a later file with the section but without this key restores 1.
---

`[Easy]`, `[Normal]` and `[Difficult]` each set their own multiplier. A house uses the one for [the difficulty slot it is assigned](/systems/difficulty/#from-the-setting-to-a-slot).

The multiplier scales the delay between an object's shots, so a value above 1 fires more slowly. With the example below, objects of a house that takes its handicap from `[Difficult]` wait about 20% longer after each shot. The multiplier does not reach a shot inside a burst, a beam or particle weapon's delay, or a structure still holding more than one round. [The weapon's `ROF` page](/keys/rof/#scope-weapontype) describes each case.

```ini title="rules.ini"
[Difficult]
ROF=1.2
```

In a campaign game this multiplier applies alone. In skirmish and multiplayer it is multiplied by the [country's multiplier](/keys/rof/#scope-housetype), as [the difficulty page](/systems/difficulty/#how-the-figures-are-combined) describes.
