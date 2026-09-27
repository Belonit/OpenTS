---
key: MultiplayerOnly
summary: Parsed flag that restricts nothing.
no_effect: true
when_omitted:
  kind: value
  value: "no"
---

`MultiplayerOnly=yes` does not keep a map out of the campaign or limit it to multiplayer games. The engine reads the flag from the map's `[Basic]` section and never acts on it.
