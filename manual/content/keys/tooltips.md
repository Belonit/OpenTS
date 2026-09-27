---
key: ToolTips
summary: Pops the interface tooltips up while a scenario is running.
see_also: [SidebarCameoText, UnitActionLines]
when_omitted:
  kind: value
  value: "yes"
---

`ToolTips=yes` shows tooltips over the sidebar cameos, the tabs and the rest of the in-game interface while a scenario is being played. Tooltips are off in the menus, and are switched off when the in-game options open, whatever this setting says. [`SidebarCameoText`](/keys/sidebarcameotext/) describes what a cameo's tooltip shows.

The game controls dialog has the same switch, and accepting the dialog saves the choice to `sun.ini`. A change made during a game takes effect at once. A change made from the main menu takes effect when the next scenario starts.
