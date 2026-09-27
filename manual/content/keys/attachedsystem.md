---
key: AttachedSystem
summary: The particle system created with a voxel animation and destroyed with it.
see_also: ["TrailerAnim", "Duration", "StartSound"]
when_omitted:
  kind: value
  value: none
---

Each piece of the voxel animation gets one particle system of the named type, created with the piece. The system is removed when the piece is removed, or sooner if it ends by itself, as [Ending a system](/systems/particle-systems/#ending-a-system) describes. The system starts at the coordinate the piece was created for. For a meteor, that is the target it flies toward, not the point where it first appears.

The system's [`BehavesLike`](/keys/behaveslike/#scope-particlesystemtype) setting decides whether it follows the piece:

- `Smoke` moves with the piece every frame and keeps the offset it started at. Ordinary debris starts on top of its system, so the plume travels with it.
- `Fire` removes itself on its first frame, because a piece of debris cannot fire a weapon.
- Every other behavior stays where it was created, however far the piece flies.

A meteor's `Smoke` plume starts at the meteor's target and moves in parallel with the meteor. It stays as far from the meteor as the meteor's starting point was from the target.

A name that matches no registered particle system still creates one. It uses a new particle system type of that name, and the type's section in `rules.ini` is not read. The type keeps its built-in values unless a later rules file or the map has a section of that name.

For a trail made of animations, use [`TrailerAnim`](/keys/traileranim/#scope-voxelanimtype).
