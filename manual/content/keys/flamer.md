---
key: Flamer
summary: Throws one to three fires onto the ground around the animation.
see_also: ["Scorch", "SmallFire", "LargeFire"]
when_omitted:
  kind: value
  value: "no"
---

When the animation shows its largest frame, the one with the biggest drawn area, it starts fires around itself:

- one [`SmallFire`](/keys/smallfire/) 64 leptons away;
- a 50% chance of a second `SmallFire` 160 leptons away;
- a 50% chance of a [`LargeFire`](/keys/largefire/) 112 leptons away.

Each fire is placed at its distance in a random direction and then moved to the nearest infantry position in that cell, whether or not something already stands there. It sits at ground level, or on the bridge deck when that cell is under a bridge and the animation is at deck height or above. The animation's height and the terrain do not stop the fires, so an animation over water or high in the air still starts fires on the ground beneath it.

Each fire plays one or two times the [`LoopCount`](/keys/loopcount/) of its fire type, or once if the fire type sets none.

When the fires start depends on which frame is the largest:

- When the largest frame is frame 0 of the shape, the fires start each time the animation starts. That covers its creation or the end of its creation delay, the end of each [`RandomLoopDelay`](/keys/randomloopdelay/) pause, and a switch to this type through [`Next=`](/keys/next/). Showing frame 0 later starts none.
- Otherwise, the fires start each time the animation advances onto the largest frame, so a looping animation starts a new set on each pass through it. The frame an animation or a loop pass opens on is not advanced onto. A largest frame equal to [`Start`](/keys/start/) therefore starts no fires on the first pass, and one equal to [`LoopStart`](/keys/loopstart/) starts none on the later passes.
- A largest frame outside the frames `Start` and [`End`](/keys/end/) select, other than frame 0, starts no fires.
- A [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype) animation starts fires only when its largest frame is frame 0.

`Flamer=yes` replaces the single fire that [`Scorch=yes`](/keys/scorch/) would start, and does not scorch or crater the ground by itself. Add `Scorch=yes` for scorch marks as well.

The shipped `art.ini` sets `Flamer` on no animation.
