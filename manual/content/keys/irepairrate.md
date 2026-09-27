---
key: IRepairRate
summary: The interval between servicing steps inside a hospital, and an armory's promotion delay.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: ".016"
---

The count each building waits for is this value times 900, which is 14.4 at the default `.016`. A larger value keeps the occupant inside longer.

- A [hospital](/systems/repair/#hospitals-and-armories) heals one step each time its count reaches that figure, and releases the occupant once it is undamaged.
- An [`Armory=yes`](/keys/armory/) building [promotes the occupant](/systems/veterancy/#promotion-without-kills) and releases it the first time its count reaches that figure.

The two buildings count at different speeds. A hospital's count advances every frame, so the default `.016` gives a step every 15 frames. An armory's count advances once per update of its repair mission, which the [`Rate=`](/keys/rate/#scope-mission-behavior) of the `[Repair]` mission sets. At the default mission rate, the same `.016` holds the occupant for about 210 frames.

Both building kinds share the setting, so neither can be tuned alone. Vehicle service depots use [`URepairRate`](/keys/urepairrate/) instead.
