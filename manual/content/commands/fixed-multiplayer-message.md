---
command_id: fixed:multiplayer-message
---

In a game against other machines, the function keys `F1` through `F8` open the message editor:

- `F8` starts a line to everyone.
- `F1` through `F7` each start a private line to the player or observer at one other machine, in connection order. `F1` addresses the first connection, `F2` the second, and so on. A key with no connection at its position does nothing.

The range ends at `F8` because the multiplayer player limit is fixed at 8, as [`Players`](/keys/players/) explains.

None of the keys does anything while a line is being edited. The private keys also do nothing for a player who may not send private lines, such as an observer; [In-game chat](/systems/chat/#who-may-open-a-line) states who may.

A line to the team, and a second key for a line to everyone, are separate commands: [`ChatToAllies`](/commands/chattoallies/) and [`ChatToAll`](/commands/chattoall/).
