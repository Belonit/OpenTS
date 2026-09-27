---
key: DissolveUnfilledTeamDelay
summary: The frames an empty team outside a campaign waits before dissolving itself.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: "5000"
---

Outside a campaign, a team is dissolved once it has no members and this many frames have passed since it was created. This clears away a team whose TaskForce the house never managed to fill. A team with at least one member is never dissolved by this delay, and in a campaign the delay does not apply.

A team that has reached [full strength](/systems/ai-team-production/#teamtypes-and-ai-triggers-in-brief) or is under way is dissolved as soon as it loses its last member, in every session type.

Either way, the team's end [records an outcome](/systems/ai-team-production/#the-track-record) against every AI trigger whose first TeamType is the team's type.
