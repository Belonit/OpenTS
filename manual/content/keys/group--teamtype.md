---
key: Group
scope: teamtype
label: Team recruitment group
see_also: ["system:ai-team-production", Recruiter]
when_omitted:
  kind: value
  value: "-1"
  note: A TeamType left at -1 takes the group of its TaskForce, which is itself -1 unless that section sets one.
---

A team [recruits](/systems/ai-team-production/#recruitment) only objects in its group. Each object that joins is put in the team's group, so the next team to look for members finds it there.

Two settings widen the search:

- `Group=-2` lets the team consider every object, but any object not already in group `-2` counts as 50 cells farther away than it is. Its members are put in group `-2` when they join.
- [`Recruiter=yes`](/keys/recruiter/) also lets the team consider every object, but it still prefers objects in its group. Any other candidate counts as 50 cells farther away than it is.

An object's group starts at `-1`. Three things can put it in another group: a map's [placed-object record](/formats/scenario-objects/), the [Set Group ID](/mapping/actions/taction-set-group-id/) trigger action, and the player assigning the object to a control group. The first control group is group `0`. Unless it is `Recruiter=yes`, a TeamType that leaves both its own and its TaskForce's `Group` unset therefore recruits only objects still in group `-1`. When the player's house owns such a team, it skips objects the player has put in a control group.

The group is the same number that Set Group ID assigns, that a control group uses, and that [Wakeup group](/mapping/actions/taction-wakeup-group/) matches. Joining a team therefore replaces a group a trigger gave the object, and it takes the object out of its control group.
