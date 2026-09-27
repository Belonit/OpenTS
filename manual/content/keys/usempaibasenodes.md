---
key: UseMPAIBaseNodes
summary: Whether the computer houses of a skirmish or multiplayer game follow the base plans the map wrote for their start positions.
see_also: [NodeCount, PercentBuilt, Allies, "system:ai-base-building"]
when_omitted:
  kind: value
  value: "no"
---

With the key set to `yes`, the house at start waypoint N reads its base node list from the map section `[Spawn<N+1>]`: the house at waypoint `0` reads `[Spawn1]`, and the house at waypoint `7` reads `[Spawn8]`. These sections take the same node list as a campaign house's section: [`NodeCount`](/keys/nodecount/) and entries numbered `000` onward. A campaign game ignores the key.

The list is read for every house at a start waypoint, including a human player's, so a house the computer takes over later follows it too. A section for a waypoint no house starts at is not read. A house that started on open ground because the map's start waypoints ran out is at no start waypoint and reads no list.

With the key set, every computer house builds as a campaign house does. [AI base planning and building](/systems/ai-base-building/) owns the details:

- A node's cell is used as written; it does not have to touch ground the house already holds.
- No power plant is inserted ahead of a node the house cannot power.
- The money-raising and fire-sale interventions are off.
- A destroyed base defense is rebuilt as the same type on the same cell.

A house that reads no node list, or whose section sets no `NodeCount`, starts with an empty list. It generates its own plan when its construction vehicle deploys, and it still builds under the rules above.

```ini title="multiplayer map file"
[Basic]
UseMPAIBaseNodes=yes

[Spawn2] ; whoever starts at waypoint 1
NodeCount=3
000=GACNST,54,71 ; construction yard BuildingType; this node moves onto the yard when it deploys
001=GAPOWR,57,70 ; power plant BuildingType
002=GAPILE,0,0   ; barracks BuildingType; the cell is picked at build time
```
