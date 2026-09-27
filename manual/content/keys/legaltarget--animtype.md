---
key: LegalTarget
scope: animtype
label: Animation targetability
no_effect: true
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

An animation can never be a target, whatever this key says. Automatic target scans never consider one. The cursor cannot land on one either: pointing at the map picks the nearest infantry, vehicle, aircraft, structure or veinhole monster drawn near the pointer, or else whatever stands in the cell, and an animation is none of these.

An animation that rides on an object, such as flames on a damaged structure, follows the same rule. The cursor finds only the object underneath, and that object's type decides whether it can be attacked.
