---
key: MaxBlockCount
summary: A retry count for blocked levitating units that has no effect.
no_effect: true
see_also: ["IntentionalDriftVelocity", "ProximityDistance"]
when_omitted:
  kind: value
  value: "4"
---

The engine counts a levitating unit's blocked moves against this figure, but running out changes nothing, so every value behaves the same.

When the count runs out, the engine clears the unit's destination only if the unit has neither a live target nor a live destination. A unit that meets that condition has no destination left to clear.

A blocked levitating unit instead drifts back to the center of its cell at [`IntentionalDriftVelocity`](/keys/intentionaldriftvelocity/). From there it drifts out toward its target or destination, if it has one, however many times it has been blocked.

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
