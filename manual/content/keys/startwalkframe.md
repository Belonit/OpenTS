---
key: StartWalkFrame
summary: The frame a shape-drawn vehicle's walking animation begins at.
see_also: ["WalkFrames", "StartStandFrame", "Facings"]
when_omitted:
  kind: value
  value: "0"
---

The walk animation starts at this frame, with one run of [`WalkFrames`](/keys/walkframes/) frames for each of its [`Facings`](/keys/facings/) in turn.

A vehicle with no standing frames also rests on these runs ([`StandingFrames`](/keys/standingframes/) explains).

Setting `StartWalkFrame` moves no other default. The default standing, firing, death and turret start frames are counted from frame 0 whatever this key holds, so set them too when they must follow the moved walk runs.

```ini title="art.ini"
[REAPER] ; the Image ID of the stock Cyborg Reaper
Facings=8
StandingFrames=1
StartStandFrame=0 ; one standing frame per facing, frames 0-7
WalkFrames=12
StartWalkFrame=8  ; eight runs of 12, frames 8-103
```
