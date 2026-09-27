---
key: PlayerJoined
summary: Sound played in the LAN lobby when another player enters the game being set up.
see_also: [PlayerLeft, GameForming, GameClosed, OptionsChanged]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
PlayerJoined=PLYRJOIN ; a sound ID registered in SOUND.INI
```

Only the LAN lobby plays this sound, and it plays without a position on the map. It marks a player entering the game being set up. A player who appears only in the chat list makes no sound.

The host hears it each time it accepts a player's request to join.

A guest hears it each time a new player is added to the game's player list, but only after the host has confirmed the guest's join. Players listed while the guest is still browsing the game list are added without it. Confirmation then rebuilds the list, so the guest hears the sound once for each player already in the game.
