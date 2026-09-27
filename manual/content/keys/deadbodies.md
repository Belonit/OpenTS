---
key: DeadBodies
summary: The corpse animations left where an infantryman finishes a death sequence.
see_also: [InfDeath, Doggie, InfantryExplode, FlamingInfantry]
when_omitted:
  kind: value
  value: ""
---

An infantryman leaves a corpse when he finishes a gun death or an explosion death, the death sequences that a warhead's [`InfDeath=1`](/keys/infdeath/) and `InfDeath=2` start. When the sequence reaches its last frame, one animation from this list appears at his center and he is removed. Every entry is equally likely, whichever of the two deaths he played.

```ini title="rules.ini"
[AudioVisual]
DeadBodies=MYDEATH_A,MYDEATH_B ; AnimTypes registered in [Animations]; each corpse is one of the two, equally likely
```

A [`Doggie=yes`](/keys/doggie/) infantryman never leaves a corpse.

Many deaths remove the infantryman at once, without a death sequence, so they leave no corpse whatever the warhead's `InfDeath` is. These include:

- an infantryman who was already falling and comes down in water;
- a prone [`Cyborg=yes`](/keys/cyborg/) infantryman;
- a `Cyborg=yes` infantryman killed by forced damage, such as being caught in a raised firestorm wall;
- a [`JumpJet=yes`](/keys/jumpjet/) infantryman.

:::danger[Give DeadBodies at least one entry]
If rules.ini leaves `DeadBodies` out, or every entry is `none`, the list is empty and the game crashes the first time an infantryman that is not `Doggie=yes` finishes a gun or explosion death. Keep at least one entry while any warhead sets `InfDeath=1` or `InfDeath=2`.
:::
