---
key: CloakDelay
summary: The time in game minutes an object must wait after it is uncloaked before it may hide again.
see_also: ["system:cloaking"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[General]
CloakDelay=.02
```

`CloakDelay` sets how long an object must wait after being uncloaked before it can start hiding again. A game minute is 900 frames, so the shipped `rules.ini` value of `.02` is 18 frames. At the engine default of `0` there is no wait. An object starts hiding again once its fade back into view has finished and nothing is revealing it.

The wait restarts each time anything uncloaks the object. For a vehicle, infantryman or aircraft it restarts once more when [the fade back into view](/systems/cloaking/#the-four-states) finishes, so after it is revealed the wait runs from the moment it is fully visible. A structure's wait runs from the moment it is uncloaked and overlaps its fade.

:::caution[Every hit restarts the wait]
Any hit that does not destroy an object restarts the wait, even when the object is not hidden at the time. This includes hits that deal no damage and heals. With a non-zero delay, an object under fire cannot start hiding until the delay has passed since the last hit.
:::
