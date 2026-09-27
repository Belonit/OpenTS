---
key: BuildupTime
summary: The length of a structure's construction animation, in game minutes.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ".05"
---

`BuildupTime` sets how long a newly placed structure plays its construction animation. A game minute is 900 frames, or 60 seconds at 15 frames a second. The shipped `rules.ini` sets `.06`, which is 54 frames or 3.6 seconds. The engine default of `.05` is three seconds, and `1` is a full minute.

The time is divided evenly across the animation's steps, and each step lasts the result rounded down to a whole frame. The step count is half the number of frames in the [buildup art](/keys/buildup/), or [`GateStages`](/keys/gatestages/) plus one for a [`Gate=yes`](/keys/gate/) type. A value too small to give each step at least one frame skips the animation, and the structure finishes construction as soon as it is placed.

One value covers every structure. A type with more buildup frames spends less time on each frame and takes no longer overall. [Buildup](/systems/production/#buildup) covers what happens while the animation plays and when it ends.

When a scenario starts, a [`Theater=yes`](/keys/theater/) structure's animation is retimed to play every frame of its buildup art over five seconds, and `BuildupTime` does not apply. A `Theater=yes` structure that sets [`DemandLoadBuildup=yes`](/keys/demandloadbuildup/) is the exception and uses this value like any other structure.

Two later events drop the five-second timing for a `Theater=yes` structure: loading a saved game, and starting a map that has a section for the structure. After either one, the animation is timed from `BuildupTime` like any other structure's. If the buildup art has no `.SHP` file, those events leave the structure with no construction animation.
