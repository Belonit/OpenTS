---
key: GuardRange
summary: The distance in cells an object scans for targets while guarding, overriding its weapon range.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "0"
  note: The object scans at the reach of its weapons.
---

```ini title="rules.ini"
[MYTANK] ; example UnitType
GuardRange=7.5
```

`GuardRange` sets how far an object of this type looks for targets on its own. The value is in cells, and fractions are accepted. It sets three scan radii, and [target selection](/systems/target-selection/#scan-radius) lists which mission uses which:

- the **guard radius** is the value itself, except that a healer, such as a medic, scans 2 cells while in Guard;
- the **area radius**, used by Guard Area, is twice the value, at most 16 cells;
- the **patrol radius**, used by Patrol, is twice the value, kept between 7 and 16 cells.

At `0`, the area and patrol radii become twice the longer of its two weapon ranges, with the same limits. A scan at the guard radius then accepts a target only when the weapon the object would choose against that target can reach it.

An engineer always takes that weapon-range guard radius, whatever its `GuardRange`. An engineer with no weapon then accepts a target within `GuardRange` of it. Its area and patrol radii still use the value.

The area and patrol radii also limit how far an object strays:

- A Guard Area object that is neither firing nor already moving somewhere drops its target and heads home once it is more than three quarters of the area radius from its home position.
- A patrolling object takes on a target it cannot already shoot only when the walk to it is shorter than the patrol radius, in cells, plus six.

:::caution[The value is also a fence connection distance]
A [`LaserFencePost=yes`](/keys/laserfencepost/) building uses it as the number of cells it searches in each of the four directions for its neighboring post, and treats anything under one cell as one. A [`FirestormWall=yes`](/keys/firestormwall/) type uses it as the number of cells a newly placed section searches for another section to join, with no such minimum. Both round it down to whole cells, so changing it on those types changes how far a fence run reaches.
:::

`GuardRange=-1` counts as leaving the key out.
