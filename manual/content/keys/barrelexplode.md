---
key: BarrelExplode
summary: The explosion animation played where an exploding overlay is set off.
see_also: [AmmoCrateDamage, BarrelDebris, BarrelParticle, Explodes]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
BarrelExplode=MYBARRELBOOM ; an AnimType registered in [Animations]
```

Every [`Explodes=yes`](/keys/explodes/#scope-overlaytype) overlay plays this animation when it is set off. An overlay type cannot name its own. The animation plays where the triggering explosion landed, which need not be the center of the overlay's cell, and it is created before the blast deals its damage.

The fires that spread to neighboring explosive overlays use the `FIRE3` animation, not this one. [`AmmoCrateDamage`](/keys/ammocratedamage/) covers the damage.

:::danger[Set an animation before any overlay explodes]
If `BarrelExplode` names no animation, the game crashes the first time an [`Explodes=yes`](/keys/explodes/#scope-overlaytype) overlay is set off.
:::
