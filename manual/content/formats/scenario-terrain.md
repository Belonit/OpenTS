---
format_id: scenario-terrain
title: Scenario terrain data
summary: Stores a scenario's terrain cells in the Base64-encoded IsoMapPack sections.
kind: file
filenames:
  - "*.MAP"
  - "*.MPR"
source_files:
  - code/display.cpp
  - code/map.cpp
  - code/ini.cpp
  - code/lcwpipe.cpp
  - code/lcwstraw.cpp
  - code/lzopipe.cpp
  - code/lzostraw.cpp
  - code/overlay.cpp
  - code/session.cpp
related:
  - type: format
    id: ini-syntax
---

Scenario map files are INI files, but their terrain cells are stored as binary data. The data is Base64-encoded and split across the assignments of an IsoMapPack section. Each revision of the format has its own section, from `[IsoMapPack]` to `[IsoMapPack5]`.

The loader decodes the assignment values in section order and ignores their keys. Keep each value to 127 characters or fewer. A longer value is cut short, which corrupts the data.

The loader reads all five sections in revision order and applies every one that is present, so a later revision can overwrite cells that an earlier one set. A missing section changes nothing.

A damaged `[IsoMapPack4]` or `[IsoMapPack5]` section stops the load. The game shows an error message, and the debug log names the section. A map loaded after this failure still uses its own theater's resources. Damage in an older revision does not stop the load.

## Revisions

| Section | Compression | Cell data |
| --- | --- | --- |
| `[IsoMapPack]` | LCW | Tile type, sub-tile and height for the original 128 by 128 cell grid |
| `[IsoMapPack2]` | LCW | Cell records, ending with a 0,0 coordinate |
| `[IsoMapPack3]` | None | Cell records, ending with a 0,0 coordinate |
| `[IsoMapPack4]` | LZO | Cell records, ending with a 0,0 coordinate |
| `[IsoMapPack5]` | LZO | Cell records with the cell's ice-growth flag, ending with a 0,0 coordinate |

`[IsoMapPack]` stores no coordinates. It holds three runs of 16,384 entries, one entry per cell of the 128 by 128 grid, in rows of increasing Y with X increasing within each row. The first run holds every cell's tile type in 2 bytes, the second every sub-tile in 1 byte, and the third every height in 1 byte.

The later revisions store a list of cell records, only for the cells they set. Each record holds these fields, in order, with multi-byte values little-endian:

| Field | Size |
| --- | --- |
| X coordinate | 2 bytes |
| Y coordinate | 2 bytes |
| Tile type | 4 bytes |
| Sub-tile | 1 byte |
| Height | 1 byte, signed |
| Ice-growth flag | 1 byte, `[IsoMapPack5]` only |

The list ends with an X and Y of 0 and no further fields, so cell 0,0 cannot have a record. A record for a cell outside the map is skipped.

Section size limits count decoded bytes: a section's bytes after Base64 decoding and before decompression. `[IsoMapPack5]` accepts up to 5,784,964 decoded bytes, enough for a record for every cell of the 512 by 512 grid written in 8 KiB blocks. A larger section is damaged. The other four sections are read up to 512,000 decoded bytes, and anything past that is dropped. An `[IsoMapPack4]` section cut before its terminator this way is damaged.

`[IsoMapPack4]` and `[IsoMapPack5]` compress the record list with LZO in blocks. Each block starts with two 16-bit counts, the compressed size and then the uncompressed size, followed by the compressed bytes. Write blocks of at most 8 KiB of records. The size limit above assumes that block size, and a block that expands past 16 KiB is damaged.

An LZO section is damaged when any of these holds:

- A block does not decompress, or expands to a size other than its header states.
- The section ends partway through a block header or a block's compressed bytes.
- The records end before the 0,0 terminator, even when every block present decompresses.

`[IsoMapPack]` and `[IsoMapPack2]` use LCW blocks with the same two-count header. Each block expands to at most 8 KiB and takes at most 10,308 compressed bytes. The read ends at a block that breaks either limit, has a count of zero, or runs out of bytes.

When an `[IsoMapPack]`, `[IsoMapPack2]` or `[IsoMapPack3]` read ends early, the load continues. Cells the read did not reach keep the terrain they had, except for these cells, which become clear ground:

- In `[IsoMapPack]`, every cell whose tile type was not reached.
- In `[IsoMapPack2]` or `[IsoMapPack3]`, a cell whose record was cut off between its coordinates and its tile type.

## Overlay packs

`[OverlayPack]` and `[OverlayDataPack]` store each cell's overlay type and overlay frame for the whole 512 by 512 cell grid. Each holds one byte per cell, in rows of increasing Y with X increasing within each row, compressed in LCW blocks and Base64-encoded as `[IsoMapPack]` is. In `[OverlayPack]`, `255` means no overlay.

The loader reads both sections only when [`NewINIFormat`](/keys/newiniformat/) is above 1, and ignores the bytes for cells outside the playfield. It reads `[OverlayPack]` up to 512,000 decoded bytes and `[OverlayDataPack]` up to 256,000, and drops anything past that.
