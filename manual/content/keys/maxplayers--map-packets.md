---
key: MaxPlayers
scope: map-packets
label: Packet-listed player ceiling
see_also: [MinPlayers, Description]
no_effect: true
when_omitted:
  kind: value
  value: "4"
---

```ini title="MyMaps.PKT"
[MYMAP] ; a section named by the packet's [MultiMaps] list
MinPlayers=2
MaxPlayers=4
```

The value is stored with the map's entry in the multiplayer map list, and nothing reads it afterwards. No lobby caps the number of players at it, and starting positions and houses are assigned without it. A map declaring `MaxPlayers=4` still accepts as many players as the lobby allows.
