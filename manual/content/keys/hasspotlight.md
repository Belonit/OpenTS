---
key: HasSpotlight
summary: Whether a structure has a swept spotlight beam.
see_also: [SpotlightLocationRadius, SpotlightMovementRadius, SpotlightRadius, LightIntensity, "system:power"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[GASPOT] ; the stock light tower
HasSpotlight=true
```

A structure with the flag gets a spotlight beam when it is placed on the map and loses it when it is taken off the map. The beam starts out sweeping. Successive beams start their sweep in alternating directions, so a row of towers does not swing in unison.

The `[General]` spotlight settings control the beam:

- [`SpotlightLocationRadius`](/keys/spotlightlocationradius/) and [`SpotlightMovementRadius`](/keys/spotlightmovementradius/) place the beam and its pivot.
- [`SpotlightAngle`](/keys/spotlightangle/), [`SpotlightSpeed`](/keys/spotlightspeed/) and [`SpotlightAcceleration`](/keys/spotlightacceleration/) drive the sweep.
- [`SpotlightRadius`](/keys/spotlightradius/) sets the base radius within which a sweeping beam detects an intruder. Detection only springs the [Enemy In Spotlight...](/mapping/events/tevent-enemy-in-spotlight/) trigger events on the structure's tag, and a structure with no tag does not look for intruders.

The beam is drawn, and detects intruders, only while its structure is operational, as [Fields, fences and lights](/systems/power/#fields-fences-and-lights) describes.

A map can give each placed structure its own [spotlight behavior](/reference/enums/spotlight-behavior/), so a tower can start with its beam circling, following the nearest non-allied soldier or vehicle near the beam, or switched off and invisible. A following beam with nothing to follow goes back to sweeping. The [Change Light Behavior](/mapping/actions/taction-change-spotlight-behavior/) trigger action switches the beam of every structure tagged with the trigger between those states. Neither setting gives a beam to a structure without the flag.

The flag has nothing to do with the colored glow a structure casts on the ground around it, which [`LightIntensity`](/keys/lightintensity/) sets. A type may set either, both or neither.
