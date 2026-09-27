---
key: Name
scope: aitriggertype
label: Type display name
see_also: [Multiplay, SidebarCameoText]
when_omitted:
  kind: value
  value: "the type's section name"
---

`Name=` sets the name players see for a type. The section name stays the type's ID. The value is shown as plain text, not looked up as a translatable string, and is cut off after 48 bytes; an accented letter takes two.

```ini title="rules.ini"
[GAPOWR]
Name=GDI Power Plant
```

Players see the display name in several places, including these:

- The sidebar. It is the caption across a cameo. With captions turned off by [`SidebarCameoText`](/keys/sidebarcameotext/), it appears in the cameo's tooltip beside the price instead. A superweapon's tooltip is its display name either way.
- The tooltip for the infantry, vehicle, aircraft or structure under the cursor. An enemy object shows a generic label instead unless its type is [`Nominal`](/keys/nominal/).
- The country box on the skirmish and multiplayer setup screens, which lists each country marked [`Multiplay`](/keys/multiplay/) by its display name.
- The tooltip over a tree or other terrain object that stands on a Tiberium cell. It shows the display name of that Tiberium type.
- The dropship loadout screen, shown before a mission that starts with dropships. It shows a unit's display name and the display name of its primary weapon.
- The hint on a player's row in the network lobby, when that player's country belongs to a side other than GDI or Nod. The hint is the country's display name.

A setting that names a country accepts either the country's section name or its display name. The shipped `rules.ini` gives `[Neutral]` the display name `Civilian`, so a house list that names `Civilian` finds that country. The lookup stops at the first country in the list that matches either name, so keep each display name different from every other country's section name.

Team types are matched the same way when an AI trigger or a trigger event names a team: either its section name or its display name finds it.

A display name cannot be cleared. `Name=` with nothing after the `=` is dropped when the file is read, so it counts as leaving the line out.
