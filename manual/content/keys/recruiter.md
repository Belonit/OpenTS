---
key: Recruiter
summary: Whether a team of this type may recruit an object whose group does not match its own.
see_also: ["system:ai-team-production", Group]
when_omitted:
  kind: value
  value: "no"
---

With `Recruiter=yes`, a team [recruits](/systems/ai-team-production/#recruitment) from every object its house owns, whatever the object's group. Without it, the team considers only objects in its own group. The exception is a team whose group is `-2`, which considers every object either way. A team on any other group that no object shares recruits nobody without this setting.

The group still affects which candidate wins. A candidate outside the team's group is ranked as though it stood 50 cells farther away, so the team takes one only when it is more than 50 cells nearer than every candidate from the group.
