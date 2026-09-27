---
key: Sparky
summary: Buildings knocked down a damage level burn with the fire set, and terrain objects struck catch fire.
see_also: [OnFire, SmallFire, Wood, Fire]
when_omitted:
  kind: value
  value: "no"
---

`Sparky=yes` has two effects. A structure this warhead damages shows flames from the [`OnFire`](/keys/onfire/) set when it drops a damage level, and a terrain object it damages catches fire.

```ini title="rules.ini"
[MyShellWH] ; example WarheadType
Sparky=yes
```

A structure drops a damage level when a hit takes it below half strength, or below the [`ConditionRed`](/keys/conditionred/) fraction. A hit that destroys the structure shows no flames.

When a hit drops the structure a damage level, each cell of its foundation rolls for a flame, and every flame stays attached to the structure. Each cell picks a whole number from `0` up to 5 plus the structure's width plus its height, in cells:

| Roll | Result |
| --- | --- |
| `1` to `5` | The first `OnFire` entry, looping one to three times |
| `6` to `8` | The second entry, looping one to three times |
| `9` | The third entry, once |
| Anything else | No flame in that cell |

The flame results stay fixed while the range grows with the foundation, so the chance of a flame per cell depends on the structure's size. It is 7 in 8 for a one-by-one structure, peaks at 9 in 10 when width plus height is 4, and falls for anything larger, to 3 in 4 for a three-by-three structure. The third entry needs a width plus height of at least 4, so a one-by-one structure never shows it.

Without `Sparky`, each foundation cell instead has an even chance of the [`SmallFire`](/keys/smallfire/) animation. It gets none when an engineer caused the damage.

A terrain object hit by this warhead catches fire when **all of** these hold:

- the warhead is [`Wood=yes`](/keys/wood/); without it the warhead cannot damage terrain objects at all;
- the terrain type is not [`Immune=yes`](/keys/immune/#scope-aircrafttype);
- the terrain type's [`Armor`](/keys/armor/#scope-aircrafttype) is `wood`;
- the terrain type is not [`SpawnsTiberium=yes`](/keys/spawnstiberium/);
- the hit dealt damage after armor and distance;
- the object is not already burning or crumbling.

Its flames come from [`TreeFire`](/keys/treefire/).

:::danger[Give `OnFire` three entries]
Set [`OnFire`](/keys/onfire/) to three animations before any warhead uses `Sparky=yes`. A flame roll that lands on a missing entry crashes the game or shows an arbitrary animation. `OnFire` is empty until a rules file sets it, and with it empty most structures crash the game on their first knock-down by this warhead.
:::
