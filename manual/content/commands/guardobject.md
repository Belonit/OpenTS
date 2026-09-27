---
command_id: GuardObject
---

Orders the selected objects the player controls to guard where they stand. Each selected object follows the first of these rules that applies to it:

1. An object that cannot move is left alone. This covers most structures and any object an [EMP](/systems/emp-pulse/) has disabled.
2. A [`Harvester`](/keys/harvester/) or [`Weeder`](/keys/weeder/) vehicle goes back to harvesting, unless it is unloading. An unloading one is left alone.
3. An armed object enters area guard around the spot where it stands, so a vehicle or infantry unit on the move stops there. An aircraft on the ground with no ammunition is left alone.
4. Any other object is left alone.

The command plays [`GuardSound`](/keys/guardsound/) whenever anything is selected, even when no selected object obeys.
