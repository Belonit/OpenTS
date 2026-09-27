---
key: Crushable
scope: animtype
label: Crushable by vehicles
no_effect: true
see_also: [CrushSound, Strength, Crusher]
when_omitted:
  kind: value
  value: "no"
---

A crusher looks for its victims among the objects occupying a cell, in the cell's overlay, and in the target it is attacking or the attacker that hit it. An animation is none of these: placing one does not make it an occupant of the cell it is drawn over, and it can be neither a target nor an attacker. No crush path reads the flag for an animation.
