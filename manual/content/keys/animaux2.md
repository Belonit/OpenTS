---
key: AnimAux2
summary: The first frame, frame count and step delay of a structure's second auxiliary animation.
see_also: ["AnimIdle", "AnimActive", "AnimAux1"]
when_omitted:
  kind: value
  value: "0,1,0"
---

`AnimAux2` is the frame sequence a [`NukeSilo=yes`](/keys/nukesilo/) structure plays while it closes its door after a launch. No other structure plays it. The value takes the same three numbers as [`AnimIdle`](/keys/animidle/): first frame, frame count and delay. The delay is used as written, with no game-speed adjustment. A damaged structure running this sequence draws damaged frames placed after the end of all four sequences, as `AnimIdle` describes.

The silo switches to this sequence once the missile has left, after [`AnimAux1`](/keys/animaux1/) has held the door open. Six game frames later it returns to `AnimIdle`, whether or not this sequence has reached its last frame.
