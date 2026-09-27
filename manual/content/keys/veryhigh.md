---
key: VeryHigh
summary: Raises a homing projectile's cruising clearance and starts its dive farther from the target.
see_also: [ROT, High, Airburst]
when_omitted:
  kind: value
  value: "no"
---

Only a projectile steered by the homing flight model is affected: one whose [`ROT`](/keys/rot/#scope-bullettype) is above zero.

The setting changes how the projectile approaches a ground target. While it is far from the target, it follows the terrain at a set clearance above the ground ahead of it. Near the target, it stops following the ground and dives straight at the target. [Steered flight](/systems/projectile-flight/#steered-flight) lists when a projectile follows the terrain at all; a launching projectile, for example, never does.

| | Ordinary homing projectile | `VeryHigh=yes` |
| --- | --- | --- |
| Clearance above the ground ahead | One terrain level for each whole cell still to the target, up to five levels (about two cells of height) | Ten terrain levels (about four cells of height), whatever the distance to the target |
| Starts its dive | Within three cells of the target, measured horizontally | Within six cells |

A `VeryHigh=yes` projectile therefore comes down on its target from higher and from farther out.

The setting also exempts the projectile from the [stall check](/systems/projectile-flight/#steered-flight), which otherwise detonates a homing projectile that has nearly stopped closing on its target.

A projectile chasing an aircraft never follows the terrain and flies straight at the aircraft, so against aircraft only the stall-check exemption remains.

On an [`Airburst=yes`](/keys/airburst/) projectile the setting changes nothing. `Airburst` already gives ten levels of clearance, keeps the projectile following the terrain all the way to the target, and exempts it from the stall check.

The setting is unrelated to [`High`](/keys/high/#scope-bullettype), which lets a projectile fly through the cell of a `High=yes` overlay.
