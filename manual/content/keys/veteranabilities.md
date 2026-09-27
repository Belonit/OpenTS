---
key: VeteranAbilities
summary: The abilities an object of this type gains at veteran rank and keeps at elite.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: ""
---

A comma-separated list of ability tokens, matched without regard to letter case. An object of this type gains every ability named here when it reaches veteran rank. It keeps them after a promotion to elite, where [`EliteAbilities`](/keys/eliteabilities/) adds more. [The ability table](/systems/veterancy/#abilities) lists the eighteen accepted tokens and what each one does.

```ini title="rules.ini"
[MYTANK] ; example UnitType
VeteranAbilities=FIREPOWER,ROF,SIGHT
```

An unrecognized token is ignored.

A later rules file that sets the key replaces the earlier list; it does not add to it. Leaving the key out of that file keeps the earlier list, and so does writing it with nothing after the `=`, because the game ignores an empty assignment. To clear an earlier list, write a value with no recognized token, such as `VeteranAbilities=none`.

:::caution[Do not put spaces after the commas]
Spaces are removed only from the start and end of the whole value, not around each token. `VeteranAbilities=FIREPOWER, ROF` therefore grants only `FIREPOWER`, because ` ROF` with its leading space is not a recognized token.
:::
