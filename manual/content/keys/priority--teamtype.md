---
key: Priority
scope: teamtype
label: Team recruitment priority
see_also: ["system:ai-team-production", Max, Recruiter]
when_omitted:
  kind: value
  value: "7"
---

A team can [recruit](/systems/ai-team-production/#recruitment) an object that is already on another team only when its own `Priority` is strictly greater than that team's. Teams with equal values, including all teams left at the default, never take members from each other. The value plays no part in [which AI trigger is drawn](/systems/ai-team-production/#the-weighted-draw) and does not set a build order.

`Priority` also decides which teams a computer house [empties when its base is attacked](/systems/base-attacked/#teams-are-emptied-first): those whose `Priority` is below [`SuspendPriority`](/keys/suspendpriority/). At the default `SuspendPriority`, a team left at the default `Priority` is emptied every time the house calls defenders back. To protect a team, give its TeamType a `Priority` of at least `SuspendPriority`.
