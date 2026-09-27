---
key: Fire
summary: The blast cracks the ice it lands on, and the attack cursor stops offering destroyable cliffs.
see_also: [Wall, Sparky]
when_omitted:
  kind: value
  value: "no"
---

In a theater with [ice](/keys/isicegrowthenabled/), which by default is only the snow theater, a blast cracks the ice tile it lands on. If the tile is already cracked, the ice gives way. A blast at or above the deck of a bridge cracks nothing.

[`Wall=yes`](/keys/wall/#scope-warheadtype) cracks ice the same way, so a wall-destroying warhead does not also need `Fire=yes`. Despite its name, the flag starts no fires; [`Sparky=yes`](/keys/sparky/) does that.

```ini title="rules.ini"
[MyFlameWH] ; example WarheadType
Fire=yes
```

:::danger[Ice that gives way becomes open water]
When a blast breaks cracked ice, the cell turns into open water. A vehicle on it sinks and is stunned, unless its [`MovementZone`](/keys/movementzone/) is one of the amphibious zones. Infantry and landed aircraft on it are taken off the map. Each sinking vehicle and each removed object leaves a wake.
:::

A player's object normally offers the attack cursor over a destroyable cliff, even when nothing stands there to shoot. An object whose first weapon uses a `Fire=yes` warhead does not. Only the first weapon counts, so a second weapon with an ordinary warhead does not restore the cursor.

The cliff itself is unaffected. A `Fire=yes` blast that lands on the cliff by any other route, such as a forced attack, has the usual chance to collapse it.
