---
key: Bouncer
summary: Throws the animation into the air on a random arc instead of playing it where it was created.
see_also: ["IsMeteor", "MaxXYVel", "MinZVel", "Elasticity", "ExpireAnim", "Spawns"]
when_omitted:
  kind: value
  value: "no"
---

The animation launches from 10 leptons above the point where it was created. Its two horizontal speeds are random within the [`MaxXYVel`](/keys/maxxyvel/#scope-animtype) range, and [`MinZVel`](/keys/minzvel/#scope-animtype) sets its upward speed. Gravity then reduces the vertical speed by 1.4 leptons every frame.

[`IsMeteor=yes`](/keys/ismeteor/#scope-animtype) also puts the animation in flight without this flag, but flies it in along a straight line with no gravity. When both are set, the animation flies as a meteor.

The flight ends at the first contact with the ground, a bridge deck, or a building or wall in the path. On that frame the animation is removed after it produces its landing effects:

- [`ExpireAnim`](/keys/expireanim/#scope-animtype), and with it a blast that deals [`Damage`](/keys/damage/#scope-animtype) through the animation's [`Warhead`](/keys/warhead/#scope-animtype)
- [`ExpireSound`](/keys/expiresound/#scope-animtype)
- [`Spawns`](/keys/spawns/#scope-animtype)
- [`IsTiberium`](/keys/istiberium/#scope-animtype)

On water, a wake and a splash replace the expiry animation and its blast, and the expiry sound, `Spawns` and `IsTiberium` are skipped. A landing on a bridge deck over water counts as a landing on land, except that `IsTiberium` spreads nothing from a landing on any bridge deck.

[`Elasticity`](/keys/elasticity/#scope-animtype) decides whether the contact also counts as a strike. A strike plays [`BounceAnim`](/keys/bounceanim/#scope-animtype) and [`BounceSound`](/keys/bouncesound/#scope-animtype) and deals the [`DamageRadius`](/keys/damageradius/#scope-animtype) damage.

A thrown animation differs from an ordinary one in two more ways:

- It deals none of the per-frame [`Damage`](/keys/damage/#scope-animtype) an ordinary animation deals to its surroundings.
- It leaves a [`Crater`](/keys/crater/#scope-animtype) or [`Scorch`](/keys/scorch/) mark only when its largest frame is its first. The mark is made when the animation starts, at the launch point.

```ini title="art.ini"
[MYDEBRIS]         ; a chunk thrown off a destroyed vehicle
Bouncer=yes
MaxXYVel=30.0      ; up to 30 leptons a frame sideways
MinZVel=20.0       ; at least 20 leptons a frame upward
LoopCount=-1       ; loop until the chunk lands
ExpireAnim=TWLT026 ; the stock small impact flash
```

:::caution[A thrown animation still runs out of frames]
The animation keeps playing its frames during the flight. If it reaches its last frame before it lands, it is removed in mid-air with none of its landing effects, unless [`Next`](/keys/next/) names an animation to turn into. Set [`LoopCount=-1`](/keys/loopcount/) so that it loops until it lands. Every bouncing animation in the shipped `art.ini` does.
:::
