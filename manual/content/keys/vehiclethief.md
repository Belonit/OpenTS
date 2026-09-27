---
key: VehicleThief
summary: Lets a soldier be ordered onto another house's vehicle and walk into its cell to take it.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

A `VehicleThief=yes` soldier can be ordered onto another house's vehicle, and it takes the vehicle when it reaches the vehicle's cell. [Stealing a vehicle](/systems/capture/#stealing-a-vehicle) covers the arrival and what changes hands.

For a player-controlled soldier, the enter cursor appears over any vehicle that belongs to a different house, a landed aircraft included. The test compares houses, not alliances, so an allied player's vehicle qualifies too. The setting gives no enter cursor over these:

- any vehicle, when the soldier's weapon heals;
- a structure, including a deployed vehicle;
- a type with [`NonVehicle=yes`](/keys/nonvehicle/);
- an [`IsTrain=yes`](/keys/istrain/) type, which gets the select cursor;
- while the [`HarvesterImmune`](/keys/harvesterimmune/) truce is on, a type listed in [`HarvesterUnit`](/keys/harvesterunit/), which gets the select cursor.

The setting also changes how the soldier moves and picks targets:

- It may step into the cell of the vehicle it is heading for, unless that vehicle is an `IsTrain=yes` type.
- While it is heading for a vehicle within 15 cells, it keeps that vehicle as its target and does not scan.
- When unarmed, it looks for vehicles, never buildings or aircraft. [Target selection](/systems/target-selection/#what-each-kind-of-object-considers) gives the full targeting rules.
- On the hunt mission, it walks to each target it finds on a capture order instead of attacking it.
- When unarmed, owned by a computer house and not in a team, it goes on area guard when idle once the house's [`IQ`](/keys/iq/) reaches [`GuardArea`](/keys/guardarea/).
- When the vehicle it is targeting deploys into an [`IsMobileWar=yes`](/keys/ismobilewar/) structure or a [`ConstructionYard=yes`](/keys/constructionyard/) structure, it drops that target.
- A computer house choosing an ion cannon target rates the soldier by [`AIIonCannonThiefValue`](/keys/aiioncannonthiefvalue/) while its strength is at most [`IonCannonDamage`](/keys/ioncannondamage/). A type that is also [`Engineer=yes`](/keys/engineer/#scope-infantrytype) is rated as an engineer instead.

A vehicle this type has stolen counts against the type's positive [`BuildLimit`](/keys/buildlimit/) while the thief's house owns it. With `BuildLimit=1`, a house that owns a vehicle this type stole cannot build the type again. A stolen aircraft does not count, and neither does a vehicle taken when it drives over its thief. A stolen vehicle that deploys into a structure stops counting, and it does not count again after it undeploys.

When a stolen vehicle is destroyed, a soldier of the thief's type steps out of the wreck, unless it cannot be placed there. It belongs to whoever owns the vehicle at that moment and has between 5 hit points and half its maximum strength, whatever [`Crewed`](/keys/crewed/) says. No soldier steps out of these:

- a stolen aircraft;
- a vehicle taken when it drives over its thief;
- a vehicle type with a death animation, set by [`DeathFrames`](/keys/deathframes/) above 0;
- a stolen vehicle that deployed into a structure and later undeployed.
