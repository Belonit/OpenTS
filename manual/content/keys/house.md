---
key: House
summary: The house, named by country or start position, that owns teams a trigger action creates from this TeamType.
see_also: [TaskForce, Script, Waypoint, "system:ai-team-production"]
when_omitted:
  kind: value
  value: none
---

`House=` sets the owner of a team that a trigger action creates from this TeamType: [Reinforcement (team)](/mapping/actions/taction-reinforcements/), [Reinforcement (team) at waypoint](/mapping/actions/taction-reinforcements-special/) or [Create Team](/mapping/actions/taction-create-team/).

:::caution[AI trigger teams ignore this setting]
A team raised by the [AI trigger pass](/systems/ai-team-production/#from-suggestion-to-team) belongs to the house whose pass raised it, whatever country this key names. A [Change team](/mapping/missions/tmission-teamchange/) mission gives the new team the old team's house.
:::

The value selects a house in one of two ways:

- A country, given by its ID or its [`Name=`](/keys/name/) string, selects the house in the match that plays that country.
- A [spawn house](/formats/scenario-objects/#spawn-houses), `Spawn1` through `Spawn8` or `<Player @ A>` through `<Player @ H>`, selects the house that starts at that position.

```ini title="ai.ini or map file"
[MyRaidTeam] ; example TeamType
Name=Raid team
House=Nod
TaskForce=MyRaidForce ; defined under [TaskForces]
Script=MyRaidScript   ; defined under [ScriptTypes]
```

The owner is the house the team's members are created for, and the only house the team can recruit from. The team also counts among that house's teams for [the team budget](/systems/ai-team-production/#the-team-budget) and, outside a campaign, for [`Max`](/keys/max/).

A file read later that defines the same TeamType without `House` keeps the owner an earlier file set. An owner that came from a spawn house is kept only as its country, so the later read gives the team to the first house in the match playing that country, which can be a different house.

:::caution[A team with no owner is never created]
The team has no owner when the value names a country no house in the match plays, or a spawn house nobody holds. A name that matches no country, `<none>` included, registers a new country under that name, and no house plays that country either. The reinforcement actions then deliver nothing, and Create Team creates no team.
:::
