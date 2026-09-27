---
key: IceCrackSounds
summary: Sounds the game picks from at random when ice cracks.
see_also: [IceCrackingWeight, IceBreakingWeight, IceSolidifyFrameTime, Weight]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
IceCrackSounds=ICECRAK1,ICECRAK2,ICECRAK3 ; sound IDs registered in SOUND.INI
```

Each time full ice cracks, the game plays one sound picked at random from this list. The sound is not placed on the map, so it plays at the same volume wherever the crack is.

Ice cracks in a theater whose [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) is `yes`, in two ways:

- a vehicle enters the cell with a [`Weight`](/keys/weight/) at or above [`IceCrackingWeight`](/keys/icecrackingweight/) and below [`IceBreakingWeight`](/keys/icebreakingweight/);
- a warhead with [`Wall=yes`](/keys/wall/#scope-warheadtype) or [`Fire=yes`](/keys/fire/) explodes in the cell.

Breaking the ice plays no sound from this list. That covers a vehicle heavy enough to break the ice outright, and any vehicle or explosion that breaks an already cracked cell.

Each name must match a sound ID registered in [SOUND.INI](/formats/sound-ini/). Names that match nothing are dropped. An empty list plays no sound.

:::caution[Repeat the list in every later `[AudioVisual]` section]
A later file with an `[AudioVisual]` section empties this list unless it names the key again. That includes a language rules file, the Firestorm rules and a map. The other settings in the section keep their earlier values in that case.
:::
