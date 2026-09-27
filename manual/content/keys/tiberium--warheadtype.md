---
key: Tiberium
scope: warheadtype
label: Sets Tiberium off
see_also: ["system:tiberium", "ChainReaction"]
when_omitted:
  kind: value
  value: "no"
---

An explosion from a `Tiberium=yes` warhead can set off the Tiberium in its cell when the cell's overlay is a [`ChainReaction=yes`](/keys/chainreaction/) Tiberium overlay. The same explosion also thins that cell's Tiberium. Explosions from other warheads leave such a cell alone. [Tiberium damage](/systems/tiberium/#damage) gives the detonation chance and the thinning.

A sonic wave passing over the cell can set the Tiberium off whatever its warhead.

The flag makes no difference to a `ChainReaction=yes` overlay that is not Tiberium; the [`ChainReaction`](/keys/chainreaction/) page covers that case.
