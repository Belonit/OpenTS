---
key: IsBaseDefense
scope: teamtype
label: Defensive team
when_omitted:
  kind: value
  value: "no"
---

`IsBaseDefense=yes` makes every team of this type a defensive team. Each defensive team counts toward its house's defensive teams for as long as it exists. The flag and that count have three effects.

**Which AI triggers a house considers.** An AI trigger is defensive when its first TeamType is defensive and its second is defensive or absent. While [`UseMinDefenseRule`](/keys/usemindefenserule/) is on and the house has fewer defensive teams than [`MinimumAIDefensiveTeams`](/keys/minimumaidefensiveteams/), the house considers only defensive triggers. [Defensive teams and the enemy](/systems/ai-team-production/#defensive-teams-and-the-enemy) gives the full rule.

**The team budget.** A house with more defensive teams than [`MaximumAIDefensiveTeams`](/keys/maximumaidefensiveteams/) skips defensive triggers. A house that holds at least [`TotalAITeamCap`](/keys/totalaiteamcap/) teams, and whose defensive teams number at least half its team count rounded down, deletes its oldest defensive team. [The team budget](/systems/ai-team-production/#the-team-budget) gives the exact conditions.

**Base defense.** A member of a defensive team can be [called back to defend the base](/systems/base-attacked/#which-objects-qualify). A member of any other team cannot. A called-back member of a defensive team always takes the Area Guard mission, never Rescue.
