---
key: JumpJet
summary: Marks the InfantryType as a jumpjet, so it routes, is targeted and dies as an air unit.
see_also: [Locomotor, MovementZone, InfantryExplode, "system:ion-storms", "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

`JumpJet=yes` does not make the soldier fly. [`Locomotor=`](/keys/locomotor/) must also name the jumpjet locomotor. The soldier flies and plays its flying animations only while that locomotor is in control. During that time, a soldier with a target is drawn facing it.

Routing, targeting and death follow from the flag alone, whatever the locomotor. The choice between flying and walking applies only to a soldier with the jumpjet locomotor.

## Routing

Movement is planned as though the type's [`MovementZone`](/keys/movementzone/) were the infantry zone, whatever it says.

An order may name a cell in any movement zone, and the soldier keeps it. Over a cell the soldier cannot enter, the cursor shows the cannot-move form, and a click sends the soldier to the nearest cell it can enter, in any zone.

A move order over a tunnel entrance, or a cell close to one, offers no action, and the cursor stays blank.

## Flying or walking

Before each leg, a jumpjet decides whether to fly. The tests run in this order, and the first that applies decides:

1. During an [ion storm](/systems/ion-storms/#jumpjet-infantry), it walks.
2. If it is already off the ground, it flies.
3. If it belongs to a human player and starts on a tunnel entrance, or close to one that lies to its north or west, it walks.
4. If the destination lies in a different infantry movement zone, it flies.
5. If the trip is one cell or none, it walks.
6. If the trip spans 12 cells or more, or either end lies outside the playable area, it flies.
7. If the estimated walking distance is over 15 cells, it flies. Otherwise it walks.

To walk, the soldier puts a walking locomotor on top of its jumpjet one. Choosing to fly removes the walking locomotor again.

## Targeting and death

A jumpjet is found by the flying-object passes of a [threat scan](/systems/target-selection/#picking-the-winner), alongside aircraft.

An explosion whose center is above ground level includes any jumpjet within one cell of that center among the objects it damages, as it does aircraft. This is how a shot fired into the air reaches it.

A killed jumpjet plays `[AudioVisual] InfantryExplode` at its position and is removed at once, with no death animation and no corpse. A jumpjet that falls from a height into water leaves a wake and a splash instead.
