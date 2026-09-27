---
key: PlayerLeft
summary: Sound played in the LAN lobby when a player drops out of the game being set up.
see_also: [PlayerJoined, GameForming, GameClosed, OptionsChanged]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
PlayerLeft=PLYRLEFT ; a sound ID registered in SOUND.INI
```

Only the LAN lobby plays this sound, and it plays without a position on the map. It marks a player in the game's player list signing off, and it plays once for each player-list entry removed.

The host hears it for any listed player who leaves. A guest hears it only after the host has confirmed the guest's join. A player who signs off from the chat list makes no sound.
