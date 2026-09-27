---
key: Max
summary: How many teams of this TeamType can exist before AI triggers stop raising more.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: "0"
---

A negative value removes the limit. Any other value stops an AI trigger from raising another team of this type once that many exist. The trigger checks the count twice:

1. The trigger [is rejected](/systems/ai-team-production/#which-triggers-are-eligible) when the house already owns this many teams of the type.
2. The creation that follows [checks again](/systems/ai-team-production/#from-suggestion-to-team). Outside a campaign it counts the house's teams of the type, as the first check did. In a campaign it counts every team of the type in the scenario, whichever house owns it and however it was created.

Other ways of creating a team ignore `Max`. These are the [Create Team](/mapping/actions/taction-create-team/), [Reinforcement (team)](/mapping/actions/taction-reinforcements/) and [Reinforcement (team) at waypoint](/mapping/actions/taction-reinforcements-special/) trigger actions and the [Change team...](/mapping/missions/tmission-teamchange/) mission.

:::caution[Set `Max` on every TeamType an AI trigger names]
The default of `0` is a limit of zero teams, not a missing limit. An AI trigger naming a TeamType that never sets `Max` is rejected every time, so that TeamType can be raised only by the trigger actions and mission listed above.
:::
