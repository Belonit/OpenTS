---
key: WeedCapacity
summary: Units of weed a house can hold.
see_also: ["system:veins", "Weeder", "Storage"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[General]
WeedCapacity=56 ; the value the stock rules.ini sets
```

Each house can store up to this many units of weed, and the same figure applies to every house. Weed a weeder unloads while its house's pool is full is lost.

When the pool is full and the house's chemical missile superweapon is not ready, the pool is emptied and the weapon's charge starts over. [The weed pool](/systems/veins/#the-weed-pool) covers the full rules, including why weed never becomes credits.

A [`Weeder=yes`](/keys/weeder/#scope-buildingtype) building with [`PipScale=Tiberium`](/keys/pipscale/) shows its house's pool on its pip gauge, not its own contents, with at most this many pips.

:::caution[Set WeedCapacity above 0]
At `0` or below, including when no rules file sets the key, the pool refuses every unit: weeders load, drive home and unload, and the pool stays empty.
:::
