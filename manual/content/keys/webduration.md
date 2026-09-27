---
key: WebDuration
summary: The number of frames a webbed infantryman stays pinned.
see_also: [Webby, WebDurationVariation, IsWebImmune, "system:target-selection"]
when_omitted:
  kind: value
  value: "300"
---

Each webbed infantryman waits this many frames, plus a random shift of up to [`WebDurationVariation`](/keys/webdurationvariation/) frames in either direction, so this figure is the middle of the range, not its upper limit. At fifteen frames a second, the default `300` frames is twenty seconds.

```ini title="rules.ini"
[MyWebWH] ; example WarheadType
Webby=yes
Particle=MyWebSys ; example ParticleSystemType
WebDuration=600 ; forty seconds, before the variation
```

While the wait runs, the infantryman struggles in place. It cannot walk or fire, and the player cannot order it to move. When the wait ends, it drops prone and can act again.

A second web can lengthen the wait but never shorten it. The infantryman keeps whichever is longer, the wait still remaining or the newly drawn one.

This figure also decides when a webbed infantryman becomes a target again. In its automatic target scan, an object whose web weapon has this warhead skips infantry with more than a quarter of this figure still left to wait: at `300`, more than 75 frames. Against a webbed infantryman that it does target, the object normally uses its other weapon and webs the infantryman again only once the wait has run out. [Target selection](/systems/target-selection/#which-weapon-the-score-assumes) covers how the web weapon is chosen.

A vehicle can still choose the web weapon against a webbed infantryman, for example when neither of its weapons can fire at that moment. If more than a quarter of this figure is left to wait, the vehicle drops the target and returns to guard.

The setting is read only while the warhead is [`Webby=yes`](/keys/webby/).
