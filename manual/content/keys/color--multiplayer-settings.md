---
key: Color
scope: multiplayer-settings
label: Preferred multiplayer color
see_also: ["Handle", "Side"]
when_omitted:
  kind: value
  value: "0"
---

The value is a position in the lobby's eight-color list, counted from `0`: gold, red, blue, green, orange, sky blue, purple, pink. It preselects the color box in the skirmish and network game dialogs. The color picked there is written back to `[MultiPlayer]` in `SUN.INI` when you leave the dialog.

In a network game, the host can move a player to another color, for example when the chosen one is already taken. The player then sees a color-in-use message, and the new color becomes the saved preference.

Each position picks an entry of the rules' [`[Colors]`](/keys/color/) section by its place in that section, not by name. The table counts the entries from 1 and gives the name the stock rules have at that place.

| Position | Lobby color | `[Colors]` entry | Stock name |
| --- | --- | --- | --- |
| `0` | gold | 2nd | `Gold` |
| `1` | red | 11th | `DarkRed` |
| `2` | blue | 24th | `DarkBlue` |
| `3` | green | 37th | `DarkGreen` |
| `4` | orange | 14th | `Orange` |
| `5` | sky blue | 28th | `DarkSky` |
| `6` | purple | 20th | `Purple` |
| `7` | pink | 17th | `Magenta` |

Reordering `[Colors]` therefore changes the color each lobby position gives. Keep at least 37 entries in `[Colors]`, or the green position names an entry that does not exist.

A value outside `0` to `7` shows gold in the color box. In skirmish, gold is used and saved. In a network game, pick a color in the lobby; otherwise the out-of-range value is kept, and the house does not get one of the eight lobby colors.
