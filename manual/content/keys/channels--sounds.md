---
key: Channels
scope: sounds
label: Sound effect voices
see_also: [Priority, Limit]
when_omitted:
  kind: value
  value: "16"
---

How many sound effects can play at once. A value below 4 is read as 4, and a value above 32 as 32. Either sound file may set it; [SOUND.INI](/formats/sound-ini/) describes how the two files combine.

Every sound effect that is playing counts toward this number, including unit responses. A sound waiting out a [`Delay=`](/keys/delay/) silence does not. Music, EVA speech and movie sound do not count.

When every voice is in use, a new sound effect can take the voice of a playing one. [`Priority=`](/keys/priority/#scope-sounds) decides which sound gives way and whether the new one plays at all.

```ini title="sound01.ini"
[General]
Channels=24
```
