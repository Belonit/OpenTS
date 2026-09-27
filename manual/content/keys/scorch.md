---
key: Scorch
summary: Blackens the ground under the animation and sets a small fire burning there.
see_also: ["Crater", "Flamer", "Scorches", "SmallFire"]
when_omitted:
  kind: value
  value: "no"
---

A scorching animation leaves a scorch mark and starts a small fire when it reaches the frame with the largest artwork. A looping animation does this again each time it returns to that frame.

The largest frame is chosen from the whole shape. If it is frame 0 of the shape, the effects happen when the animation starts instead. A looping animation then repeats them only after a [`RandomLoopDelay`](/keys/randomloopdelay/) pause.

If the largest frame is the animation's [`Start`](/keys/start/) frame and `Start` is above `0`, an animation playing forward never leaves the mark or starts the fire.

## The scorch mark

The animation leaves a scorch mark when it is less than 30 leptons above the ground. The mark is a random smudge type with [`Burn=yes`](/keys/burn/) that fits at the animation's position. A smudge type fits only when **none of** these is true:

- the animation's cell lies outside the playfield;
- any cell the mark would cover has a ramp;
- any of those cells has a smudge already;
- any of those cells holds an overlay;
- a structure stands on any of those cells;
- any of those cells is a tile that will not take a smudge ([`Morphable=no`](/keys/morphable/)).

Scorch marks that cover more than one cell are candidates only when the largest frame is more than 48 pixels wide and 40 pixels tall. If no single-cell scorch fits, a multi-cell scorch that fits can still be chosen.

An animation that also sets [`Crater=yes`](/keys/crater/#scope-animtype) leaves a scorch mark half the time and a crater the other half, never both.

## The fire

When the animation is less than 10 leptons above the ground, it also starts the rules' [`SmallFire`](/keys/smallfire/) animation at its position. There is no fire on water, beach, ice or rock, though the scorch mark is not limited that way. The fire does not depend on the scorch mark, so a scorching animation that leaves a crater instead still starts it.

The height limits for the mark and the fire, and the ground limit for the fire, hold only for an animation that is not attached to an object. An attached animation measures its height and the ground type at the wrong place, so whether it leaves the mark or starts the fire cannot be predicted from its height or the ground under it.

The fire plays one or two times the loop count of the `SmallFire` type. If the scorching animation is attached to an object, the fire is attached to that object too.

[`Flamer=yes`](/keys/flamer/) replaces this fire. An animation that sets both still leaves its scorch mark, but starts the flame thrower's scattered fires in place of this single one.
