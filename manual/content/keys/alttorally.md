---
key: AltToRally
summary: Makes the force-move key set a factory's rally point and the plain click move the structure.
see_also: [Factory, UndeploysInto, "system:production"]
when_omitted:
  kind: value
  value: "no"
---

A structure whose [`Factory=`](/keys/factory/) is `UnitType`, `InfantryType` or `AircraftType` has a [rally point](/systems/production/#rally-points). At `no`, a plain click on the ground sets the rally point, and a click with the force-move key held gives the structure a move order. On a factory that can [undeploy](/keys/undeploysinto/), such as a mobile war factory, the move order packs it up and the vehicle drives to the clicked point. Any other factory does nothing on a force-move click.

`AltToRally=yes` swaps the two clicks: a force-move click sets the rally point, and a plain click gives the move order. A factory that cannot undeploy then does nothing on a plain click.

The setting does not affect a structure without a rally point. If such a structure can undeploy, as a deployed artillery piece can, a plain click gives it the move order at either setting.

The game reads the setting only at startup. It affects only the player who sets it, so players in one match can use different settings.
