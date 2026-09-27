---
key: InfantryExplode
summary: The explosion that stands in for an infantry death animation.
see_also: [InfDeath, Cyborg, DeadBodies, FlamingInfantry]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
InfantryExplode=MYINFBANG ; an AnimType registered in [Animations]
```

When an infantryman dies with this animation, the animation plays at its position and the infantryman is removed at once. It plays no death sequence and leaves no [`DeadBodies`](/keys/deadbodies/) corpse.

When an infantryman is killed, the engine checks these cases in order and uses the first that matches:

1. It was knocked off a height and dies no more than 10 leptons above water. It leaves a wake and a splash instead of this animation, apart from the cyborg case below the list.
2. It is a [`Cyborg=yes`](/keys/cyborg/) type lying prone. It plays this animation.
3. It is a [`JumpJet=yes`](/keys/jumpjet/) type. It plays this animation, whatever killed it.
4. The killing warhead sets [`InfDeath=3`](/keys/infdeath/). It plays this animation, unless a [laser fence](/systems/laser-fences/) made the kill, which gives the electrocution death. A [`Doggie=yes`](/keys/doggie/) type killed by a laser fence plays its fire death instead.

A `Cyborg=yes` infantryman that was knocked off a height also plays the animation when forced damage kills it. Forced damage ignores [`Immune=yes`](/keys/immune/#scope-aircrafttype), and the impact at the end of a fall is forced. This animation plays before the list is checked, and the list still applies. A cyborg that also matches case 2, 3 or 4 plays the animation twice on the same frame, and one that matches case 1 plays it alongside the wake and splash.

The animation also marks a `Cyborg=yes` infantryman losing its legs without dying. When ordinary damage would bring an upright cyborg to zero strength, it survives instead: it plays this animation, drops to a quarter of its maximum strength with a minimum of 1, goes prone and starts crawling. Forced damage kills an upright cyborg outright.

:::danger[Name an animation before any cyborg or jumpjet takes fatal damage]
With the key unset, the game crashes the first time one of these cases plays the animation, including the first time a cyborg loses its legs. Cyborgs and jumpjets reach it without any warhead setting `InfDeath=3`.
:::
