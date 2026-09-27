---
command_id: StopObject
---

Stops each selected object that the player can move or fire. The object drops its destination, its target and any waypoints still queued. Every object except an aircraft is also put on guard where it stands, whatever order it had. An aircraft keeps its current order. As a result:

- a unit on area guard no longer walks back to its guard spot;
- a hunting unit stops looking for targets across the map;
- a harvester stops working;
- a transport that is unloading keeps the passengers still aboard.

A vehicle that has already started turning to deploy still deploys.

Three kinds of object ignore the command:

- an object docked at a structure, such as a harvester unloading at a refinery;
- a structure being built or sold;
- an object that is not on a bridge or ramp and whose cell is hidden on screen behind higher ground in front of it.
