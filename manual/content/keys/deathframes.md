---
key: DeathFrames
summary: The number of frames in the wreck animation a destroyed shape-drawn vehicle plays before it explodes.
see_also: ["StartDeathFrame", "DeathFrameRate", "MaxDeathCounter", "CrewEscape"]
when_omitted:
  kind: value
  value: "0"
---
Above `0`, a destroyed vehicle stays on the map as a wreck. The destroying hit leaves it at one point of strength and unable to move. The wreck explodes and is removed once [`MaxDeathCounter`](/keys/maxdeathcounter/) game frames have passed. At `0` the destroying hit removes the vehicle at once.

Further hits during the death animation grant no experience or additional kills and do not repeat destruction effects such as Tiberium drops.

Keep the value between `0` and `127`. The engine stores it in a single signed byte, so values from `128` to `256` wrap to zero or a negative number and turn the wreck off.

A vehicle that leaves a wreck skips the usual effects of destruction, both when it is destroyed and when the wreck later explodes:

- no "unit lost" announcement;
- no passengers escape;
- no crate drops, even with [`CarriesCrate=yes`](/keys/carriescrate/);
- no crew survivor appears, whatever [`CrewEscape`](/keys/crewescape/) holds.

The run has one set of frames for every facing, so the wreck plays the same frames whichever way the vehicle was pointing. It starts at [`StartDeathFrame`](/keys/startdeathframe/), advances one frame every [`DeathFrameRate`](/keys/deathframerate/) game frames, and holds its last frame once it gets there. Only shape artwork draws these frames. A [`Voxel=yes`](/keys/voxel/) vehicle with a value above `0` still becomes a wreck.

```ini title="art.ini"
[MYWALKER] ; the Image ID of a shape-drawn UnitType
Facings=8
WalkFrames=12
DeathFrames=13     ; one run of 13, from frame 8 × (0 + 12 + 1) = 104
DeathFrameRate=3   ; 39 game frames of animation, about two and a half seconds
MaxDeathCounter=64 ; the wreck is removed after 64 game frames
```
