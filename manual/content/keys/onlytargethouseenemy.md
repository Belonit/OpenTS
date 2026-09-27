---
key: OnlyTargetHouseEnemy
summary: Restricts the team's scripted target choice to the owner's declared enemy.
see_also: [Suicide, "system:base-attacked", "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

With this set, three script missions pick a target only from [the house's declared enemy](/systems/base-attacked/#anger-and-the-declared-enemy):

- On an [Attack](/mapping/missions/tmission-attack/) mission, the team leader's search for a target skips every object the declared enemy does not own.
- Without this setting, the two building-with-property missions, attack and move to, pick a matching building of the declared enemy first and otherwise take one owned by any other non-allied house. With it, they skip that second choice and pick no building when the declared enemy has none.

A mission that finds no target ends, and the team moves on to the next line of its script.

The filter has one gap on the Attack mission, and it depends on the team's leader. The leader is the most recently joined member that is [in formation](/systems/ai-team-execution/#bringing-a-member-into-formation), armed or not.

- If a computer house's unarmed engineer leads, it picks the building its house wants recaptured when that building is within 15 cells.
- If a vehicle thief leads, it picks the vehicle it is already heading for when that vehicle is within 15 cells and is not a train.

In both cases the owner of the target does not matter.

:::caution[A house with no declared enemy finds no target]
A house that has never been given an enemy refuses every candidate. A campaign house [starts without one](/systems/base-attacked/#picking-a-first-enemy) and gains one only when damage or a Make enemy trigger action raises its anger. An `OnlyTargetHouseEnemy=yes` team that reaches one of these missions before then finds no target and moves on to the next line of its script.
:::

The setting does not restrict the members' own targeting. Each member still [scans](/systems/target-selection/#when-an-object-scans) for targets and [retaliates](/systems/target-selection/#retaliation) whichever house the target belongs to.
