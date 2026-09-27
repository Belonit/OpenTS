---
key: LightIntensity
summary: The brightness of the glow a structure casts over the ground around it.
see_also: [LightVisibility, LightRedTint, LightGreenTint, LightBlueTint, HasSpotlight, "system:power"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[GALITE] ; the stock light post
LightVisibility=5000
LightIntensity=0.2
LightRedTint=0.05
LightGreenTint=0.05
LightBlueTint=0.01
```

The value is how much light the structure adds to the cells around it, as a fraction of full daylight. At the structure's center, `LightIntensity=1` adds as much light as a map at [`Ambient=1`](/keys/ambient/) already has. The added light falls off in a straight line to nothing at [`LightVisibility`](/keys/lightvisibility/).

The glow is added to the map's ambient light, not scaled by it, so a structure adds the same amount of light on a dark map as on a bright one. A negative value darkens the cells instead, as the stock negative light post does.

A value of `0` gives the structure no light at all, and its radius and tints then have no effect.

The light comes on when the structure is placed or finishes building. It goes out while the structure is switched off or stunned by an [EM pulse](/systems/emp-pulse/), and for good when the structure is destroyed, sold or undeployed. A power shortage in its house does not dim it. The glow is unrelated to the swept beam that [`HasSpotlight`](/keys/hasspotlight/) covers.

A later rules file can wipe out a fractional value. If any later rules file, such as the expansion's rules or a map's own rules, contains the structure's section but not this key, the stored value loses its fraction. A `0.2` light therefore goes out entirely when a map names the section for any other reason, and a `1.5` light drops to `1`. The three tints lose their fractions the same way.

:::caution[Set the tints whenever you set the intensity]
Give a structure with a light all three tint keys. Each tint left unset stays at its built-in `1000`, far above the stock values, which lie between `-1.5` and `2`. If all three are left unset, the light adds no color, because the tints are balanced against each other as [`LightRedTint`](/keys/lightredtint/) describes. If only some are left unset, those channels swamp the others and the light casts their color. A tint that large also overflows the ground's brightness calculation, so the ground's brightness jumps erratically from cell to cell inside the radius instead of forming an even glow.
:::
