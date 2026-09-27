---
key: AlphaImage
scope: aircrafttype
label: Object light shape
see_also: ["Image"]
when_omitted:
  kind: value
  value: ""
  note: No light shape is loaded and the object contributes nothing to the lighting pass.
---

`AlphaImage=` names a shape that lights the map around each object of the type. The value is a filename without its extension: the engine loads `<value>.SHP` when it reads the type. A type that never names a shape gets no light, and an empty value in a later file does not remove a shape that an earlier file named. Unlike the object's own artwork, the shape is named here directly and not through the [Image ID](/keys/image/).

```ini title="rules.ini"
[MYLAMP] ; a BuildingType
AlphaImage=MYGLOW ; MYGLOW.SHP lights the ground around the lamp
```

The shape is centered on the object and changes the brightness of everything drawn under it. Each pixel's palette index sets the change at that spot: `127` leaves the brightness as it is, higher indexes brighten and lower ones darken.

The light is placed when the object enters the map, and removed when the object leaves it by being destroyed, sold, or loaded into a transport. The light is also removed when the object is captured or starts to cloak. An object that comes back onto the map gets a new light at its new position, and that is the only way a removed light returns.

An overlay or a smudge never gets a light, because it becomes part of its cell as it is placed.

:::caution[The light does not travel with a moving object]
Give `AlphaImage=` to a structure or another object that stays put. The light stays where the object entered the map, so a vehicle drives out from under it and leaves it behind, for example at the factory it was built in.
:::
