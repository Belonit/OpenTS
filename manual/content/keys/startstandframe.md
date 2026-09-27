---
key: StartStandFrame
summary: The frame a shape-drawn vehicle's standing artwork begins at.
see_also: ["StandingFrames", "WalkFrames", "Facings", "StartWalkFrame"]
when_omitted:
  kind: computed
  note: Facings × WalkFrames, counted from frame 0 whatever StartWalkFrame holds; 0 for a vehicle with no standing frames, which is drawn from its walk runs instead.
---

The standing frames start at this frame, with one run of [`StandingFrames`](/keys/standingframes/) frames for each facing in turn. A vehicle standing still in its cell shows the first frame of its facing's run.

The default places the standing runs right after the walk runs. It is computed from the [`Facings`](/keys/facings/) and [`WalkFrames`](/keys/walkframes/) values in the same section, so changing either moves it.

Set this key when the artwork does not put the standing frames after the walk frames. The stock Core Defender and Cyborg Reaper both hold their standing frames first and their walk frames after them:

```ini title="art.ini"
[DEFENDER] ; the Image ID of the stock Core Defender
Facings=8
WalkFrames=8
FiringFrames=12   ; also gives it one standing frame per facing
StartStandFrame=0 ; frames 0-7
StartWalkFrame=8  ; frames 8-71
```
