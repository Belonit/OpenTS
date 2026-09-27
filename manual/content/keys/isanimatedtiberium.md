---
key: IsAnimatedTiberium
summary: Removes the animation once the overlay that placed it is gone or no longer names it.
see_also: ["CellAnim", "system:tiberium"]
when_omitted:
  kind: value
  value: "no"
---

The animation deletes itself once the overlay that placed it is removed, or is replaced by an overlay whose [`CellAnim`](/keys/cellanim/) names a different animation. The check runs on every logic frame after any creation delay has run.

An overlay that names a `CellAnim` creates that animation one and a half cells along each map axis from its own cell. The flag makes the animation look back by the same offset to find that cell, so it works only on an animation an overlay placed. Created any other way, the animation checks a cell that has nothing to do with it.

Any animation an overlay places through `CellAnim` takes the color of the Tiberium in the overlay's cell at the moment it is placed, whether or not it sets the flag. Its settings choose its artwork.

The color is not saved with the animation. After a saved game is loaded, a cell animation without the flag is drawn in its type's usual palette.

:::caution[A loaded game recolors IsAnimatedTiberium animations]
After a saved game is loaded, a flagged animation takes the color of the Tiberium in the cell it stands in, one and a half cells from the overlay's cell. If that cell holds no Tiberium, the animation is drawn in its type's usual palette.
:::

```ini title="art.ini"
[BIGBLUE] ; the animation the large Tiberium overlays name as their CellAnim
IsAnimatedTiberium=yes
Surface=yes
```
