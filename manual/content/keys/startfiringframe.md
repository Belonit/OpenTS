---
key: StartFiringFrame
summary: The frame a shape-drawn vehicle's firing animation begins at.
see_also: ["FiringFrames", "StandingFrames", "WalkFrames", "Facings"]
when_omitted:
  kind: computed
  note: Facings × (StandingFrames + WalkFrames), counted from frame 0. A vehicle with no firing frames takes the default StartStandFrame, even when the section sets StartStandFrame.
---

The firing animation starts at this frame, with one run of [`FiringFrames`](/keys/firingframes/) frames for each facing in turn. The default assumes the shape file holds the walk runs first, then the standing runs, then the firing runs. It is computed from the [`Facings`](/keys/facings/), [`WalkFrames`](/keys/walkframes/) and [`StandingFrames`](/keys/standingframes/) values in the same section.

Set this key when the artwork uses a different order. The stock Core Defender holds its standing frames first, its walk frames next and its firing frames last:

```ini title="art.ini"
[DEFENDER] ; the Image ID of the stock Core Defender
Facings=8
WalkFrames=8
FiringFrames=12     ; also gives it one standing frame per facing
StartStandFrame=0   ; frames 0-7
StartWalkFrame=8    ; eight runs of 8, frames 8-71
StartFiringFrame=72 ; eight runs of 12, frames 72-167
```
