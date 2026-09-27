---
key: LimpetFactor
summary: The percentage of a vehicle's speed a limpet attachment takes away.
see_also: [ROT]
when_omitted:
  kind: value
  value: "0"
---

A value of `1` or more makes the weapon attach a limpet instead of firing a shot, whenever the target is a vehicle, infantryman, aircraft or structure. Against any other target, such as a cell, the weapon fires an ordinary shot. An attachment creates no projectile. It does these things in one step:

- marks the target with the firing object's house;
- sets the target's speed multiplier to the percentage that remains, so `50` leaves half;
- plays the weapon's sound and springs the limpet trigger event on the target;
- removes the firing object.

```ini title="rules.ini"
[MyLimpetWH] ; example WarheadType
LimpetFactor=50 ; the target keeps half its speed
```

In the shipped rules, the deployed limpet mine fires the attachment. The limpet drone folds into that structure and has no weapon of its own.

A target can hold one mark from each house. When the firing object's house has already marked the target, firing does nothing: no projectile, no second mark, and the firing object survives. A later mark from another house replaces the speed percentage the target already had.

:::caution[Write a whole number]
The value is truncated to a whole number, so a value of at least `0` and below `1` attaches nothing and the weapon fires an ordinary shot. That includes the percentage form: `LimpetFactor=50%` reads as one half, which truncates to `0`. Do not write a negative value; its effect is undefined.
:::

:::danger[Keep the value at 100 or below]
`100` stops a marked vehicle dead. A value above `100` does not reverse or freeze the target. It multiplies the vehicle's top speed by a huge figure instead: `LimpetFactor=150` multiplies it by about 43 million.
:::

## What a mark does

A mark has these effects on the object holding it:

- A marked vehicle is slowed. Infantry, aircraft and structures keep their full speed.
- A marked object reveals the map around it for its owner and also for every house that has marked it. A marked aircraft reveals only for its owner.
- A marked structure's selection box is drawn in yellow, and the repair cursor is offered over it at any strength. A marked vehicle with [`IsCoreDefender=yes`](/keys/iscoredefender/#scope-unittype) also gets a yellow selection box.
- Other marked vehicles and aircraft draw a different frame of the selection marker art when selected. Marked infantry look the same as unmarked ones.
- The mark carries over when a vehicle deploys into a structure or a structure undeploys into a vehicle.

:::caution[The target's turn rate is not slowed]
A marked vehicle turns its body and turret at full speed, however high this value is. The attachment slows the turn rate of the firing object instead, which is removed in the same step.
:::

## Removing a mark

Healing removes every mark on an object and restores its full [`ROT`](/keys/rot/#scope-aircrafttype), so a repair weapon undoes an attachment. A repair step from a structure that services docked objects, such as a service depot, also removes the marks, even from an object at full strength.
