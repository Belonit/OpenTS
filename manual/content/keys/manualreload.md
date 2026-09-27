---
key: ManualReload
summary: Has a service depot refill a vehicle's ammunition for free, and stops firing from starting its reload delay.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle with `ManualReload=yes` refills its ammunition at a service depot. Each time the depot services it and its [`Ammo`](/keys/ammo/) is not full, the depot fills it completely at no cost.

That refill replaces the repair step for the same service, so a damaged vehicle is rearmed first and starts repairing at the next one. An undamaged vehicle with ammunition missing is rearmed and released. [What a depot does for free](/systems/repair/#what-a-depot-does-for-free) gives the full order.

The flag also stops firing from starting the vehicle's 450-frame reload delay. That delay matters only to a [`NoMovingFire=yes`](/keys/nomovingfire/) vehicle, which regains one point of ammunition each time the delay runs out while it stands still. With both flags, a vehicle that is not already waiting out the delay regains its first missing point as soon as it stands still. Each further point takes 450 frames.

:::danger[Set the flag only on a VehicleType]
On an AircraftType or InfantryType, servicing the object at a building reads invalid data and can crash the game.
:::
