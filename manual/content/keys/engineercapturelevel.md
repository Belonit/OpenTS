---
key: EngineerCaptureLevel
summary: The fraction of maximum strength at or below which an engineer's cursor over a non-allied structure is the enter cursor.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "1"
---

Over a non-allied `Capturable=yes` structure that [the engineer cursor rules](/systems/capture/#an-engineer-over-a-structure) cover, the value changes only the cursor a player's engineer shows:

- at or below this fraction of the structure's maximum strength, the enter cursor;
- above it, the ordinary pointer.

The click gives the same capture order either way. Whether the engineer captures or damages the structure on arrival depends on the structure and the game, not on this key, as [Walking in](/systems/capture/#walking-in) explains.

At `1`, every such structure shows the enter cursor, because strength never exceeds its maximum. A lower value makes a healthier structure show the ordinary pointer, as if the engineer could not enter it. At `0.5`, for example, the enter cursor appears only once the structure is at or below half strength.
