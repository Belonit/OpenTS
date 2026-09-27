---
key: Annoyance
summary: Makes a team that is under way stop and regroup when an enemy damages one of its members.
see_also: [Suicide, Stray, "system:base-attacked"]
when_omitted:
  kind: value
  value: "no"
---

`Annoyance=yes` makes a team that is under way stop and regroup when an enemy damages one of its members. A team is under way once it has started running its script. A team that is still gathering, or that was sent back to regroup, is not under way. With or without this setting, damage to such a team drops its center and marks it to reform, so once it starts it gathers on a new center before running its script. [Answering damage](/systems/ai-team-execution/#answering-damage) covers both cases.

A team that is under way responds to damage only under **all of** these conditions:

- the attacker is not allied with the team's house and is not a member of the team;
- the team's most recently joined member, which need not be the member that was hit, is not an aircraft and has a primary weapon;
- the attacker is not already the team's current target.

If any condition fails, the team does nothing: it neither regroups nor turns on the attacker, whatever this setting says.

When the conditions hold, a team without this setting takes the attacker as its new target. It keeps its current target instead when that target has a primary weapon and either can fire on the team's center or the team has no center. It never switches to an aircraft attacker. With `Annoyance=yes`, the team first drops its center and reforms. It stops running its script, gathers on a newly computed center, and then resumes the script line it was on.

:::caution[A reforming team keeps an armed target]
The regroup comes before the team decides whether to switch targets, and a team with no center keeps a current target that has a primary weapon. A team of this type that is shooting at something armed therefore stops to reform and never turns on its attacker. A team whose current target is unarmed, or that has no target, takes the attacker as its new target, unless the attacker is an aircraft.
:::

[`Suicide=yes`](/keys/suicide/) switches off the whole response to damage, including this setting.
