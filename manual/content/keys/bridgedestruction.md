---
key: BridgeDestruction
summary: Starting state of the destroyable-bridges option for a multiplayer or skirmish match.
see_also: [DestroyableBridges, BridgeStrength]
when_omitted:
  kind: value
  value: "yes"
---

`BridgeDestruction` sets the destroyable-bridges option when the game starts. The skirmish setup screen, the network lobby or the spawn settings then replace it for each match, so the value decides only how the option starts out.

Outside a campaign, the option decides whether blasts can damage bridges, and the map's [`DestroyableBridges`](/keys/destroyablebridges/) entry is not read. This is the first half of the test a blast makes on a bridge span. [`BridgeStrength`](/keys/bridgestrength/) covers the roll that follows. A campaign mission ignores the option and uses the map's `DestroyableBridges` entry.

:::caution[One skirmish with bridges off turns them off until restart]
A skirmish applies the option only when it is off, and nothing in a skirmish turns bridge destruction back on. After one skirmish with the option cleared, bridges stay indestructible in every later skirmish until the game is restarted, whatever the option says. A network game applies the agreed option either way, so it turns bridge destruction back on as well as off.
:::
