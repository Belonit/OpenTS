---
key: Cameo
summary: The SHP file drawn as an object's sidebar cameo.
see_also: ["system:sidebar"]
when_omitted:
  kind: value
  value: ""
  note: No cameo file is selected and XXICON.SHP is drawn in the slot instead.
---

The value is a filename without its `.SHP` extension. A file that cannot be loaded also leaves `XXICON.SHP` in the cameo slot.

The key is read from the section of the object's [Image ID](/keys/image/), so types that share an image share a cameo.

Loading a saved game fetches every cameo again, with two differences. A type whose image section names no cameo, or names `XXICON`, also looks for the key in the section of its own ObjectType ID. A file that cannot be loaded leaves the cameo blank.

[What a cameo shows](/systems/sidebar/#what-a-cameo-shows) covers the darkening, clock and captions drawn over it.
