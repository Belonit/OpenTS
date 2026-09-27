---
key: PoseDir
summary: Facing an aircraft parks at when it has nothing else to line up with.
see_also: [PadAircraft, HoverPad, SeparateAircraft]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[AudioVisual]
PoseDir=0
```

Keep this at `0`, north. Two uses read the number on different scales, so any value from 1 to 255 gives them different headings.

## Placing an aircraft

When an aircraft is put on the map beside or on a structure, it faces this direction on a 256-step scale. `0` is north, `64` east and `128` south, and each step is about 1.4 degrees. This covers:

- a structure's free aircraft, including the one a helipad gets when it is built;
- a new aircraft from its factory, when the factory is not in contact with another aircraft or an ion storm is running. During a storm the aircraft is placed on a nearby cell instead of the pad.

Outside an ion storm, a new aircraft whose factory is already in contact with another aircraft, such as one parked on its pad or one flying back to it, flies in from the map edge facing north. It does not use this setting.

## Landing

When an aircraft comes within a cell of its destination with nothing to aim at, or while strafing, it turns to a landing facing. The first of these that applies decides the facing:

1. An aircraft in radio contact with a helipad or a vehicle copies that object's facing.
2. An aircraft carrying cargo keeps its current heading.
3. Any other aircraft takes this value as an eight-step compass facing, where `1` is northeast and `4` is south.

The landing scale uses only the lowest three bits of the number. Values `8`, `16`, `24` and so on all mean north there, while the placement scale gives each of them a different heading.
