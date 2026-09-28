---
key: FadeOut
scope: themes
label: Music fade-out time
see_also: [CrossFade]
when_omitted:
  kind: value
  value: "1.5"
---

`FadeOut=` in THEME.INI's `[General]` section sets how many seconds the current music track takes to fade out when it gives way to a queued track, when the player presses Stop on the sound options screen, when a mission is won, lost, restarted or left, and when the game fades the music out on leaving a menu. A queued track starts once the fade has ended.

```ini title="theme01.ini"
[General]
FadeOut=3
```

`0` stops the track at once. A value below zero counts as zero, and one above 60 counts as 60. A value that is not a number is ignored. With [`CrossFade=`](/keys/crossfade/) set, a queued track uses the crossfade time instead; `FadeOut=` still applies to the other cases.
