---
key: Color
scope: tiberium
label: Tiberium remap
see_also: ["system:tiberium", "Debris"]
when_omitted:
  kind: value
  value: "0"
  note: The scheme of the first entry in `[Colors]`.
---

The value names a color scheme declared in the rules' `[Colors]` section, in any letter case. A name that `[Colors]` does not declare leaves the type on the scheme it already had.

The scheme recolors three things:

- the type's overlays on the battlefield, though not on the radar minimap;
- the [`CellAnim`](/keys/cellanim/) animation a Tiberium overlay of this type starts when it is placed;
- the [`Debris`](/keys/debris/) animation left when a [`TiberiumChainReaction=yes`](/keys/tiberiumchainreaction/) animation clears a cell of this type.
