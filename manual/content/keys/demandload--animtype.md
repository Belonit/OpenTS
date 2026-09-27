---
key: DemandLoad
scope: animtype
label: Animation demand loading
see_also: ["FreeAfterPlaying", "Image", "NewTheater", "Theater"]
when_omitted:
  kind: value
  value: "no"
---

The animation's shape file is not loaded with the rest of the art when the settings or a saved game are read. The engine loads it the first time the animation needs its artwork, and then fills in any frame count or loop end the section left unset.

The file name is the [Image ID](/keys/image/#scope-animtype) with a `.SHP` extension, or the AnimType ID when no image is set. [`Theater=yes`](/keys/theater/#scope-animtype) uses the AnimType ID with the theater's extension instead, and [`NewTheater=yes`](/keys/newtheater/#scope-animtype) adjusts the ordinary name for the theater.

Once loaded, the shape stays in memory until the next scenario is loaded. [`FreeAfterPlaying=yes`](/keys/freeafterplaying/) releases it sooner, each time an animation of the type finishes, and the next animation of the type loads it again.
