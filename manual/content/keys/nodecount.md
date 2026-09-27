---
key: NodeCount
summary: The number of base node entries read from the house's section.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "0"
---

`NodeCount` sets how many entries of a house's base plan are read. The entries use the zero-padded three-digit keys `000` upward, read in order, so a `NodeCount` of `4` reads `000` through `003` and ignores `004` and any later entry. [Where the plan comes from](/systems/ai-base-building/#where-the-plan-comes-from) covers the entry format and how a supplied plan stops the house from generating one.

An entry whose type does not start with `-` and matches no BuildingType ID becomes a `-1` node, a base-defense placeholder whose type and cell the planner picks.

:::caution[Write every entry the count covers]
Give each key from `000` up to one below `NodeCount` a type and both cell coordinates. A missing entry, or one without both coordinates, crashes the game while the scenario loads.
:::

In a campaign, the house reads `NodeCount` from the section named after it, such as `[GDI]`. In a skirmish or multiplayer game, a house reads `NodeCount` from the [spawn house](/formats/scenario-objects/#spawn-houses) section of the start position it holds, `[Spawn1]` through `[Spawn8]`, and only on a map that sets [`UseMPAIBaseNodes=yes`](/keys/usempaibasenodes/).
