---
key: ShouldFogRemove
summary: Hides the animation while the ground it plays over is under the fog of war.
see_also: ["ActiveAnim", "system:map-visibility"]
when_omitted:
  kind: value
  value: "yes"
---

`ShouldFogRemove=yes` hides the animation under the fog of war. It does not lift fog or reveal anything.

An animation that does not belong to a structure is hidden while the cell under its center is fogged. This includes an animation attached to a moving object, such as a fire burning on a vehicle: the fog is tested at the animation's own cell.

An animation that belongs to a structure is hidden while the structure is fogged. The player sees the structure as it was last seen, with each of its animations frozen on the frame it had reached. When the fog lifts, the live animations are drawn again.

With `ShouldFogRemove=no`, the animation is drawn over fogged ground as it plays. A structure's animation keeps playing on top of the structure's frozen image. An explosion or other effect set this way shows the player activity under the fog.

[Shroud, fog and the radar map](/systems/map-visibility/#the-fog-of-war) describes what the fog remembers and when it lifts.
