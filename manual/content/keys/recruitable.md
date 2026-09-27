---
key: Recruitable
summary: Whether an object in this mission may be taken onto a team.
see_also: ["system:ai-team-production", "system:base-attacked"]
when_omitted:
  kind: value
  value: "yes"
---

At `Recruitable=no`, no team can [recruit](/systems/ai-team-production/#recruitment) an object while it is on this mission. The setting is read from the mission the object is currently in.

```ini title="rules.ini"
[Sleep]
Recruitable=no
```

A computer house also leaves such an object out when it counts [the objects it already has for its teams](/systems/ai-team-production/#production-demand). It may therefore build another object of the same type to fill a team.

In a campaign, the [base defense call-up](/systems/base-attacked/#which-objects-qualify) also skips an object on a `Recruitable=no` mission. In skirmish and multiplayer games the call-up ignores the setting, so such an object can still be called back if it qualifies otherwise.
