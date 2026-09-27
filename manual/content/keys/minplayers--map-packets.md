---
key: MinPlayers
scope: map-packets
label: Packet-listed player minimum
see_also: [MaxPlayers, Description]
no_effect: true
when_omitted:
  kind: value
  value: "2"
---

```ini title="MyMaps.PKT"
[MYMAP] ; a section named by the packet's [MultiMaps] list
MinPlayers=2
```

The value is stored with the map's entry in the multiplayer map list, and nothing reads it afterwards. No lobby waits for this many players before a game can start, and starting positions and houses are assigned without it.
