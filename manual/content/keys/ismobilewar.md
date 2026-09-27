---
key: IsMobileWar
summary: Marks a deployed structure as a mobile war factory, which an engineer may work on and which may pack up even where redeploying is off.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

`IsMobileWar=yes` marks a structure that sets [`UndeploysInto`](/keys/undeploysinto/) as a mobile war factory.

An engineer gets [the structure cursors](/systems/capture/#an-engineer-over-a-structure) over a mobile war factory, whatever its [`Repairable`](/keys/repairable/) setting. Without the flag, a structure that sets `UndeploysInto` and is not a construction yard counts as a vehicle, and an engineer gets none of those cursors over it.

:::caution[Do not send engineers to repair a mobile war factory]
When the engineer arrives, the mobile war factory still counts as a vehicle, and [the vehicle branch](/systems/capture/#the-vehicle-branch) checks neither ownership nor [`Capturable`](/keys/capturable/). A damaged allied mobile war factory therefore shows the engineer's repair cursor, but the engineer takes it over instead of repairing it. An engineer sent to the player's own damaged mobile war factory is used up and repairs nothing.
:::

The flag has these further effects:

- The structure can be undeployed whether or not the session allows redeploying, and the [Deploy Object](/commands/deployobject/) command accepts it.
- Drag selection passes it over, as it does a construction yard. The player's other structures that set `UndeploysInto` are picked up.
- When a vehicle deploys into a mobile war factory, a [`VehicleThief=yes`](/keys/vehiclethief/) infantryman targeting that vehicle drops its target. Every other object targeting the vehicle switches to the new structure.
- The first time the structure finishes deploying, its [primary factory](/systems/production/#the-primary-factory) status is toggled.

A mobile war factory that sets [`Factory=UnitType`](/keys/factory/) has a [rally point](/systems/production/#rally-points). A plain click on the ground sets the rally point, and a click with the force-move key held packs the structure up and drives it to the clicked point. [`AltToRally=yes`](/keys/alttorally/) swaps the two clicks.
