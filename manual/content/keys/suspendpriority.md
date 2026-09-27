---
key: SuspendPriority
summary: The TeamType priority a team must reach to survive a base attack.
see_also: ["system:base-attacked", Priority, SuspendDelay]
when_omitted:
  kind: value
  value: "20"
---

When a computer house calls defenders back after an attack, it empties every team it owns whose TeamType [`Priority`](/keys/priority/#scope-teamtype) is below `SuspendPriority`. Each emptied team is suspended for [`SuspendDelay`](/keys/suspenddelay/) minutes, and its former members become free to be [called back as defenders](/systems/base-attacked/#teams-are-emptied-first). A team whose `Priority` is equal to or above this value keeps its members and carries on.

Only the TeamType's `Priority` is compared. No per-house or per-difficulty value enters the test.

```ini title="rules.ini"
[General]
SuspendPriority=6 ; a team on the default Priority of 7 now survives a base attack
```

Not every attack starts a call-up. [When the call-up is refused](/systems/base-attacked/#when-the-call-up-is-refused) lists the attacks that call no one back and so suspend no team.

:::caution[Default priorities put every team below the built-in threshold]
A TeamType that does not set `Priority` has `7`, below this key's built-in `20`. With neither key set, every call-up empties all of the attacked house's teams. The shipped rules set `SuspendPriority=1`, so teams on the default priority survive. Set this key to the lowest priority that should survive, or raise those TeamTypes' `Priority` to at least this value. A value below every priority in use suspends no team.
:::
