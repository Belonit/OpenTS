---
key: HoverPad
summary: Gives the structure a free aircraft when it is first built or placed.
see_also: [PadAircraft, SeparateAircraft, Helipad, AIIonCannonHelipadValue]
when_omitted:
  kind: value
  value: "no"
---

A structure with this flag receives one free aircraft when its construction finishes. A structure placed already built receives it when it first appears on the map. Capturing the structure gives the new owner none. The aircraft is the first type listed in [`PadAircraft`](/keys/padaircraft/) and belongs to the structure's house. It appears parked on the structure, at its center and at ground level, facing [`PoseDir`](/keys/posedir/). It starts on guard, linked to the structure as the aircraft docked there.

No aircraft is given when **any of** the following holds:

- [`SeparateAircraft=yes`](/keys/separateaircraft/);
- `PadAircraft` is empty;
- the structure's [`FreeUnit`](/keys/freeunit/) is an aircraft type, even if that aircraft was not given or could not be placed.

The flag is also the last structure test in [the rating a computer house gives each ion cannon target](/systems/superweapons/#the-computers-use), where it selects [`AIIonCannonHelipadValue`](/keys/aiioncannonhelipadvalue/).

:::caution[This flag does not let aircraft dock]
Accepting an aircraft for docking comes from [`Helipad=yes`](/keys/helipad/). The two flags are independent, so a structure with only `HoverPad=yes` receives an aircraft that cannot dock with it.
:::
