---
command_id: CenterOnRadarEvent
---

Centers the tactical view on the last place the game flagged for the player's attention. The command does nothing until the first place is flagged after the program starts. Saved games keep the place.

These events flag a new place:

- A radar event starts on the radar. The game starts one when EVA announces that the player's base or one of the player's harvesters is under attack, when the radar detects a hidden enemy such as a cloaked or tunneling unit, and when a map's [Create Radar Event](/mapping/actions/taction-radar-event/) trigger action runs. An event that is not shown because one of the same kind is already showing nearby flags nothing.
- One of the player's vehicles, soldiers or aircraft is destroyed and EVA [announces the loss](/systems/destruction-and-debris/#the-loss-announcement). The flagged place is the cell the object was heading to, or the cell it stood in if it was not moving.
- [Reinforcements](/mapping/actions/taction-reinforcements/) arrive for the player's house or an ally. The flagged place is the cell they arrived at.

A unit or aircraft leaving a factory flags nothing.

Starting a new game does not clear the place. Until something is flagged in the new game, the command centers on the place last flagged in an earlier game played since the program started. Loading a saved game replaces the place with the one the save holds.
