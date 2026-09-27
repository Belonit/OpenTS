---
key: FirestormWarhead
summary: The WarheadType a raised firestorm wall destroys objects with.
see_also: [FirestormWall, C4Warhead, "system:laser-fences"]
when_omitted:
  kind: value
  value: none
---

`FirestormWarhead` is the warhead a raised firestorm wall kills with. It applies to:

- an object in a raised section's cell, when the section [sweeps its cell](/systems/laser-fences/#what-a-raised-section-destroys);
- an object with the flying or jumpjet locomotor moving over a raised section.

The victim takes damage equal to its remaining strength. The damage is forced, so armor and [`Immune=yes`](/keys/immune/) do not reduce it. No attacker is credited with the kill, and no crew escapes, although [a hijacker](/systems/capture/#stealing-a-vehicle) who took the vehicle still steps out.

The warhead decides how the victim dies. An infantryman dies as the warhead's [`InfDeath`](/keys/infdeath/) selects, except jumpjet infantry and crawling cyborgs, which explode. A standing cyborg is removed at once, so only an `InfDeath` that leaves an animation (`3`, `4` or `5`) shows anything. A vehicle or aircraft killed by this warhead throws [`DefaultFirestormExplosionSystem`](/keys/defaultfirestormexplosionsystem/) sparks instead of its usual explosion, with the exceptions given in [What a raised section destroys](/systems/laser-fences/#what-a-raised-section-destroys).

The [approach sweep](/systems/laser-fences/#what-a-raised-section-destroys), which destroys objects moving into a raised section's cell, uses [`C4Warhead`](/keys/c4warhead/) instead, so its victims die with that warhead's effects.
