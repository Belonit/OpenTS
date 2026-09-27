---
key: Autocreate
summary: Which of an object's two recruitable states a team of this type reads when it recruits.
see_also: ["system:ai-team-production", AreTeamMembersRecruitable, Recruiter]
when_omitted:
  kind: value
  value: "no"
---

`Autocreate=yes` marks the TeamType as autocreated. The mark decides which of an object's two recruitable states a team of this type checks when it [recruits](/systems/ai-team-production/#recruitment):

- a team of an unmarked TeamType takes only objects whose ordinary recruitable state is set;
- a team of a marked TeamType takes only objects whose autocreate-recruitable state is set.

Each kind of team ignores the other state. Both states start set on every object, so the mark makes a difference only after one of them is cleared. A map's [placed-object record](/formats/scenario-objects/) can clear either state, and joining a team whose TeamType sets [`AreTeamMembersRecruitable=no`](/keys/areteammembersrecruitable/) clears the autocreate-recruitable state.

:::caution[An AI trigger marks its TeamTypes for the rest of the scenario]
Every TeamType the AI trigger pass [goes on to create teams from](/systems/ai-team-production/#from-suggestion-to-team) is marked as autocreated and stays marked for the rest of the scenario. `Autocreate=no` therefore lasts only until the AI trigger pass first goes on to create teams from the TeamType. [Trigger selection](/systems/ai-team-production/#which-triggers-are-eligible) does not read the mark.
:::
