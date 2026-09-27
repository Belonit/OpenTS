---
key: GameClosed
summary: Sound played in the network game list when a listed game stops accepting players.
see_also: [GameForming, PlayerJoined, PlayerLeft, SystemError]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
GameClosed=GAMESHUT ; a sound ID registered in SOUND.INI
```

The sound plays in the LAN game list that a player sees before joining a match. It marks a listed game changing from open to closed, as reported in the replies to the list's game queries. Once a game is closed, any player in it can send that reply. A matching line appears in the chat panel with the sound.

The sound plays only until the player has been confirmed into a game. A game that disappears from the list without first reporting itself closed does not play it.
