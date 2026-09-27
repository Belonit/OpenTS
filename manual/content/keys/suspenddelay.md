---
key: SuspendDelay
summary: Minutes of game time a team stays suspended after a base attack emptied it.
see_also: ["system:base-attacked", SuspendPriority]
when_omitted:
  kind: value
  value: "2"
---

`SuspendDelay` is how long a team stays suspended after a base defense call-up [empties it](/systems/base-attacked/#teams-are-emptied-first). A suspended team loses all its members but is not deleted. It does nothing until the delay runs out. [`SuspendPriority`](/keys/suspendpriority/) decides which teams are suspended.

```ini title="rules.ini"
[General]
SuspendDelay=.5  ; suspended teams sit out half a minute
```

When the delay runs out, the outcome depends on whether the team has ever started. A team has started once it has held every member its TaskForce asks for, or once it was brought in as a reinforcement.

- A team that has started is deleted.
- A team that never started begins recruiting again. Outside a campaign, it is deleted if it is still empty and older than [`DissolveUnfilledTeamDelay`](/keys/dissolveunfilledteamdelay/). In a campaign, it stays and keeps recruiting.

A shorter delay brings either outcome sooner.

Every team suspended by the same call-up gets the same delay. A later call-up restarts the delay from the beginning for every team it suspends, including teams that are still suspended.
