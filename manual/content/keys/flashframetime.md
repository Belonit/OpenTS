---
key: FlashFrameTime
summary: Frames between repaints of a flashing radar blip.
see_also: ["system:map-visibility", RadarCombatFlashTime]
when_omitted:
  kind: value
  value: "7"
---

When one of the local player's objects takes damage, its radar blip flashes for [`RadarCombatFlashTime`](/keys/radarcombatflashtime/) frames. The blip alternates between the house color and its inverse, holding each color for this many frames, until the flash ends. The first color depends on `RadarCombatFlashTime`; with both keys at their defaults, the flash starts on the house color.

Only the local player's objects flash. An enemy or allied object's blip does not change when it takes damage.

Keep the value above `0`. At `0` the game crashes as soon as one of the local player's objects takes damage. Damage to any other object can also crash it, if the radar redraws that object's blip within `RadarCombatFlashTime` frames of the hit.
