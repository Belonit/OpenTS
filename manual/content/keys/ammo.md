---
key: Ammo
summary: The number of shots a runtime instance holds, or the number of visitors a hospital or armory can admit.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "-1"
---

Each object starts with a full pool of shots. Firing spends one shot, and an object whose pool is exactly zero cannot fire. A pool that starts below zero never reaches zero, so the default of `-1` gives an unlimited supply. `Ammo=0` leaves the object unable to fire at all.

How an empty pool refills depends on the object:

- A structure refills its whole pool as soon as it empties. Hospitals and armories are the exception described below.
- A vehicle or aircraft docked at a [`UnitReload=yes`](/keys/unitreload/) building regains one shot at a time. A [`ManualReload=yes`](/keys/manualreload/) vehicle can also refill its whole pool for free at a service depot.
- A [`NoMovingFire=yes`](/keys/nomovingfire/) vehicle also regains one shot at a time while it stands still.
- An infantryman refills its whole pool when its fear wears off. A [`FraidyCat=yes`](/keys/fraidycat/) infantryman panics as it fires its last shot, so it recovers once it calms down. Other infantry stay empty until damage frightens them and they calm down again. A [`Fearless=yes`](/keys/fearless/) or [`Doggie=yes`](/keys/doggie/) infantryman never refills.

On a [`Hospital=yes`](/keys/hospital/) or [`Armory=yes`](/keys/armory/) structure the value counts visits instead of shots. Each infantryman the building admits spends one point, the pool never refills, and the building turns visitors away once it reaches zero. Leaving the key unset gives exactly one visit. [Hospitals and armories](/systems/repair/#hospitals-and-armories) covers the admission.
