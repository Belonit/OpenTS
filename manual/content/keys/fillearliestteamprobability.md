---
key: FillEarliestTeamProbability
summary: The percent chance that the next vehicle, infantryman or aircraft chosen goes to the oldest waiting team, one entry per difficulty.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: ""
  note: A computer house uses an undefined chance.
---

`FillEarliestTeamProbability` is the percent chance that a computer house builds for its oldest waiting team first. The house draws it each time it [chooses the next vehicle, infantryman or aircraft](/systems/ai-team-production/#production-demand) to build for its teams. Vehicles, infantry and aircraft each make a separate draw.

- **Draw succeeds:** the house builds the candidate type wanted by its oldest waiting team.
- **Draw fails:** the house picks at random from a list of candidate types, with equal chances. The list does not favor the types in greatest demand; [Production demand](/systems/ai-team-production/#production-demand) explains which types it holds.

Write one percentage for each [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot), slot 0 first. A computer house uses the entry for its slot. With the menu's settings, the first entry applies when the player chose Hard and the last when the player chose Easy, unless [the multiplayer bonus](/systems/difficulty/#the-computers-bonus-with-more-than-one-human) moves the house down a slot. Write all three entries; a house whose slot lies past the end of a shorter list uses an undefined chance.

```ini title="rules.ini"
[General]
FillEarliestTeamProbability=100,80,60 ; player on Hard, Normal, Easy
```
