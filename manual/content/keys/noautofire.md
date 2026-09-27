---
key: NoAutoFire
summary: Stops a human-owned object of this type from picking targets on its own.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

While an object of this type belongs to a human player, every [automatic target search](/systems/target-selection/) it makes finds nothing. That includes the search a team's attack mission runs for each of its members. A [`VehicleThief=yes`](/keys/vehiclethief/) infantry type is the exception: its search still finds a vehicle it is already heading for within 15 cells. The same type searches normally under a computer house.

The object still fires at a target it is given directly, such as a player's attack order or an attacker it retaliates against.
