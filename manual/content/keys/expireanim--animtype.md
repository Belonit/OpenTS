---
key: ExpireAnim
scope: animtype
label: Animation impact effect
see_also: ["Damage", "Warhead", "ExpireSound", "Bouncer"]
when_omitted:
  kind: value
  value: none
---

The animation that plays where a thrown animation ends, unless it ends low over water. A thrown animation is one with [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype).

An end is low over water when the cell is water and the thrown animation is less than 416 leptons above the ground there, the height of a bridge deck. Such an end makes a wake and a small splash instead, and this setting is not used. A meteor makes the last splash in the rules' [`SplashList`](/keys/splashlist/) in place of both. An end on solid ground, on a bridge deck, or higher up plays this animation.

A thrown animation ends at its first contact with a surface, as [`Elasticity`](/keys/elasticity/#scope-animtype) describes. When that contact counts as a strike, this animation and the [`BounceAnim`](/keys/bounceanim/#scope-animtype) appear on the same frame. This animation appears at the contact point, and the `BounceAnim` appears where the thrown animation was one frame before the contact.

:::caution[Blast damage needs an impact animation]
The [`Damage`](/keys/damage/#scope-animtype) blast, with its [`Warhead`](/keys/warhead/#scope-animtype) and the flash of light a bright warhead brings, is dealt only when this key names an animation. Without one, the thrown animation deals no blast damage when it ends. The damage dealt on a strike within [`DamageRadius`](/keys/damageradius/#scope-animtype) does not depend on this key.
:::

A misspelled name is not refused. It creates a new, empty animation type of that name, with no artwork unless a shape file of that name exists. Because an animation is then named, the blast damage still happens.
