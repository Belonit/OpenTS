---
key: Surface
summary: Places the animation in the ground layer, sorted among the objects on the ground, instead of in the layer above them.
see_also: ["YSortAdjust", "Flat", "Tiled", "FlightLevel"]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, the animation is in the ground layer, the layer of objects on the ground such as infantry, vehicles, structures and trees. The ground layer is sorted, so the animation is drawn in its place among those objects: in front of some and behind others.

With `no`, the animation is in the layer above. That layer is drawn after the whole ground layer and after the artwork attached to structures, so the animation covers all of them. Use `yes` for fire, smoke and a structure's animations, and `no` for explosions and other effects that should appear in front of everything.

[`YSortAdjust`](/keys/ysortadjust/) works only with `yes`, because no other layer is sorted.

An animation attached to an object is always in the ground layer, so the flag matters only for an animation that stands on its own.

The flag does not change the animation's height. The animation appears at the height the code that created it chose.
