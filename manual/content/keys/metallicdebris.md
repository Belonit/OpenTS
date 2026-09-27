---
key: MetallicDebris
summary: Wreckage animations thrown up by ion storm strikes, collapsing bridges, and destroyed objects with no debris types of their own.
see_also: [IonStormWarhead, "system:ion-storms"]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
MetallicDebris=MYDEBRIS1,MYDEBRIS2 ; AnimTypes registered in [Animations]
```

Three events create animations picked at random from this list. Each pick is separate, so one entry can appear more than once.

- **Ion storm strike.** A lightning bolt creates two to six at the strike point when it [changes the cell](/systems/ion-storms/#what-a-strike-does), for example by destroying what stood there. A bolt that hits an empty cell of road, rock, wall or weeds land always creates them.
- **Bridge collapse.** Each destroyed bridge cell has a 47.5 percent chance of creating one beside its bridge explosion. This happens only when [`BridgeExplosions`](/keys/bridgeexplosions/) lists at least one animation.
- **Destroyed object.** An object whose type sets [`MaxDebris`](/keys/maxdebris/) above zero and has no [`DebrisTypes`](/keys/debristypes/) creates between zero and `MaxDebris` of them just above its center, unless it has fallen into water as [the water exit](/systems/destruction-and-debris/#the-step-every-kind-shares) describes. [Destruction and debris](/systems/destruction-and-debris/) covers the rest of what a destroyed object leaves.

:::danger[Give the list at least one animation]
With an empty list, each of these events crashes the game as soon as it needs an animation.
:::
