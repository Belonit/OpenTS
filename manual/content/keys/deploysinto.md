---
key: DeploysInto
summary: The BuildingType a vehicle turns into when it is given the deploy order.
see_also: ["UndeploysInto", "BaseUnit"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MCV]
DeploysInto=GACNST ; GDI Construction Yard
```

Naming a structure lets the vehicle deploy into it. When the vehicle is the only object selected, pointing at it shows the deploy cursor, or the no-deploy cursor when the vehicle cannot deploy. This also holds for a vehicle whose weapon repairs friendly units.

The structure is placed at a fixed spot relative to the vehicle, chosen by the kind of structure:

- A deployed-vehicle structure is placed on the vehicle's own cell. These are the structures flagged [`SensorArray=`](/keys/sensorarray/), [`TickTank=`](/keys/ticktank/), [`ICBMLauncher=`](/keys/icbmlauncher/), [`Artillary=`](/keys/artillary/), [`IsMobileStealth=`](/keys/ismobilestealth/), [`IsJuggernaut=`](/keys/isjuggernaut/), [`IsCoreDefender=`](/keys/iscoredefender/) or [`IsLimpetMine=`](/keys/islimpetmine/).
- Every other structure is placed one cell to the north-west of the vehicle.

If the structure cannot be placed there, the vehicle does not deploy. The local player hears the "cannot deploy here" speech for their own vehicle. A computer house's vehicle orders its house's and allies' units off the site, so a later attempt can succeed. The vehicle then switches to guard; outside a campaign, a computer house's vehicle switches to hunt instead.

If the structure can be placed, the vehicle first turns to the structure's deploy facing. It then disappears, and the structure appears in its place and plays its buildup.

The structure belongs to the vehicle's house and takes over the vehicle's selection group, experience, current target, any limpet drone attached to it, and the country the vehicle was built for. With [`MultiMCV=no`](/keys/multimcv/), that country decides what a deployed construction yard can build.

Objects that were attacking the vehicle attack the structure instead. The exception is a [`VehicleThief=`](/keys/vehiclethief/) infantryman: when the structure is a construction yard or has [`IsMobileWar=yes`](/keys/ismobilewar/), it drops its target.

Naming a structure also has these effects:

- A positive [`BuildLimit`](/keys/buildlimit/) on the vehicle also counts the structures of the named type its house owns. Deploying an MCV therefore does not free a slot to build another.
- A human player's vehicle that deploys into an [`Artillary=yes`](/keys/artillary/) structure never fires back on its own when attacked.
- A vehicle on the `Hunt` mission deploys instead of hunting when its structure is listed in [`BuildConst`](/keys/buildconst/), when it has a target, or when a human player owns it. It first drives to a nearby clear spot.
- The [Deploy](/mapping/missions/tmission-deploy/) team mission orders the vehicle to deploy.
- A computer house's vehicle whose structure is [`TickTank=yes`](/keys/ticktank/) can deploy to fire at its target, as that key explains.
- A team member counts as slow for [`GuardSlower=yes`](/keys/guardslower/). This also applies to infantry and aircraft types that name a structure.

Only vehicles deploy. On an aircraft or infantry type the key's only effect is the `GuardSlower=yes` rule above, and on a structure type it has none.

A name that matches no registered BuildingType registers a new, unconfigured structure under that name. The values `none` and `<none>` name no structure, and a rules file that writes one clears a value an earlier file set.
