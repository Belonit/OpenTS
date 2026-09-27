---
key: DetailLevel
scope: client-settings
label: Chosen detail level
see_also: [TranslucencyDetailLevel, GameSpeed]
when_omitted:
  kind: value
  value: "2"
---

The player's graphics detail level, from `0` for low to `2` for high. A value outside that range is read as the nearer end. The Game Controls dialog offers the three levels and saves the choice to `sun.ini` when the player closes the dialog with any button except Cancel.

Each level changes specific drawing work:

| Effect | `0` | `1` | `2` |
| --- | --- | --- | --- |
| Smoke and spark particles | Not drawn | Drawn | Drawn |
| Laser beams | Flat lines in their full color | Blended onto the terrain | Blended onto the terrain |
| Cell lighting | Coarsest steps | Finer steps | Finest steps |
| Glow wave along a laser beam | Not drawn | Not drawn | Drawn |
| Ion cannon blast effect | Not drawn | Not drawn | Drawn |
| Particle translucency | Opaque | Opaque | Translucent |
| Spotlight from a `Spark` particle system's burst | Not drawn | Not drawn | Drawn |

Cell lighting is quantized at every level, including `2`. A [`OneFrameLight`](/keys/oneframelight/) glow is drawn at every level.

An animation is drawn only when this setting is at least the animation's own threshold, which [`DetailLevel`](/keys/detaillevel/#scope-animtype) on the animation sets. The picture remembered under the fog of war uses the same test.
