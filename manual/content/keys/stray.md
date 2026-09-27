---
key: Stray
summary: Distance in cells a team member may drift from the team before it is ordered back.
see_also: [CloseEnough, GuardSlower, "system:ai-team-execution"]
when_omitted:
  kind: value
  value: "2"
  note: "512 leptons."
---

`Stray` is how far a team member may be from where the team wants it before the team orders it there. The value is in cells, and fractions are accepted. A larger value lets a team spread out more before it pulls members back.

The team applies this distance in several tests:

- A newly recruited member farther than this from the team's center is sent to the center. Until it comes within this distance, it holds up the team's arrival at a move target.
- While the team regroups, any member farther than this from the center is sent back to it.
- While the team moves, a member farther than this from the move target is ordered toward it. An aircraft is allowed three times the distance.
- One team mission sends a member back to the center only once it is more than twice this distance away.

[Team execution](/systems/ai-team-execution/#keeping-the-members-together) sets out each test and the exceptions to it.

One path test outside team coordination also reads this key. When an infantry unit or vehicle searches for a path to a cell that is temporarily blocked, it may head for a reachable free cell nearby instead, but only while it is farther from the blocked cell than its check distance. A team member uses this key as its check distance. Every other object uses [`CloseEnough`](/keys/closeenough/). A train never takes the detour.
