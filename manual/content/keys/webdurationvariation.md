---
key: WebDurationVariation
summary: The number of frames the web duration is shifted at random in either direction.
see_also: [Webby, WebDuration]
when_omitted:
  kind: value
  value: "25"
---

Each infantryman caught by a web draws a whole number at random between minus and plus this figure, inclusive, and adds it to [`WebDuration`](/keys/webduration/). Infantry caught by the same shot can break free at different times. At `25` and the default `WebDuration`, the waits run from 275 to 325 frames, a spread of a little over three seconds at fifteen frames a second. At `0`, every infantryman waits exactly `WebDuration`.

```ini title="rules.ini"
[MyWebWH] ; example WarheadType
Webby=yes
Particle=MyWebSys ; example ParticleSystemType
WebDuration=600
WebDurationVariation=90 ; each infantryman waits 510 to 690 frames, 34 to 46 seconds
```

A negative figure behaves exactly like its positive counterpart.

The setting is read only while the warhead is [`Webby=yes`](/keys/webby/).

:::caution[Keep the variation below WebDuration]
The shifted wait has no lower limit. When a draw brings it to zero or below, the web does not hold the infantryman. One that was free plays the struggle animation once, drops prone and can act again. One that was already webbed keeps the wait it had left. The hit deals no damage either way.
:::
