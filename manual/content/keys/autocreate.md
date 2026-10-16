---
key: Autocreate
summary: Selects the recruitment permission a team requires from each candidate object.
see_also: ["system:ai-team-production", AreTeamMembersRecruitable, Recruiter]
when_omitted:
  kind: value
  value: "no"
---

`Autocreate` decides which recruitment permission a team checks on each infantry, vehicle, or aircraft it might recruit. Both kinds of team use a TeamType; the choice depends on that TeamType's current `Autocreate` value.

| TeamType's current value | Permission required on the candidate |
| --- | --- |
| `Autocreate=no` | Ordinary recruitable permission |
| `Autocreate=yes` | Autocreate-recruitable permission |

The other permission is not checked by that team. Both permissions start enabled, but a map's [placed-object record](/formats/scenario-objects/) can disable either one for a particular object. Joining a team also replaces the object's autocreate-recruitable permission with that TeamType's [`AreTeamMembersRecruitable`](/keys/areteammembersrecruitable/) value. The remaining [recruitment requirements](/systems/ai-team-production/#recruitment) still apply.

`Autocreate=yes` does not cause teams to be created automatically. The [AI-trigger system](/systems/ai-team-production/#when-the-pass-runs) controls automatic team creation and does not require this setting to be `yes` when it selects a TeamType.

:::caution[AI selection changes the TeamType's value]
The AI-trigger pass [sets `Autocreate` to `yes`](/systems/ai-team-production/#from-suggestion-to-team) on each TeamType it proceeds to create teams from, even if the INI set it to `no`. The value stays `yes` for the rest of the scenario. This changes the permission checked by all teams of that type, including existing teams and teams later created by map trigger actions.
:::
