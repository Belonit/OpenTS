---
key: UseNormalLight
summary: Draws the animation at the neutral light level instead of at the light level where it stands.
see_also: ["ShouldUseCellDrawer", "AltPalette"]
when_omitted:
  kind: value
  value: "no"
---

With the flag set, the animation is drawn at the neutral light level, whatever the lighting where it stands. The neutral level is the brightness a cell has before anything darkens or brightens it. Set the flag for explosions, muzzle flashes and fire, which should stay bright in a dark cell or under an ion storm.

Without the flag, the animation takes the light level of its surroundings, so it dims and brightens with the ground in the dark, under an ion storm or beside a light source. Which light level it takes depends on the animation:

- An animation that a structure runs with [`ShouldUseCellDrawer=yes`](/keys/shouldusecelldrawer/) takes the structure's brightness.
- Tiberium debris, and a cell animation that an overlay starts on a tiberium cell, take the brightness of the tiberium cell they came from.
- The burning infantry animation named by [`FlamingInfantry`](/keys/flaminginfantry/) is always drawn at the neutral level.
- An animation that a terrain tile starts, and a vein attack animation, take the brightness that the ground tile in their cell is drawn at.
- Any other animation takes the brightness of the cell it is in.

The flag changes brightness only. The palette the animation is drawn with is set by [`ShouldUseCellDrawer`](/keys/shouldusecelldrawer/) and [`AltPalette`](/keys/altpalette/).

The copy of a structure's animation that the fog of war draws in its place also honors the flag; without it, the copy takes the brightness of its cell.

The shadow under a thrown animation is always drawn at the neutral level.
