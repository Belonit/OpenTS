---
key: AnimActive
summary: The first frame, frame count and step delay of a structure's working animation.
see_also: ["AnimIdle", "AnimAux1", "AnimAux2"]
when_omitted:
  kind: value
  value: "0,1,0"
---

`AnimActive` is the frame sequence a structure's artwork plays while the structure is working. The value takes the same three numbers as [`AnimIdle`](/keys/animidle/): first frame, frame count and delay. The delay is used as written, with no game-speed adjustment. A damaged structure running this sequence draws damaged frames placed after the end of all four sequences, as `AnimIdle` describes.

Three kinds of structure play the sequence:

- A [`ConstructionYard=yes`](/keys/constructionyard/) structure plays it while a structure it placed is being built.
- A [`UnitReload=yes`](/keys/unitreload/) structure plays it while it reloads the object docked with it.
- A [`NukeSilo=yes`](/keys/nukesilo/) structure plays it to open its door for a launch. The silo stays on the sequence until it reaches the last frame, then switches to [`AnimAux1`](/keys/animaux1/). With a delay of `0`, it switches to `AnimAux1` at once.
