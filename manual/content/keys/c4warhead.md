---
key: C4Warhead
summary: The warhead used for damage that no weapon deals, such as a demolition charge.
when_omitted:
  kind: value
  value: none
---

`C4Warhead` names the warhead the game uses for damage that no weapon deals. Demolition charges use it, and so do many other events.

Most of these events deal forced damage. Forced damage skips the warhead's [`Verses`](/keys/verses/) table and [`Immune=yes`](/keys/immune/), so the target always takes the full amount. The main events that deal forced damage through this warhead are:

- a demolition charge detonating on a structure;
- a unit docked on a structure when the structure is destroyed;
- the [Destroy attached building](/mapping/actions/taction-destroy-object/) trigger action;
- a train running into an object it cannot crush, which deals 10,000 damage to the object and 20 to the train;
- an object that falls after losing its support, such as a bridge, when it lands;
- a laser fence section blowing up with its post, and a vehicle, infantryman or aircraft in a laser fence section's cell while the fence energizes;
- a vehicle, infantryman or aircraft moving into a raised firestorm wall section;
- a bridge collapsing or losing a section, for the objects on it and those left on a cell they can no longer occupy;
- an infantryman stopped on rock or water, and a vehicle stopped on a cell it cannot enter where no structure stands;
- Tiberium poisoning an infantryman;
- an aircraft, jumpjet or tunneling unit with nowhere to land or surface, and a jumpjet that moves while off the ground during an ion storm;
- collecting an explosive crate, for the collector;
- an engineer [damaging a structure](/systems/capture/#damaging-it-instead) in a multiplayer game;
- a defeated house having all of its objects blown up;
- the [Self destruct](/mapping/missions/tmission-self-destruct/) team mission.

The other events deal an explosion around a point. The warhead's `Verses` table, [`Spread`](/keys/spread/#scope-warheadtype) and `Immune=yes` apply to it as they do to a weapon's blast. The events that explode through this warhead are:

- a Tiberium chain reaction, and the destruction of a Tiberium-spawning terrain object;
- an [`Explodes=yes`](/keys/explodes/#scope-overlaytype) overlay such as a barrel;
- a harvester exploding with its load;
- an aircraft falling to the ground;
- a drop pod whose passenger cannot be placed;
- the fragments of an explosive crate;
- an infantryman demolishing a bridge;
- the [Apply 100 damage at...](/mapping/actions/taction-damage/) trigger action;
- the animation named `INVISO`, which deals its [`Damage`](/keys/damage/#scope-animtype) through this warhead.

The [structure damage tick](/systems/power/#the-structure-damage-tick) a house takes while short of power also uses this warhead without forcing it, so `Verses` and `Immune=yes` apply to it.

A falling aircraft, a stranded vehicle, a destroyed Tiberium-spawning terrain object, a failed drop pod, an explosive crate and a Tiberium chain reaction show explosions chosen from the warhead's [`AnimList`](/keys/animlist/). Over water, a falling aircraft and a stranded vehicle use [`SplashList`](/keys/splashlist/) instead when the warhead sets [`Conventional=yes`](/keys/conventional/).

:::danger[Set `C4Warhead` to a warhead with an `AnimList`]
Without `C4Warhead`, the game crashes the first time any of these happens:

- an aircraft falls to the ground;
- a vehicle is stopped on a cell it cannot enter where no structure stands;
- a Tiberium-spawning terrain object is destroyed;
- a drop pod cannot place its passenger;
- an explosive crate is collected;
- an engineer's damage takes a structure below half strength or below [`ConditionRed`](/keys/conditionred/).

A warhead with no explosion animation for the blast crashes the first five events in the same way. [`AnimList`](/keys/animlist/) covers when a blast has none. Over water, a `Conventional=yes` warhead also crashes a falling aircraft or a stranded vehicle when `SplashList` is empty.
:::

Without `C4Warhead`, the events that explode deal no damage, and neither does the power tick. A Tiberium chain reaction still burns the Tiberium away. Forced damage still lands in full.
