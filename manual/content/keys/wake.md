---
key: Wake
summary: The ripple laid on the water by something moving across it, falling into it or sinking through it.
see_also: [SplashList, IceBreakingWeight, Locomotor]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
Wake=MYWAKE ; an AnimType registered in [Animations]
```

The animation plays in three situations.

**Movement.** An object whose [`Locomotor`](/keys/locomotor/) is Drive, Hover or Levitate lays one at its position every tenth frame while it moves over open water and is not on a bridge. With the key unset, it leaves no trail.

**Splashes.** Some of the splashes that [`SplashList`](/keys/splashlist/) plays also lay a wake beside them. That page lists which ones.

**Ice giving way.** When ice breaks open into water, each object lost with it gets one. A vehicle that is not amphibious starts to sink, and an infantryman or aircraft is removed. An amphibious vehicle stays up and gets none. The exception is the vehicle whose weight broke the ice: it sinks even when it is amphibious, and then it gets no wake. [`IceBreakingWeight`](/keys/icebreakingweight/) and [`Fire`](/keys/fire/) cover what breaks ice.

:::danger[Set Wake in any mod with water or breakable ice]
Only the movement trail checks that the key is set. With `Wake` unset, the game crashes the first time a splash or breaking ice lays one.
:::
