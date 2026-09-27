---
key: RadarCombatFlashTime
summary: Frames a damaged object's radar blip keeps flashing for.
see_also: ["system:map-visibility", FlashFrameTime]
when_omitted:
  kind: value
  value: "21"
---

When damage has any effect on one of the local player's objects, its radar blip flashes for this many game frames. Fresh damage restarts the count instead of adding to it. Other houses' objects do not flash.

While the count runs, the blip is repainted every [`FlashFrameTime`](/keys/flashframetime/) frames, alternating between its inverted and normal colors, and the last repaint restores the normal color. At the defaults of 21 and 7, the blip turns inverted 7 frames after the hit and returns to normal 7 frames later. Keep this value at least twice `FlashFrameTime`; below that, a blip that stays in place never shows the inverted color.
