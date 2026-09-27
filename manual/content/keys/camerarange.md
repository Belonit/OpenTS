---
key: CameraRange
summary: Parsed distance that the engine never uses.
no_effect: true
see_also: ["system:map-visibility"]
when_omitted:
  kind: value
  value: "9"
---

The game reads this distance, in cells, and never uses it. The name refers to an aircraft whose [`Camera=yes`](/keys/camera/) weapon reveals the ground below it instead of firing. That behavior is compiled out of the game, and even there it revealed a fixed nine cells without reading this key.
