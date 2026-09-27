---
key: Players
summary: Parsed player limit that the engine never uses.
no_effect: true
when_omitted:
  kind: value
  value: "8"
---

The multiplayer player limit is fixed at 8, whatever this key holds. The engine sets its limit once at startup, before it reads the `[Maximums]` section, and never updates it from this key.

That fixed limit has two visible effects:

- The LAN lobby turns away a player who tries to join a game that already holds 8 players, with the message that the game is full.
- In a network game, `F1` to `F8` open the in-game message line. `F8` addresses everyone, and `F1` to `F7` address the other players in connection order. [The multiplayer message keys](/commands/fixed-multiplayer-message/) cover when each key responds.
