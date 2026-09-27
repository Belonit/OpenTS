---
key: RadarEventColorSpeed
summary: Fraction of the blend between a radar event's two colors covered each time the screen is redrawn.
see_also: ["system:map-visibility"]
when_omitted:
  kind: value
  value: ".05"
---

A [radar event](/reference/enums/radar-event/)'s outline pulses between two colors fixed by its kind. Each time the screen is redrawn, the blend moves this fraction of the way from one color to the other, reversing at either end. At the default, one sweep takes 20 redraws and a full back-and-forth 40. A larger value pulses faster.

The same value sets how quickly the color changes along the outline. Each pixel along an edge moves the blend by two to three times this value, so a larger value also draws more color bands around the box.

At `0` the outline stays in the brighter of its two colors and never pulses. A negative value pulses the same as that value written positive.
