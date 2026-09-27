---
title: Settle a repeated INI section or key instead of stopping on it
category: fix
release: 0.2.0
targets:
- type: format
  id: ini-syntax
  effect: changed
credit: [ZivDero]
---

A section that appears twice in one file is now read as one section, with the keys of both blocks. The two blocks used to be kept as separate copies, and the keys of one of them could not be read. The stock `nod10a` mission contains `[HMEC]` twice and lost one of its two keys.

A key assigned twice in one section now takes the later value and moves to the end of its section, as a key overridden by a later file already did. In a numbered list such as `[VehicleTypes]`, only one copy of the entry now remains, so the entries that followed its first appearance each move up by one.

A Debug build used to stop on an assertion at either kind of repeat. It now continues, and a repeat within one file is written to the debug log with the file and section, and the key for a repeated key.
