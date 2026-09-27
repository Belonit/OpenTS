---
key: Description
scope: map-packets
label: Packet list entry
see_also: [MinPlayers, MaxPlayers]
when_omitted:
  kind: value
  value: ""
  note: The map is listed with a blank description.
---

The text is the map's row in the multiplayer scenario list. At most 43 characters are kept; a longer value is cut.

A scenario packet lists its maps in `[MultiMaps]`. Each value there names a section of the packet, and that section holds the map's settings, this key included.

```ini title="MyMaps.PKT"
[MultiMaps]
1=MYMAP

[MYMAP] ; the section the entry above names
Description=Four player canyon
```

The map file is the section name with `.MAP` appended, `MYMAP.MAP` in this example. When it builds the list, the game reads that file only for its digest, which other players' copies are checked against, and never for a description.

In the game's own network lobby, the host sends this text to the other players with the game options. A joining player who has a map with the same file name sees the text their own list gives it. The host's text is shown only to a player who does not have the map.

:::caution[Give every packet map a description without commas]
The game options travel as a comma-separated list, and this text is written into it as it stands. An empty description or one that contains a comma makes each joining player misread the fields after it, including the map's file name, so the map is not matched.
:::
