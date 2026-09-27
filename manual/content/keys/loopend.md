---
key: LoopEnd
summary: The frame that ends every pass of a looping animation except the last.
see_also: ["LoopStart", "LoopCount", "End", "Reverse", "TurretAnim"]
when_omitted:
  kind: computed
  note: The frame count of the shape the type first gets hold of, or zero if it never gets one.
---

The value is a frame number in the shape. [`End`](/keys/end/), by contrast, counts stages from [`Start`](/keys/start/). When a pass reaches this frame, the animation jumps back to [`LoopStart`](/keys/loopstart/) before the frame is drawn, so the `LoopEnd` frame itself never appears.

It ends every pass except the last. The last of the [`LoopCount`](/keys/loopcount/) passes runs to the end of the `End` stage count instead. If the two settings disagree, the last pass plays a different stretch of the shape than the passes before it.

Setting `End=` alone does not shorten the loop. An omitted `LoopEnd` is taken from the shape's full frame count before `End` is read, so the middle passes still run over the whole shape. To shorten a looping animation, set both keys.

`LoopEnd=-1` takes the `End` stage count instead, when the first animation of the type is created. That count is then treated as a frame number, so with a nonzero `Start` the middle passes stop `Start` frames short of where the last pass ends.

A [`Reverse=yes`](/keys/reverse/) animation starts every pass on frame `Start` plus `LoopEnd` and steps backward. With a nonzero `Start` and more than one pass, each reversed pass ends at its first frame advance, as [`Start`](/keys/start/#what-is-counted-from-here-and-what-is-not) describes.

A structure with a charging weapon ([`Charges=yes`](/keys/charges/)) uses this value from the animation in its [`TurretAnim`](/keys/turretanim/) slot. The weapon is charged once the charge sequence reaches that frame.
