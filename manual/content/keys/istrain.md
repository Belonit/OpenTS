---
key: IsTrain
summary: Marks a vehicle as rolling stock, which changes how it finds a path, what blocks it and when it may leave the map.
when_omitted:
  kind: value
  value: "no"
---

The flag makes a vehicle one car of a train. It changes how the vehicle plans a route, what stops it, what happens to objects in its way, and how other objects treat it.

A train plans every route cell by cell. The coarse map-wide planning that other vehicles use for long routes is off for it. A new route also cannot leave the starting cell through the three neighboring cells behind the train, those more than 90 degrees from its current facing. A train therefore cannot start a journey by reversing or turning sharply.

A train treats every cell as open unless the cell is impassable to it. It does not ask an allied object in its way to move aside. When its destination is occupied, it keeps that destination where another vehicle would settle for a free cell nearby. An enemy object in a cell does not block a train, armed or not. Other unarmed vehicles treat a cell held by an enemy as impassable unless they can crush the occupant.

Each time the lead car enters a cell, every object in that cell that is not crushable takes 10,000 damage from the [`C4Warhead`](/keys/c4warhead/). The lead car takes 20 damage from the same warhead for each object hit. A train with [`Crusher=yes`](/keys/crusher/) also crushes allied crushable objects, which other crushers leave alone.

A train never scatters.

A map couples cars into a train by naming, in each vehicle's entry, the vehicle that follows it. When the lead car stops, every car behind it stops too. When a car is destroyed, it is uncoupled from the car ahead, and every car behind it that has a destination stops.

A train may leave the map. Most other objects may leave only while retreating or when their team is leaving the map. Once a train is off the map it is deleted, unless its destination is still inside the playable area or it belongs to a team that is not leaving the map.

A [vehicle thief](/keys/vehiclethief/) never picks a train as a target. When the player points a thief at a train, the click selects the train.

A destroyed train with [`CarriesCrate=yes`](/keys/carriescrate/) drops a crate only when the scenario sets [`TrainCrate`](/keys/traincrate/). [`TruckCrate`](/keys/truckcrate/) does not apply to it.
