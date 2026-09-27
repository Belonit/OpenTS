---
key: AllowToPlace
summary: Parsed tile-set flag that the engine never uses.
no_effect: true
see_also: [RequiredForRMG, TilesInSet]
when_omitted:
  kind: value
  value: "yes"
---

The engine stores the value on every tile of the set and never reads it back. A set marked `no` still appears on maps and in random maps like any other.
