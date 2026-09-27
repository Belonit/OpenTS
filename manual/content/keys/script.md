---
key: Script
summary: The Script whose team missions a team of this type carries out.
see_also: [TaskForce, House, Tag, "system:ai-team-production"]
when_omitted:
  kind: value
  value: none
---

A team built from this TeamType carries out the named Script's team missions one line at a time. When it runs past the last line, the team is disbanded and its members stay on the map. Each team keeps its own place in the Script, so several teams of the same type can be on different lines at once.

```ini title="ai.ini or map file"
[MyRaidTeam] ; example TeamType
Name=Raid team
House=Nod
TaskForce=MyRaidForce ; defined under [TaskForces]
Script=MyRaidScript   ; defined under [ScriptTypes]
```

The value is matched against the IDs registered under `[ScriptTypes]`. A name that is not registered there is not an error. The game creates a new, empty Script under that name, so a misspelled name gives the team no missions. A team with an empty Script is disbanded when it tries to run its first line.

The [Reinforcement (team)](/mapping/actions/taction-reinforcements/) and [Reinforcement (team) at waypoint](/mapping/actions/taction-reinforcements-special/) actions handle an empty Script differently. Each adds an attack-waypoint mission to the Script itself, so every later team that uses that Script also gets the mission.

:::danger[Give every TeamType a Script]
`<none>`, `none` or a missing `Script=` leaves the TeamType with no Script at all, and teams of that type crash the game:

- Either reinforcement action crashes before it creates any object.
- A team created any other way crashes when it starts. It can crash earlier, while it gathers, if one of its members is underground or is an aircraft in the air.

Name a Script on every TeamType, even one with no missions.
:::
