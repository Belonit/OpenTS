---
key: AARate
summary: The servicing delay an armed building on this mission waits between passes.
see_also: [Rate, SAM, HasStupidGuardMode]
when_omitted:
  kind: inherited
  note: The mission's own Rate=, taken from the same section.
---

`AARate=` sets how long a structure with a primary weapon waits between passes of its Guard or Area Guard mission. On each pass it looks for a target and switches to attacking when it finds one. An [`EMPulseCannon=yes`](/keys/empulsecannon/) structure, or one that holds a chemical missile superweapon, skips the search but still waits this long.

The value uses the same units as [`Rate`](/keys/rate/#scope-mission-behavior): a fraction of a minute, multiplied by 900 and rounded down to whole game frames. The structure adds a random 0 to 2 frames to each wait. `[Guard]` and `[Area Guard]` each read their own `AARate=`.

```ini title="rules.ini"
[Guard]
Rate=.030
AARate=.016  ; an armed structure looks for a target every 14 to 16 frames
```

Despite the name, the delay is not tied to aircraft. It applies to every armed structure on guard, whatever its weapon can hit. A [`SAM=yes`](/keys/sam/) structure uses it on guard too, but once it is attacking, it tracks and fires every frame and does not normally wait for `AARate`.

`AARate` never sets the delay for a structure without a primary weapon. With [`HasStupidGuardMode=yes`](/keys/hasstupidguardmode/), the default, such a structure on guard checks again every 100 frames. With `HasStupidGuardMode=no`, it waits three times the mission's `Rate`, or `Rate` itself for a [`UnitRepair=yes`](/keys/unitrepair/) structure.

Other structure missions that repeat, such as Repair, Unload and Open, wait for their mission's `Rate`.

:::caution[Zero and very small values]
`AARate=0` takes the mission's `Rate`, as though the key were missing. If `Rate=` is also `0`, the delay is zero. Any delay below about `.0011`, whether set by `AARate=` or taken from `Rate=`, also gives zero, because it rounds down to zero frames. In both cases the structure looks for a target again after only the random 0 to 2 frames.
:::

:::caution[Repeat AARate in every file that sets the mission]
A rules file read after `rules.ini`, such as a map, resets `AARate` whenever it contains the mission's section without `AARate=`. The mission's `AARate` then equals its `Rate` again, and a separate value set in `rules.ini` is lost. Give `AARate=` again in any later file that includes `[Guard]` or `[Area Guard]`.
:::
