---
key: AreTeamMembersRecruitable
summary: The autocreate-recruitable state written onto each object as it joins a team of this type.
see_also: ["system:ai-team-production", Autocreate, Priority]
when_omitted:
  kind: value
  value: "yes"
---

Each object that joins a team of this type takes this value as its autocreate-recruitable state. With `AreTeamMembersRecruitable=no`, no [autocreated team](/systems/ai-team-production/#recruitment) can recruit the object, and a [base defense call-up](/systems/base-attacked/#which-objects-qualify) passes it over. Every TeamType the [AI trigger pass](/systems/ai-team-production/#from-suggestion-to-team) creates teams from is marked as autocreated, so AI trigger teams cannot recruit it either.

The state stays after the object leaves the team, and after the team is gone. It changes only when the object joins another team, which sets it to that TeamType's value.

The object's ordinary recruitable state is unaffected. A team whose TeamType is not marked as autocreated can still recruit it.
