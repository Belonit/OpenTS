---
key: MoveFlash
summary: The animation dropped on the cell a move order points at.
see_also: [YSortAdjust]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
MoveFlash=MOVEFLSH ; an AnimType registered in [Animations]
```

When the player orders a move, the named animation plays at the cell the player clicked. It sits at ground height there, or on the bridge deck if the cell has a bridge. A move order for a group plays it at most once, not once per object.

:::danger[Set `MoveFlash` to an existing AnimType]
If no rules file sets `MoveFlash`, or it is set to `none`, the game crashes on the player's first move order.
:::

In a campaign or skirmish game, the marker is an ordinary animation. In a network or Internet game, it plays only on the machine of the player who gave the order, and the game keeps it out of the multiplayer synchronization check. The same order also sets the AnimType's [`YSortAdjust`](/keys/ysortadjust/) to `-5000` on that machine, which draws a ground-layer marker behind the objects around it. The type keeps that value for the rest of the game.

:::danger[Give the marker an AnimType of its own in network games]
Use an AnimType for `MoveFlash` that nothing else creates. Once one player has given a move order, other animations of that type sort differently on that player's machine, and an animation of the type in the ground layer then puts the game out of sync.

Also keep random settings such as [`RandomRate`](/keys/randomrate/) and [`RandomLoopDelay`](/keys/randomloopdelay/) off that type. The marker exists only on one machine, so any random number it draws puts that machine out of step with the others.
:::
