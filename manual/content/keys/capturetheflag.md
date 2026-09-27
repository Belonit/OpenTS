---
key: CaptureTheFlag
summary: Seeds the capture-the-flag session option, which no longer reaches the game.
see_also: [BaseUnit, Bases]
no_effect: true
when_omitted:
  kind: value
  value: "no"
---

`CaptureTheFlag` sets the starting value of the multiplayer capture-the-flag option, like the other `[MultiplayerDefaults]` options. The option is shared with the other players during setup, and a guest takes the host's value. The game never copies it into the scenario setting that turns the mode on, and no scenario file sets that either, so capture-the-flag stays off in every game.

Part of the mode remains in the engine. If it were on in a game with [`Bases`](/keys/bases/) on, each house's [`BaseUnit`](/keys/baseunit/) would carry that house's flag from the start. Carrying a flag halves a vehicle's speed and stops it from cloaking fully, so it shimmers instead. The flag drops onto the ground when the vehicle deploys or is otherwise taken off the map, and a house that is defeated loses its flag.

Nothing moves a flag from one house to another, and no victory condition checks flags. The contest the name describes does not exist in the engine.
