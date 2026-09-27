---
key: Type
scope: sounds
label: Where a sound is heard from
see_also: [Range, MinVolume, Control]
when_omitted:
  kind: value
  value: SCREEN
---

Flags that decide how a sound played at a place in the world fades, pans and is silenced. Separate the flags with spaces or commas; they combine. The flags follow Yuri's Revenge.

- `NORMAL` or `SCREEN`: the sound fades with the distance of its place outside the view, reaching silence at [`Range=`](/keys/range/#scope-sounds), and pans by where the place is across the view.
- `LOCAL`: as `SCREEN`, but the distance is measured from the center of the view, so the sound is already quieter at the edge of the view.
- `GLOBAL`: the fade stops at [`MinVolume=`](/keys/minvolume/) instead of silence.
- `SHROUD` or `UNSHROUDED`: the sound is silent while the cell of its place is unrevealed.
- `SHROUDED`: the sound is silent once the cell of its place has been revealed.
- `UNSHROUD`, `VIOLENT`, `MOVEMENT`, `QUIET`, `LOUD`, `PLAYER`, `NOISE_SHY` (or `NOISESHY`), `GUN_SHY` (or `GUNSHY`) and `AMBIENT` are accepted and have no effect.

A flag the engine does not recognize is ignored.

```ini title="sound01.ini"
[BIGBLAST]
Type=GLOBAL SHROUD
MinVolume=0.3
```

`BIGBLAST` keeps at least 30 percent of its in-view loudness however far from the view it plays, but it is silent in cells the player has not revealed.

A sound played without a place, such as a button click, does not fade, pan or fall silent under any of these flags.
