---
key: GameForming
summary: Sound played in the network game list when a joinable game appears.
see_also: [GameClosed, PlayerJoined, PlayerLeft, SystemError]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
GameForming=NEWGAME1 ; a sound ID registered in SOUND.INI
```

The sound plays in the LAN game list that a player sees before joining a match. It marks a game becoming joinable in either of two ways:

- a listed game reopens after having been closed;
- a game appears on the list for the first time, already open.

A game that first appears closed is added to the list without the sound. A matching line appears in the chat panel with each sound.

A game's host reports these changes when it answers the game queries sent by the list. The sound plays only until the player has been confirmed into a game.
