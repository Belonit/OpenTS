---
title: Developer-build troubleshooting
summary: Checks the supported toolchain, target architecture, output location, and local game-data tree.
category: troubleshooting
source_files:
  - docs/BUILDING.md
  - CMakeLists.txt
  - code/CMakeLists.txt
related:
  - type: using
    id: build-and-run
  - type: using
    id: game-data
---

## Configuration fails before compilation

A message that a `thirdparty/` directory such as `thirdparty/bgfx.cmake` is empty means the clone did not fetch the submodules. Run `git submodule update --init --recursive` and configure again.

Use the Visual Studio 2022 generator with `-A Win32` or `-A x64`. Other compilers, Visual Studio versions, and target architectures are unsupported. Configuration stops for MSVC older than 19.30 and for compilers other than MSVC, apart from the experimental clang-cl cross-build that `docs/BUILDING.md` describes.

A build directory holds one platform. Configuring the other platform over it fails, so give each platform its own directory.

If CMake cannot find a Visual Studio installation through the Visual Studio Installer, set `CMAKE_GENERATOR_INSTANCE` to its directory and product version, as the repository's `docs/BUILDING.md` describes.

## The executable is not in the run directory

Builds write their runnable files to `build/bin/<configuration>/` and copy nothing into `Run/`:

- Debug: `GameD.exe`, `GameD.pdb`, `GameD.map`, `Language.dll`, and the `ui/` directory
- Release: `Game.exe`, `Game.pdb`, `Game.map`, `Language.dll`, and the `ui/` directory

## The executable cannot initialize game data

Name the game data directory with [`-DATADIR=<path>`](/using/command-line/data-directory/). Point it at a legitimate Tiberian Sun installation or a copy of its data; the repository and the CMake build directory contain no game assets. A relative path is read from the directory that holds the executable.

If the named path does not exist or is not a directory, the game shows a message that the data directory cannot be used, and exits.
