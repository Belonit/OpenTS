---
key: Waypoint
summary: The waypoint a team of this type starts at and recruits around.
see_also: [House, TaskForce, Recruiter, "system:ai-team-production", "system:ai-team-execution"]
when_omitted:
  kind: value
  value: none
---

The waypoint this key names is the team's origin. The value is a letter label, not a number. `A` is waypoint `0` and `Z` is `25`. Two-letter labels continue from `AA` at `26`, so `AB` is `27` and `BA` is `52`.

Case does not matter, and only the first two characters count. A second character that is not a letter is ignored, so `A1` reads as `A`. A value that does not begin with a letter, such as a bare waypoint number, gives the team no origin.

```ini title="ai.ini or map file"
[MyRaidTeam] ; example TeamType
Name=Raid team
House=Nod
TaskForce=MyRaidForce ; defined under [TaskForces]
Script=MyRaidScript   ; defined under [ScriptTypes]
Waypoint=A
```

The label is matched against the current scenario's waypoints each time the origin is used, so a team type in `ai.ini` can name a waypoint that each map places for itself. If the scenario has not placed that waypoint, a Release build treats the team as having no origin. A Debug build stops at a [failed assertion](/systems/developer-mode/#assertions) when a team of this type is created.

The origin controls five things:

- [Recruitment](/systems/ai-team-production/#recruitment) ranks candidate members by their distance from the origin, not from the team.
- An infantry or vehicle member on the Retreat mission heads for the map edge nearest the origin. Without an origin, it heads for the edge nearest itself. Aircraft on the Retreat mission ignore the origin.
- An aircraft other than a dropship picks its landing zone near the origin when it unloads a passenger that belongs to a team of this type.
- A group delivered by the [Reinforcement (team)](/mapping/actions/taction-reinforcements/) action arrives at the origin, or at the map edge nearest it when the group enters across the edge. Without an origin, a group that enters across the edge uses its house's [`Edge`](/keys/edge/). The [Reinforcement (team) at waypoint](/mapping/actions/taction-reinforcements-special/) action uses the waypoint it names instead.
- After a Reinforcement (team) delivery that EVA announces, [Goto Radar Event](/commands/centeronradarevent/) jumps to the origin, not to the cell where the group entered.

The origin is not the team's center. A new team uses the origin as its center only until its first logic pass, which [computes the center from the team's members](/systems/ai-team-execution/#the-teams-center).

:::danger[Keep the label at `CW` or earlier]
A scenario has 101 waypoints, `A` through `CW`. `A` through `CT` are the 98 ordinary ones. `CU`, `CV` and `CW` are reserved for the scenario's home cell, reinforcement cell and special airdrop cell. A label from `CX` onward names a waypoint past the end of the list. A Release build then reads the origin cell from unrelated memory, and a Debug build stops at a failed assertion.
:::
