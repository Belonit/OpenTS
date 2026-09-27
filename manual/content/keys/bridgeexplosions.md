---
key: BridgeExplosions
summary: The explosions that accompany a bridge span coming down.
see_also: [MetallicDebris, BridgeStrength, C4Warhead]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
BridgeExplosions=MYBLAST1,MYBLAST2 ; AnimTypes registered in [Animations]
```

When an elevated bridge collapses, each collapsing cell has a 95 percent chance to show one animation picked at random from this list. The animation appears at deck height, up to 25 leptons off the cell's center in each direction, and starts one to five frames late. A low bridge that is destroyed shows none of these animations.

Each cell that shows an explosion also has an even chance to throw wreckage from [`MetallicDebris`](/keys/metallicdebris/).

:::caution[An empty list also removes the wreckage]
With no entries, a collapsing bridge shows no explosions and throws no `MetallicDebris` wreckage, because the wreckage is thrown only alongside an explosion.
:::
