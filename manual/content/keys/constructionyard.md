---
key: ConstructionYard
summary: A BuildingType with this flag animates while a structure it built is going up, refuses ordinary undeploy orders, and starts a computer house's base when an MCV deploys into it.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "no"
---

`ConstructionYard=yes` controls a structure's production animations, when a player can order it to undeploy, whether a computer house starts its base around it, and whether its owner's allies can build off it.

The flag does not make a type count toward its house's construction yards. Only the BuildingTypes named by [`BuildConst`](/keys/buildconst/) count, and the effects below apply to any type with the flag, listed there or not.

## Production animations

A construction yard plays its [`PreProductionAnim`](/keys/preproductionanim/) while a structure it built runs its construction animation, and switches to its [`ProductionAnim`](/keys/productionanim/) when that animation ends. [The thirteen slots](/systems/building-animations/#the-thirteen-slots) lists what starts each animation on other structures.

## Undeploying

A construction yard whose type names an [`UndeploysInto`](/keys/undeploysinto/) vehicle still counts as a structure, not as a [deployed vehicle](/systems/capture/#an-engineer-over-a-structure). A band selection does not pick it up. It can be repaired like any other structure, and engineers and commandos treat it as one.

A player can order a construction yard to undeploy only when **all of** these hold:

- the game is not a campaign game;
- its owner is a human player;
- the MCV redeploy option is on (`MCVRedeploy` in a [spawn file](/formats/spawn-ini/));
- the yard is not stunned.

Even then, a yard whose type has [no construction artwork](/keys/buildup/#a-type-with-no-construction-artwork-cannot-be-sold) ignores the order.

## Bases

When a computer house's MCV deploys into a `ConstructionYard=yes` type outside a campaign game, that house [starts building its base](/systems/ai-base-building/#where-the-plan-comes-from) around it.

When any vehicle deploys into a `ConstructionYard=yes` type, vehicle thieves that were targeting the vehicle drop the target instead of switching to the new structure.

When a match allows [building off an ally](/systems/base-adjacency/#building-off-an-ally) and [`BuildOffAllyAnyStructure=no`](/keys/buildoffallyanystructure/), an ally's structure anchors your placements only if its type sets this flag.

When a player-controlled house loses a construction yard to capture and no longer owns any `BuildConst` type, a structure it was about to place is dropped from the cursor.
