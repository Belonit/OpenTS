---
key: FreeAfterPlaying
summary: Frees a demand-loaded animation's artwork each time an animation of the type is removed.
see_also: ["DemandLoad", "Image", "Next"]
when_omitted:
  kind: value
  value: "no"
---

The flag has an effect only on a [`DemandLoad=yes`](/keys/demandload/#scope-animtype) animation.

Each time an animation of the type is removed, however it ended, the type frees its artwork. The next time any animation of the type is drawn, including one that is still playing, the shape is read from disk again.

Set `FreeAfterPlaying=yes` only on a rarely played animation. On a common one, every animation of the type that ends makes the next draw of the type read the shape from disk again.

Only the type an animation ends as frees its artwork. An animation that has chained through [`Next=`](/keys/next/) frees the artwork of its last type, and the earlier types in the chain keep theirs.

[Animation shape](/keys/demandload/#scope-animtype) covers shape ownership and loading.
