---
key: Explodes
scope: overlaytype
label: Explosive overlay
see_also: [BarrelExplode, BarrelDebris, BarrelParticle, AmmoCrateDamage, C4Warhead, ChainReaction]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYBARREL] ; an OverlayType registered in [OverlayTypes]
Explodes=yes
```

An explosion centered in the cell sets the overlay off when its damage is not zero or its warhead sets [`Webby=yes`](/keys/webby/). There is no armor test or chance roll. In an [`Inert=yes`](/keys/inert/) scenario, no explosion sets it off.

The overlay is removed at once. The cell's passability and movement zones are updated, and anything targeting the cell drops it as a target.

The overlay then explodes in the same cell, with these effects:

- the [`BarrelExplode`](/keys/barrelexplode/) animation plays;
- [`AmmoCrateDamage`](/keys/ammocratedamage/) is dealt as area damage through the [`C4Warhead`](/keys/c4warhead/), with no house responsible for it;
- one piece of [`BarrelDebris`](/keys/barreldebris/) may be thrown;
- a [`BarrelParticle`](/keys/barrelparticle/) particle system starts on a 25% chance.

For the debris, each `BarrelDebris` entry in list order gets a 15% chance, and the first entry that succeeds is thrown. At most one piece is thrown, and a later entry is tried only when every earlier one failed.

Explosive overlays in the four cells that share an edge with the exploding cell each get a `FIRE3` animation four to six frames later. Those neighbors do not explode directly. Each explodes only if its animation's [`Damage`](/keys/damage/#scope-animtype) sets it off. A destroyed [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) structure lays the same fire on explosive overlays in the four cells that share an edge with its origin cell.

`Explodes` is separate from [`ChainReaction=yes`](/keys/chainreaction/), which lets explosions detonate the Tiberium in a cell.

:::danger[Keep the `FIRE3` animation registered]
Keep an animation named `FIRE3` in `[Animations]`; the neighbor fire is looked up by that name each time. If no animation has that name, the game reads outside the animation list the first time the fire spreads, and it can crash.
:::
