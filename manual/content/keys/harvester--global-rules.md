---
key: Harvester
scope: global-rules
label: IQ threshold
see_also: [IQ, HarvesterUnit, BuildRefinery]
when_omitted:
  kind: value
  value: "3"
---

A computer house whose [`IQ`](/keys/iq/) is at least this value builds harvesters up to a number set by its refineries. Before it chooses any other vehicle to build, it orders a harvester when **all of** the following hold:

- its `IQ` is at least this value;
- it has not been marked [short of Tiberium](/systems/tiberium/#finding-a-patch);
- it owns fewer harvesters than its refineries multiplied by a difficulty factor;
- the harvester type's [`TechLevel`](/keys/techlevel/#scope-aircrafttype) is within the house's tech level.

The difficulty factor is `1` in a campaign game and for a house in the `[Difficult]` difficulty slot, and `2` for every other house. A computer house therefore normally keeps two harvesters per refinery, and one where the factor is `1`.

Every type listed in [`HarvesterUnit`](/keys/harvesterunit/) counts as a harvester, and every type listed in [`BuildRefinery`](/keys/buildrefinery/) counts as a refinery. The house orders the first listed harvester type its country may own, or the first listed type if it may own none.

Once it has ordered a harvester, the house chooses no other vehicle until that harvester leaves the factory or its production is abandoned. When a condition fails, the house chooses its next vehicle from [production demand](/systems/ai-team-production/#production-demand) instead.

:::caution[Keep the harvester's `TechLevel` at `0` or above]
At `TechLevel=-1` the house never orders that harvester type, whatever the house's tech level.
:::

:::note[The difficulty slot is inverted for computer houses]
A computer house is given the `[Difficult]` slot at the player's Easy setting, so that is where the factor of `1` applies. [From the setting to a slot](/systems/difficulty/#from-the-setting-to-a-slot) covers the inversion, and [the computer's bonus with more than one human](/systems/difficulty/#the-computers-bonus-with-more-than-one-human) covers the further shift a session with several people applies on top of it.
:::
