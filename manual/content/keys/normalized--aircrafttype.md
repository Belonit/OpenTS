---
key: Normalized
scope: aircrafttype
label: Building animation rate
when_omitted:
  kind: value
  value: "no"
---

On a structure, `Normalized=yes` rescales an animation state's frame delay against the game speed setting, so the animation keeps roughly the same real-time speed at every game speed setting. It applies in two cases only:

- the first animation state the structure enters;
- any animation state set while the scenario is being set up.

The construction state is not rescaled in either case.

Separately, every structure rescales its construction and idle states whatever this flag says. That happens when a queued change of animation state takes effect and each time an animation loops. At those points any other state goes back to its configured delay, so the flag's effect on that state lasts only until its first loop.

An aircraft, infantry type or vehicle stores the flag without effect.
