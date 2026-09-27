---
key: FlamingInfantry
summary: The burning figure left where fire kills an infantryman.
see_also: [InfDeath, Doggie, IsFlamingGuy, RunningFrames, SmallFire]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
FlamingInfantry=MYFLAMEGUY ; an AnimType registered in [Animations]
```

When a warhead with [`InfDeath=4`](/keys/infdeath/) kills an infantryman, this animation plays at his position and the soldier is deleted at once. No corpse remains to be crushed, shot or targeted.

The animation does not play in these cases:

- A [`Doggie=yes`](/keys/doggie/) infantryman plays its own fire-death sequence instead.
- A soldier who was falling and dies no more than ten [leptons](/glossary/#lepton) above a water cell splashes instead.
- A prone [`Cyborg=yes`](/keys/cyborg/) infantryman and a jumpjet infantryman burst into [`InfantryExplode`](/keys/infantryexplode/) instead.
- A soldier killed by a laser fence is electrocuted instead, whatever the warhead.

How the figure moves depends on the named type. With [`IsFlamingGuy=yes`](/keys/isflamingguy/), it runs from cell to cell and then collapses, using the frames that [`RunningFrames`](/keys/runningframes/) lays out. Without that flag, the animation simply plays where the soldier fell.

:::caution[The burning figure wears the local player's colors]
The figure takes the local player's color scheme, whichever house owned the soldier. In a multiplayer game, each player sees the same death in his own color. After a saved game is loaded, a figure whose type sets `IsFlamingGuy=yes` is repainted in the local player's colors again, and any other figure is drawn without the remap.
:::

:::danger[Set this key if any warhead uses `InfDeath=4`]
With the key unset, the game crashes the first time an `InfDeath=4` warhead kills an infantryman who would take this animation.
:::
