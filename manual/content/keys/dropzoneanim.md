---
key: DropZoneAnim
summary: The flare that marks a reinforcement drop zone and lights the ground around itself.
see_also: [DropZoneRadius, "system:map-visibility"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
DropZoneAnim=MYBEACON ; an AnimType registered in [Animations]
```

The [Drop Zone Flare (waypoint)](/mapping/actions/taction-dz/) trigger action creates this animation at the ground height of its waypoint, or at bridge-deck height when the cell has, or had, a bridge. The flare deals none of the animation's damage. Its sound and any Tiberium chain reaction it sets off take effect once, when the flare appears. Scorch marks, craters and fire that the animation type leaves still appear.

Two more behaviors belong to the animation type, so they apply to every animation of this type, whatever created it:

- It reveals the ground around itself when it is created, out to [`DropZoneRadius`](/keys/dropzoneradius/). The reveal happens once and covers every human player and every house that [shares a human player's view](/systems/map-visibility/#whose-looks-count), whichever house's trigger created the flare.
- It is removed as soon as a structure stands in its cell, so a flare disappears when a player builds on the spot it marks.

:::caution[Give the flare an animation type of its own]
If this key names an animation type that is also used elsewhere, every use of that type reveals the map and disappears under structures.
:::

:::danger[Set DropZoneAnim before a scenario uses the drop zone action]
If `DropZoneAnim` names no animation type, the game crashes when a Drop Zone Flare action runs.
:::
