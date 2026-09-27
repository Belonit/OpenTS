---
key: Reinforce
summary: Whether a team of this type keeps recruiting after it has begun to move.
see_also: ["system:ai-team-production", "system:ai-team-execution", Max]
when_omitted:
  kind: value
  value: "no"
---

`Reinforce=yes` lets a team replace its losses. Without it, a team [recruits](/systems/ai-team-production/#recruitment) only until it starts moving, and members it loses afterward are never replaced. With it, a computer house's team that is short of full strength keeps recruiting for the rest of its life. A human house's team stops recruiting once it has reached full strength or started, whatever this setting says.

The same rule decides which teams add to the house's [production demand](/systems/ai-team-production/#production-demand). A `Reinforce=yes` team asks for its missing members whenever it is short of full strength. Any other team asks only until it is [forced active](/systems/ai-team-execution/#the-state-flags), reaches full strength, or starts moving.

`Reinforce=yes` also lets a team be pulled back off its Script to regroup. A team is sent back only while it is under strength:

- A `Reinforce=no` team is never under strength after it first reaches full strength or starts moving, however many members it loses afterward. It is therefore never sent back.
- A `Reinforce=yes` team becomes under strength when it is down to a third of full strength, rounded down, or fewer. If its TaskForce asks for only one or two members, it becomes under strength as soon as it is short of full.

An under-strength team is stopped and sent to regroup. It sets out again once recruitment has brought it back to full strength. A team created by a reinforcement trigger action is forced active and sets out again at once. Either way, [it restarts its Script from the first line](/systems/ai-team-execution/#every-regroup-rewinds-the-script). Set `Reinforce=yes` only on a TeamType whose Script can safely start over.
