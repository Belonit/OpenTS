---
title: Build and run
summary: Builds the Debug or Release executable for either platform and runs it against a directory of game data.
category: getting-started
source_files:
  - docs/BUILDING.md
  - CMakeLists.txt
  - code/CMakeLists.txt
  - code/language/CMakeLists.txt
related:
  - type: using
    id: game-data
  - type: using
    id: developer-build-troubleshooting
---

Install Visual Studio 2022 with the **Desktop development with C++** workload, a Windows SDK, CMake 3.23 or newer, and Git for Windows. The repository's `docs/BUILDING.md` covers toolchain details and options.

The renderer, the audio layer, and the interface toolkits are Git submodules. Fetch them before the first configure; configuration stops with instructions if one is missing.

```powershell title="PowerShell"
git submodule update --init --recursive
cmake -S . -B build -G "Visual Studio 17 2022" -A Win32
cmake --build build --config Debug
```

The Debug build writes `GameD.exe`, its symbol file, its map file, and the matching `Language.dll` to `build/bin/Debug/`. It also copies the repository's `ui/` directory of interface documents, styles, and font beside them. Use `--config Release` to write `Game.exe` to `build/bin/Release/` instead. Each configuration has its own output folder, and the build copies nothing outside the build directory.

`-A x64` builds the 64-bit executable. A build directory holds one platform, so give the 64-bit build its own directory, such as `-B build/x64`. Keep saved games with the platform that wrote them, and play network games with every player on the same platform; [Compatibility and save games](/using/compatibility-and-saves/) explains why.

Put the required game data in `Run/`, then launch the built executable and name that data directory:

```powershell title="PowerShell"
.\build\bin\Debug\GameD.exe -DATADIR="$PWD\Run"
```

A relative `-DATADIR` path is read from the directory holding the executable, not from the directory the command runs in. The game switches to the executable's directory before it reads the command line.

The game reads its strings from the `Language.dll` beside the executable. The freshly built copy is the one that runs, and a localized or edited `Language.dll` in the game data directory is not read.
