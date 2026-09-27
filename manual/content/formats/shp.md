---
format_id: shp
title: SHP images
summary: Stores indexed two-dimensional image frames used by sprites and interface graphics.
kind: binary
extensions:
  - .SHP
role: image
source_files:
  - code/shapeset.h
  - code/objtype.cpp
  - code/builtype.cpp
---

An SHP file holds a set of image frames drawn within one shared box, its logical width and height. The file starts with an 8-byte header, followed by a 24-byte record for each frame and then the frames' pixel data. Numbers are stored low byte first.

The header holds the logical width at byte 2, the logical height at byte 4 and the frame count at byte 6, each in 2 bytes. Each frame record holds:

| Offset | Bytes | Holds |
| --- | --- | --- |
| 0 | 2 | The frame's horizontal offset inside the logical box |
| 2 | 2 | The frame's vertical offset inside the logical box |
| 4 | 2 | The frame's width |
| 6 | 2 | The frame's height |
| 8 | 2 | Flags: `1` if the frame has transparent pixels, `2` if its pixels are run-length encoded |
| 12 | 3 | One color for the whole frame, as red, green and blue bytes |
| 20 | 4 | Where the frame's pixel data starts, counted from the start of the file, or `0` for a frame with no pixels |

The radar map colors overlays, Tiberium and terrain objects such as trees with these stored colors. For the overlays at `[OverlayTypes]` positions 127 to 138 and 147 to 158, counting from 0, the radar swaps the green and blue bytes. The shipped rules put `TIB2_01` to `TIB2_12` and `TIB3_01` to `TIB3_12` at those positions.

Cursors, interface graphics, animations and object art that is not a voxel model are SHP files. Cursors and interface graphics load under fixed file names. Most object art loads from `<Image ID>.SHP`, using the type's [Image ID](/keys/image/). A structure's main shape can take a different file name from `Image=` in [its art section](/keys/image/#scope-buildingtype). The art settings [`Theater`](/keys/theater/) and [`NewTheater`](/keys/newtheater/) change the file name to one for the scenario's theater, and their pages say which types each one applies to.

Object art that is not [demand-loaded](/keys/demandload/) is read only from cached archives. [Caching](/formats/mix/#caching) lists which archives are cached and how to replace a file in one. A type whose art file is not found has no image.
