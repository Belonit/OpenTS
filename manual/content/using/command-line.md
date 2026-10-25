---
title: Command line options
summary: Options given after the executable's name that change how the game starts, grouped by what they are for.
category: getting-started
source_files:
  - code/init.cpp
  - code/startup.cpp
related:
  - type: system
    id: developer-mode
  - type: using
    id: game-data
---

## Passing options

Put options after the executable's name, separated by spaces. Option names are not case-sensitive.

```text title="Command Prompt"
Game.exe -WIN -1280X720 -DATADIR="D:\Games\Tiberian Sun"
```

Write a value straight after its `=`, with no space. Quote a value that contains spaces; the game removes the quotes.

The single-letter `-X` options can share one `-X`: `-XCQ` is `-XC` and `-XQ` together.

The game ignores an option it does not recognize. An `-X` letter it does not accept is the exception: the game exits before starting, and a Debug build shows `Invalid option switch.` in its debug console first. A Release build does not accept the `-X` letters listed under [Debug build only](/using/command-line/#debug-build), and ignores the other options there.
