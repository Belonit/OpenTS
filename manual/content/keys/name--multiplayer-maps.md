---
key: Name
scope: multiplayer-maps
label: Multiplayer map title
see_also: ["Official"]
when_omitted:
  kind: value
  value: "No Name"
  note: "Shown only when no earlier .mpr file sets a title. The .mpr files are read in alphabetical order of file name, and a file without Name= takes the title of the nearest earlier file that has one."
---

`[Basic] Name=` is the map's title in the skirmish and multiplayer map list. It applies to loose `.mpr` files, the ones found on their own in the folders the game searches (see [Game data](/using/game-data/)). A map listed in a `.pkt` packet takes its title from the packet's [`Description`](/keys/description/#scope-map-packets) instead and never reads this setting.

A non-empty [`Description`](/keys/description/#scope-multiplayer-maps) in the same file's `[Multiplay]` section replaces the title. The list keeps at most 43 bytes of either one; an accented letter takes two.

In a network game the host sends the selected map's title to the guests with the rest of the game options. A guest whose own map list has a file of the same name shows its own copy's title instead. The host's text appears only on a guest that does not have the file.

:::caution[Keep commas out of the title]
The game options travel as a comma-separated list, and the title is written into it as it stands. A comma in the title makes each guest misread the fields after it, including the map's file name, so the guest looks for the wrong map.
:::
