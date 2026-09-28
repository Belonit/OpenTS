---
key: RequiredAddon
scope: themes
label: Track expansion
see_also: [Normal, Side, Scenario]
when_omitted:
  kind: value
  value: "0"
  note: No expansion is needed, so the track can play in the base game and in every expansion.
---

`RequiredAddon=1` makes the music track a Firestorm track: the game chooses it for the playlist, and lists it on the sound options screen, only while Firestorm is running. `-1` allows the track while any expansion is running. `0` places no restriction.

```ini title="theme01.ini"
[MYTHEME]
Name=Example theme
RequiredAddon=1
```

Any other number names no expansion, so the track is never chosen. The restriction applies to the playlist, the sound options list, and the [next track](/commands/nexttheme/) and [previous track](/commands/prevtheme/) commands. A track that the game or a map starts by name, such as a scenario's [`Theme=`](/keys/theme/) track or a Play music theme trigger action, plays whatever expansion is running.
