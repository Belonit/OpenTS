---
key: IsLimpetMine
summary: Marks a deployed structure as a limpet mine, which vehicles drive over and an EM pulse destroys.
see_also: [DeploysInto, UndeploysInto, EMPulseCannon, ImmuneToEMP, IsMobileWar, "system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

`IsLimpetMine=yes` makes the structure one of the [deployed-vehicle kinds](/keys/deploysinto/). A vehicle that deploys into it places it on the vehicle's cell, not one cell away, and the structure undeploys back onto that cell. It can be undeployed whether or not the session allows redeploying.

The flag also has these effects:

- **Vehicles drive over it.** A limpet mine never blocks a vehicle from entering its cell, as with an [`InvisibleInGame=yes`](/keys/invisibleingame/) structure.
- **It offers no attack cursor.** A selected limpet mine shows no attack cursor over an object or a bare cell, even with force fire, so the player cannot order it to attack. An [`EMPulseCannon=yes`](/keys/empulsecannon/) structure is limited the same way.
- **An EM pulse destroys it.** [The pulse](/systems/emp-pulse/#what-a-pulse-reaches) credits the kill to its firer, where other structures are only powered off and stunned. A mine whose type sets [`ImmuneToEMP=yes`](/keys/immunetoemp/) is not destroyed.
- **The [Deploy Object](/commands/deployobject/) command accepts it.** Other structures pass that command's readiness test only when they set [`Passengers=`](/keys/passengers/) above `0`. `IsLimpetMine=yes` and [`IsMobileWar=yes`](/keys/ismobilewar/) structures pass it without.
