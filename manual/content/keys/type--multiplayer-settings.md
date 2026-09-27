---
key: Type
scope: multiplayer-settings
label: Sync-bug trap object kind
no_effect: true
see_also: ["Frame", "Target", "Cell", "Coord"]
when_omitted:
  kind: value
  value: "NONE"
---

`Type=` names the kind of object a sync-bug trap would search during recording playback. That search is not built into OpenTS, so no value changes anything.

The key is read only while recording playback is armed. `AIRCRAFT`, `ANIM`, `BUILDING`, `BULLET`, `INFANTRY` and `UNIT` are recognized in any letter case, and every other value reads as `NONE`.
