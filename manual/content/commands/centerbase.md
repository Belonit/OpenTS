---
command_id: CenterBase
---

Centers the view on the player's base. The view moves to the first of these that the player controls:

1. A construction yard, meaning a structure whose type is listed in [`BuildConst`](/keys/buildconst/). The primary construction yard is preferred.
2. Any other structure.
3. A vehicle whose type is listed in [`BaseUnit`](/keys/baseunit/), such as an undeployed MCV.

If the player has none of these, the view stays where it is.

The command ends follow mode even when the view does not move. It also works while a structure is waiting to be placed, and that structure's placement outline stays under the mouse pointer after the view moves.
