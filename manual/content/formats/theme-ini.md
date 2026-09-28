---
format_id: theme-ini
title: THEME.INI
summary: Registers music track IDs and each track's playlist settings.
kind: file
filenames:
  - THEME.INI
  - THEME01.INI
key_scopes:
  - file: theme01.ini
    section:
      kind: identifier
      source: theme
related:
  - { type: format, id: aud }
  - { type: format, id: opents-ini }
source_files:
  - code/init.cpp
  - code/theme.cpp
  - code/themeini.cpp
---

The game reads `THEME.INI` and `THEME01.INI` once at startup and builds the track list from them. Whether Firestorm is installed does not matter: each file that is present is read, and either one alone is enough. When neither can be read, the game shows an initialization error and closes. [OPENTS.INI](/formats/opents-ini/#the-files-it-reads) can change both file names.

`[Themes]` values register track IDs. Each ID names the track's section and, unless the section sets [`Sound=`](/keys/sound/), the base name of its music file. The text to the left of the `=` is only a label, and the list keeps the order the entries are read in. An ID listed twice appears once, at its first position. [Music](/systems/music/) explains how that order and each track's settings decide what plays.

```ini title="THEME.INI"
[Themes]
0=MYTHEME

[MYTHEME]
Name=Example theme
Length=3.27
Normal=yes
```

The two files are combined as if they were one file, with `THEME01.INI` read second. A key that both files set, in the same section, takes the value from `THEME01.INI`. A track section present in both files takes each key from `THEME01.INI` when that file sets it, and from `THEME.INI` otherwise.

Give the `[Themes]` entries in `THEME01.INI` labels that `THEME.INI` does not use. A reused label replaces the `THEME.INI` entry with that label. The new ID is placed among the `THEME01.INI` entries in the order that file lists them, and the replaced ID is no longer a track unless another label lists it.
