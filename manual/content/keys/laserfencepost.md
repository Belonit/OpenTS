---
key: LaserFencePost
summary: Whether the structure anchors laser fence segments run out from it.
see_also: ["system:laser-fences", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

A `LaserFencePost=yes` structure is a laser fence post. It searches north, east, south and west for another post of the same house, up to [`GuardRange`](/keys/guardrange/) cells away, and lays a run of [`LaserFence=yes`](/keys/laserfence/) segments to each post it finds. [Finding the far post](/systems/laser-fences/#finding-the-far-post) covers what blocks the search, and [Laying the run](/systems/laser-fences/#laying-the-run) covers which cells refuse a segment.

`GuardRange` counts whole cells here: a fractional value is rounded down, and a post always reaches at least one cell.

A run is live only while the posts at both ends are [operational](/systems/power/#defenses), have finished building, and are not being sold or undeployed. If either post fails any of these, the whole run goes slack and its segments stay in place. [Energizing the run](/systems/laser-fences/#energizing-the-run) covers what a run destroys as it goes live.

A post switches only the runs that end at it. A run between two other posts that passes alongside this post is not affected by it.

Removing a post removes every run it holds: destroying it destroys the segments, and selling or undeploying it deletes them. [What lowers or removes a run](/systems/laser-fences/#what-lowers-or-removes-a-run) lists every case.

On the sidebar, a post's cameo sorts with the walls; [The order of the strips](/systems/sidebar/#the-order-of-the-strips) covers the full order.
