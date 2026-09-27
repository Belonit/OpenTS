---
key: SpotlightMovementRadius
summary: Distance in leptons behind a structure at which its spotlight's sweep pivots, and the range beyond which a followed target is dropped.
see_also: [SpotlightLocationRadius, SpotlightRadius, HasSpotlight]
when_omitted:
  kind: value
  value: "2000"
---

`SpotlightMovementRadius` places the pivot of a sweeping spotlight and sets how far a following spotlight will chase a target. Only a structure whose type sets [`HasSpotlight=yes`](/keys/hasspotlight/) has a beam.

```ini title="rules.ini"
[General]
SpotlightMovementRadius=2560  ; the sweep pivots ten cells behind the structure
```

A sweeping beam turns about a point this far behind its structure, on the side opposite the starting point that [`SpotlightLocationRadius`](/keys/spotlightlocationradius/) places in front. The beam therefore swings on an arc whose radius is the two keys added together. With both at their built-in values, that radius is a little under twelve cells. A larger value moves the beam farther sideways for the same [`SpotlightAngle`](/keys/spotlightangle/).

The gap between this key and `SpotlightLocationRadius` sets the width of a sweep stage. A beam farther from its structure than `SpotlightLocationRadius` gains one stage for every further tenth of that gap, and each stage widens its detection radius, as [`SpotlightRadius`](/keys/spotlightradius/) describes. Raising this key makes each stage longer, so the beam widens more slowly. Stages keep counting past this distance. With every key at its built-in value, the beam swings all the way around its pivot and reaches stage 40, 5000 leptons from the structure.

If this key is smaller than `SpotlightLocationRadius`, the stages count backward and the detection radius shrinks as the beam moves out. Keep the two keys at least 10 leptons apart, as `SpotlightLocationRadius` explains.

A beam [set to follow a target](/mapping/actions/taction-change-spotlight-behavior/) keeps its target only while the target is closer to the structure than this distance. No other key sets the follow range.

A following beam goes back to sweeping as soon as it has no living target in range. That happens when the target is destroyed or moves beyond this distance. It also happens when no enemy was near the beam when the behavior was set, unless the beam followed a target earlier. If that earlier target still exists and is within this distance, the beam follows it again. The sweep restarts from the middle of the arc, not from where the target led the beam. On the frame it switches, the beam still stands where it left off and already checks for intruders there.
