---
key: CloakingStages
summary: The number of fade stages an object's cloak is measured against.
see_also: [CloakingSpeed, "system:cloaking"]
when_omitted:
  kind: value
  value: "9"
---

`CloakingStages` sets how many steps make up a complete cloaking fade for a vehicle, infantryman or aircraft. How the object is drawn depends on the fraction of those steps it has passed. A higher value spreads the same bands of appearance over more steps and adds no new bands. [The four states](/systems/cloaking/#the-four-states) lists the bands and where each fade ends.

The value also sets where the fade back into view starts. An object that is uncloaked restarts one step below this value and counts down to zero.

Keep the value above `0`. At `0` or below, an object that starts to cloak never finishes hiding.

A structure's fade does not use this value. Structures fade through fifteen fixed levels of translucency instead.
