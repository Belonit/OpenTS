---
key: Side
scope: multiplayer-settings
label: Preferred multiplayer side
see_also: ["Handle", "Color"]
when_omitted:
  kind: context-dependent
  note: The first house in the rules until a side has been chosen this run; the already-chosen side afterwards.
---

The value is the country the player last chose for LAN and skirmish games. The game reads it when the player enters the multiplayer menu, and writes the current choice back when the player joins or starts a LAN game or leaves the LAN or skirmish dialog.

The value names a country by its section name or its display name, in any letter case. A number is a name too: `Side=2` looks for a country called `2`, not for the second country. The names `Spawn1` to `Spawn8` and `<Player @ A>` to `<Player @ H>` are ignored, and the previous choice stays.

The LAN and skirmish dialogs preselect this country in their side box. The box lists only [`Multiplay=yes`](/keys/multiplay/) countries, by name, so the choice follows the country wherever it sits in the rules.

:::caution[Name a country the side box lists]
Set `Side=` to a `Multiplay=yes` country. A name that matches no country, or a country the box does not list, leaves both side boxes on their first entry. Skirmish then uses that first entry once the player leaves the dialog. A LAN game keeps the unlisted value as the player's country until the player picks a side in the box.
:::
