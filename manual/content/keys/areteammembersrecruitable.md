---
key: AreTeamMembersRecruitable
summary: Sets each joining object's permission to be recruited by teams with Autocreate=yes.
see_also: ["system:ai-team-production", Autocreate, Priority]
when_omitted:
  kind: value
  value: "yes"
---

`AreTeamMembersRecruitable=no` prevents teams whose TeamType currently has [`Autocreate=yes`](/keys/autocreate/) from recruiting objects that joined this team. It also excludes those objects from a [base defense call-up](/systems/base-attacked/#which-objects-qualify). With `yes`, this setting permits both, subject to their other requirements.

Each object that joins takes this value as its autocreate-recruitable permission, regardless of this team's own `Autocreate` value. Leaving the team or deleting the team does not reset the permission. Joining another team replaces it with that TeamType's value.

The ordinary recruitable permission is unchanged. Teams whose TeamType currently has `Autocreate=no` can still recruit the object if it meets their other requirements. The [AI-trigger pass](/systems/ai-team-production/#from-suggestion-to-team) changes its selected TeamTypes to `Autocreate=yes`, so those teams use the autocreate-recruitable permission.
