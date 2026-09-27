---
key: IsVeins
scope: overlaytype
label: Vein ground
see_also: ["system:veins", "IsVeinholeMonster"]
when_omitted:
  kind: value
  value: "no"
---

`IsVeins=yes` makes the overlay count as vein ground where [vein growth checks for overlays](/systems/veins/#what-stops-veins). A vein field can grow into a cell holding such an overlay, and the vein replaces the overlay when that cell matures. The overlay also does not block veins from growing into the cells beside it.

The key has three other effects:

- A thin vein next to the overlay draws its connecting piece as though the overlay were mature vein.
- A mature vein growing beside the overlay does not put thin vein on its cell.
- When a veinhole monster is removed, overlays with the key are cleared from its five-by-five block along with its veins.

The key does not make an overlay behave as veins. Growing, harvesting, withering and vein attacks use only the vein overlay at its fixed position in `[OverlayTypes]`, and the key does not change how an overlay is drawn.
