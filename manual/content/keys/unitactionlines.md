---
key: UnitActionLines
summary: Draws lines from each selected object to its target, along its route and through its queued destinations.
see_also: ["system:action-lines", AlwaysShowActionLines, ToolTips, SidebarCameoText]
when_omitted:
  kind: value
  value: "yes"
---

`UnitActionLines=yes` lets selected vehicles, infantry and aircraft draw action lines: a line to the object's target, a line along its route, and lines through its queued destinations. Only objects that belong to a house under the player's control draw them. Structures never do. `UnitActionLines=no` turns the lines off for every object, but does not affect the sighting laser.

The lines do not stay up all the time even when the setting is on. [Action lines](/systems/action-lines/) covers when they appear and how `UI.INI` styles them.

The game controls dialog has the same switch. Accepting the dialog applies the change on the next frame and saves it to `sun.ini`.
