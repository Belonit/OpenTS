---
key: FireProne
summary: The stage of the prone firing animation at which an infantry type releases its round.
see_also: ["FireUp", "Sequence", "Crawls"]
when_omitted:
  kind: value
  value: "0"
---

This is [`FireUp`](/keys/fireup/) for a soldier lying down. While the soldier is prone, its round is released when the animation reaches this stage. The figure counts stages of the `FireProne` run in the type's [`Sequence`](/keys/sequence/) section, from `0`.

`FireProne` does not take its value from `FireUp`. A type that sets `FireUp` but not this key releases prone shots on the first stage of its prone firing run.

A figure beyond the run's last stage delays the round. The prone firing run ends first. While the soldier stays prone and keeps its target, the next animation to reach that stage releases the round: the `Prone` run for a soldier lying still, or the `Crawl` run for one that moves. Too large a `FireUp` works differently, because a standing soldier that stays still never fires.
