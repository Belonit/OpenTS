---
key: Inviso
summary: Removes the flight entirely; the projectile appears at its target the moment it is fired and is never drawn.
see_also: [Image, IgnoresFirestorm]
when_omitted:
  kind: value
  value: "no"
---

The projectile is placed on its target's position as it is launched, stopped there, and detonates there. It is never drawn, and neither is its shadow.

An active [firestorm wall](/systems/laser-fences/#projectiles) on the line between firer and target stops it. The projectile is placed at the wall and consumed without detonating, so the shot deals no damage to the wall or to anything else. A wall belonging to the firer's house lets it through, but an ally's wall stops it. [`IgnoresFirestorm=yes`](/keys/ignoresfirestorm/) does not help, because only a projectile in flight reads that setting.

The explosion animation and any lighting flash appear 32 leptons (an eighth of a cell) from the detonation point, in a random direction, so repeated hits do not all show on the same spot. The damage is still dealt at the detonation point.

An aircraft whose first weapon fires an invisible projectile makes no strafing runs.
