---
key: CrumbleSound
summary: Sound a structure makes as its destruction sequence begins.
see_also: [BlowupSound, IsLimpetMine, "system:emp-pulse"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
CrumbleSound=BLDGDIE1 ; a sound ID registered in SOUND.INI
```

The sound plays once, at the structure's position, when the structure is destroyed. It plays after anything inside the structure has been killed and before the scorch marks, fires, explosions, debris and survivors appear. Every structure uses this one sound, whatever its size, in addition to the explosion animations its own type names.

Two things destroy a structure this way:

- damage that brings it to zero strength;
- an [EM pulse](/systems/emp-pulse/) that reaches an [`IsLimpetMine=yes`](/keys/islimpetmine/) structure, which is destroyed instead of being disabled.

Selling a structure does not play this sound. A sale plays [`SellSound`](/keys/sellsound/) instead.
