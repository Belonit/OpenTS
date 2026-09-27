---
key: RequiredAddOn
summary: The expansion whose rules, art and speech the mission is played under.
see_also: [SpeechSide, Name]
when_omitted:
  kind: context-dependent
  note: 0, the base game, in a campaign mission. In a multiplayer or skirmish game, the expansion the session was started under.
---

```ini title="map file"
[Basic]
RequiredAddOn=1
```

`0` names the base game and `1` names Firestorm. A campaign mission is played under the expansion it names: that expansion's rules, art and speech apply, and every other expansion is switched off. The check comes before anything else in the mission is loaded.

A campaign mission that names an expansion that is not installed does not load. It does not fall back to the base game. Without Firestorm installed, every mission that sets `RequiredAddOn=1` fails this way.

The number also selects the file a campaign mission's title and briefing text come from: `MISSION.INI` for `0` and `MISSION1.INI` for `1`. The objectives screen reads the briefing from the same file when the scenario does not already hold its text.

Outside a campaign, the lobby or the launch file decides the expansion, and this key switches no expansion on or off when the match starts. The map's number is still stored with the match, and a saved game of the match loads under that expansion. A map that sets `RequiredAddOn=0` and is played under Firestorm therefore loads back as the base game.

Loading a saved game, in any kind of game, switches to the expansion the saved mission recorded and switches every other one off. The load fails if that expansion is not installed.
