---
key: Limit
scope: sounds
label: Copies at once
see_also: [Priority, Control, Channels]
when_omitted:
  kind: value
  value: "3"
---

How many copies of this sound can play at once; `0` allows any number. A copy counts from the moment the game plays it, including while it waits out a `PREDELAY` silence, waits for a voice under `QUEUE`, or sits in the silence between cycles of a loop with a [`Delay=`](/keys/delay/).

When the limit is reached, the new copy is compared in loudness with the quietest copy already counted. A copy's loudness is its [`Volume=`](/keys/volume/#scope-sounds), times its distance fade or the loudness the game asked for, times its [`VShift=`](/keys/vshift/) draw.

- If the new copy is louder by more than one percent, the quietest copy stops.
- If the two are within one percent, the quietest copy stops only with `INTERRUPT` in the sound's [`Control=`](/keys/control/). Otherwise the new copy is refused.
- If the new copy is quieter, it is refused.

A refused copy does not play. With `QUEUE` in `Control=`, a copy refused when the game plays it keeps trying for up to two seconds first.

```ini title="sound01.ini"
[GUN5]
Limit=2
```

The limit compares only copies of the same sound, and it applies before the new copy looks for a voice. A new copy that stops the quietest copy must still get a voice under [`Channels=`](/keys/channels/) and [`Priority=`](/keys/priority/#scope-sounds). If the new copy is refused there, the stopped copy does not resume. `Priority=` decides between different sounds when all voices are in use.
