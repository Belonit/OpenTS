---
key: NumPlayers
scope: random-map-generation-2
label: Start positions a lobby counts
see_also: [Width, Height]
when_omitted:
  kind: value
  value: "0"
---

The skirmish setup and the multiplayer lobby use `NumPlayers` as the number of start positions of a scenario that has no waypoints. The [map generator](/keys/numplayers/#scope-random-map-generation) reads the same key separately.

Before a game starts, the setup opens the chosen scenario file and counts the entries `0` through `7` in its `[Waypoints]` section. If it finds none, it takes the count from `NumPlayers` in the file's `[RandomMap]` section. This is how a map seed, which has no waypoints until its map is generated, gets a player limit.

The setup then compares the count with the players asked for:

- In a skirmish game, the human player plus the computer players.
- In a multiplayer lobby, the human players in the lobby. Computer players are not counted, so a lobby game can start with more players than start positions. The extra players start on open ground picked at random.

If more players are asked for than the count allows, the game does not start, and the setup shows a message that the map is too small. A scenario with no waypoints and no `NumPlayers` therefore counts as having no start positions and cannot be started with any lineup.
