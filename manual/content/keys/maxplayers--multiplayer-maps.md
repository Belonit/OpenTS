---
key: MaxPlayers
scope: multiplayer-maps
label: Loose map player ceiling
see_also: [MinPlayers, Description, Official]
no_effect: true
when_omitted:
  kind: value
  value: "4"
---

```ini title="MyMap.MPR"
[Multiplay]
MinPlayers=2
MaxPlayers=4
```

The value is stored with the map's entry in the multiplayer map list, and nothing reads it afterwards. No lobby caps the number of players at it, and starting positions and houses are assigned without it. A map declaring `MaxPlayers=4` still accepts as many players as the lobby allows.
