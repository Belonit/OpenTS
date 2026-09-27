---
key: IsLimpetDrone
summary: Runs a vehicle's shape through a ten-frame loop and draws it without facings.
see_also: ["Jellyfish", "Image", "DeploysInto"]
when_omitted:
  kind: value
  value: "no"
---

The flag changes only how a vehicle drawn from shape artwork is animated. The vehicle shows frames 0 to 9 of its shape in a loop, one frame per game frame, and never turns them to match its heading. A voxel vehicle is drawn as usual.

The flag changes nothing else. What a drone turns into through [`DeploysInto`](/keys/deploysinto/), how it moves, and what may target it come from the rest of its section.
