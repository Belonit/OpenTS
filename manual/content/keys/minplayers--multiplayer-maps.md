---
key: MinPlayers
scope: multiplayer-maps
label: Loose map player minimum
see_also: [MaxPlayers, Description, Official]
no_effect: true
when_omitted:
  kind: value
  value: "2"
---

```ini title="MyMap.MPR"
[Multiplay]
MinPlayers=2
```

The value is stored with the map's entry in the multiplayer map list, and nothing reads it afterwards. No lobby waits for this many players before a game can start, and starting positions and houses are assigned without it.
