---
key: Priority
scope: sounds
label: Sound playback priority
see_also: [Limit, Volume, Channels]
when_omitted:
  kind: value
  value: "10"
---

`Priority=` decides which sound effect gives up its voice when more sound effects want to play than [`Channels=`](/keys/channels/) allows. A higher priority wins. Write a number from 0 to 255, or one of `LOWEST`, `LOW`, `NORMAL`, `HIGH` and `CRITICAL` for 0, 10, 50, 100 and 255. A number outside that range is held to it, and any other word is ignored.

A new sound takes a free voice whatever its priority. When every voice is in use, the playing sound with the lowest priority is the one that can give up its voice. Among equal priorities, that is the quietest, or the oldest when their loudness is within a tenth. The new sound takes that voice when either is true:

- its priority is higher;
- the priorities are equal, and the playing sound is more than a tenth quieter than the new one.

Otherwise the new sound is refused and does not play. With `QUEUE` in its [`Control=`](/keys/control/), a sound refused when the game plays it keeps trying for up to two seconds first.

```ini title="sound01.ini"
[EXPLOLG1]
Priority=50

[MYALERT]
Priority=CRITICAL
```

Loudness only breaks ties between equal priorities; a quiet or distant sound keeps the priority it was given. [`Limit=`](/keys/limit/) applies first and separately, among copies of the same sound.
