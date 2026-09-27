---
key: Pip
summary: The color of the pip a transport draws for this soldier while it is carried.
see_also: [Passengers, PipScale, MaxPips, Size, "system:transports"]
when_omitted:
  kind: value
  value: green
---

`Pip` sets the color of the pips this soldier fills in a transport's pip row while it rides inside. The row appears under a selected transport that the player or an ally owns, with the exceptions [`PipScale`](/keys/pipscale/) lists. Each passenger fills as many pips as its [`Size`](/keys/size/#scope-aircrafttype), and at least one. An infantry passenger's pips take its type's `Pip` color, any other passenger's pips are green, and free space is drawn empty. The value has no other effect, so it does nothing for an infantry type that never rides in a transport.

```ini title="rules.ini"
[MYCOMMANDO] ; example InfantryType
Pip=white
```

The row's length comes from the transport's [`PipScale`](/keys/pipscale/) and [`MaxPips`](/keys/maxpips/). Under `PipScale=Passengers` the row has five pips, or `MaxPips` where set, but never more than the transport's [`Passengers`](/keys/passengers/). Passengers past the end of the row get no pip.

:::caution[Spell the pip color exactly]
Omitting `Pip` keeps the color an earlier rules file set. A value that matches none of the [pip colors](/reference/enums/pip-color/) replaces that color with `green`, so a misspelling in a later file undoes an earlier assignment.
:::
