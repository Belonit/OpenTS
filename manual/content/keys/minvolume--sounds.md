---
key: MinVolume
scope: sounds
label: Distance floor
see_also: [Volume, Range, Type]
when_omitted:
  kind: value
  value: "0"
---

The least loudness a sound with `GLOBAL` in its [`Type=`](/keys/type/#scope-sounds) falls to at any distance from the view, as a share of its loudness inside the view. `MinVolume=0.3` keeps such a sound at 30 percent of the loudness its [`Volume=`](/keys/volume/) gives it inside the view. A value above 1 is read as a percentage, as for `Volume=`.

A value below `0.05` does not keep a distant sound audible, because a placed sound quieter than five percent of its in-view loudness is cut off.

Without `GLOBAL`, the key has no effect, and the sound fades to silence at its [`Range=`](/keys/range/#scope-sounds).

```ini title="sound01.ini"
[BIGBLAST]
Type=GLOBAL
MinVolume=0.3
```
