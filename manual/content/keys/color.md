---
key: Color
summary: Color scheme for a projectile, house, or Tiberium type; the multiplayer setting holds the index of the player's preferred color.
---

This page covers five `Color=` settings. Four take a color scheme name and one takes a number, so the file you are writing decides what a valid value looks like.

The four scheme names, each written in the section of the type or house it colors:

- [Voxel projectile remap](/keys/color/#scope-bullettype): a projectile's section in the rules. It colors the projectile's voxel model in flight.
- [Country color](/keys/color/#scope-housetype): a country's section in the rules. It is the color every house of that country starts with.
- [Scenario house color](/keys/color/#scope-house-per-scenario): a house record in a campaign map. It recolors that one house for that one mission.
- [Tiberium remap](/keys/color/#scope-tiberium): a Tiberium type's section in the rules. It colors the Tiberium overlay and the animations it creates.

Each name is looked up, in any letter case, among the schemes the rules declare in `[Colors]`. Each entry there names a color scheme and gives the hue, saturation and value its colors are built from.

The number is the [preferred multiplayer color](/keys/color/#scope-multiplayer-settings). It lives in `[MultiPlayer]` of the player's settings file, `SUN.INI`, and is a position in the lobby's eight-color list, not a name the rules know.

A spawned game reads one more `Color=`, in each person's section of the [spawn file](/formats/spawn-ini/#who-is-playing). It gives the lobby color that person plays.
