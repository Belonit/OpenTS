---
key: SystemError
summary: Sound played on the LAN game screens when a join is refused or the host removes the player.
see_also: [GameForming, GameClosed, PlayerJoined, PlayerLeft]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
SystemError=BUZZER1 ; a sound ID registered in SOUND.INI
```

The sound plays on the LAN game screens when a join is refused or the host removes the player. It has no position on the map, and each time it plays, a system line also appears in the chat panel.

In the game list, the game refuses to send a join request in seven cases:

- no game is selected;
- the list holds no game to join;
- the player handle is empty;
- the selected game is no longer open;
- the game uses Firestorm and the expansion is not installed;
- the game uses Firestorm and the expansion is installed but not enabled;
- the game uses the base game and Firestorm is enabled on this client.

After a request is sent, the host can turn it down, or remove the player from the lobby of a game they had already joined. Either way the chat line says the request was denied. For most refusals by the host, a message box gives the reason, such as a duplicate name, a full game or a version mismatch.

No screen outside the LAN game list and lobby plays this sound. During a match, a refused interface action plays [`ScoldSound`](/keys/scoldsound/) instead.
