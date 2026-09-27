---
key: AnimAux1
summary: The first frame, frame count and step delay of a structure's first auxiliary animation.
see_also: ["AnimIdle", "AnimActive", "AnimAux2"]
when_omitted:
  kind: value
  value: "0,1,0"
---

`AnimAux1` is the frame sequence a [`NukeSilo=yes`](/keys/nukesilo/) structure plays while it holds its door open for a launch. No other structure plays it. The value takes the same three numbers as [`AnimIdle`](/keys/animidle/): first frame, frame count and delay. The delay is used as written, with no game-speed adjustment. A damaged structure running this sequence draws damaged frames placed after the end of all four sequences, as `AnimIdle` describes.

The silo switches to this sequence when its [`AnimActive`](/keys/animactive/) door-opening sequence reaches its last frame. The missile leaves 14 game frames later, and the silo then closes its door with [`AnimAux2`](/keys/animaux2/).
