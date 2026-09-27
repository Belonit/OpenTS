---
key: ColorList
summary: The colors a spark or railgun particle blends through as it ages.
see_also: ["ColorSpeed", "StartColor1", "StartColor2", "BehavesLike"]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYSPARK] ; a ParticleType registered in [Particles]
BehavesLike=Spark
MaxEC=500
XVelocity=10
YVelocity=10
ZVelocityRange=15
ColorList=(255,255,255),(200,200,80),(200,10,10),(0,0,0)
ColorSpeed=.13
```

Only [`Spark` and `Railgun`](/keys/behaveslike/#scope-particletype) particles use the list, because they are drawn as a single colored pixel. Particles of other behaviors are drawn from artwork and ignore it.

The particle's color changes through the list in order:

1. It starts at the first entry. If [`StartColor1`](/keys/startcolor1/) or [`StartColor2`](/keys/startcolor2/) is set to anything but black, it starts instead at a random blend of those two colors.
2. It fades from its starting color to the second entry, then from each entry to the next, at the rate [`ColorSpeed`](/keys/colorspeed/) sets.
3. When it reaches the last entry, it keeps that color for the rest of its life.

Write each color as a red, green and blue triplet in parentheses, with commas between the triplets. The components are counted in threes from the start of the line, whatever the parentheses say, so a triplet with a missing component shifts every color after it. An incomplete triplet at the end is dropped. Each component is stored in one byte, so `256` reads as `0` and `300` as `44`.

:::caution[Leave no space before an opening parenthesis]
A space before `(` makes that color's red component read as `0`. `ColorList=(255,255,255), (255,0,0)` gives a second color of black instead of red. Write `ColorList=(255,255,255),(255,0,0)` instead.
:::

:::danger[Give a spark or railgun particle at least two colors]
With an empty list, the game crashes the first time a particle of the type is drawn on screen. With a single entry, the particle fades toward black in a new game. After a saved game is loaded, it reads its second color from outside the list and can be drawn in any color.
:::

:::danger[Repeat the list in every rules file that opens the section]
Most particle settings keep their earlier value when a later file opens the section without them. This list does not: a section without `ColorList` empties it. A map's rules or an expansion rules file that opens the particle's section to change another setting therefore discards the colors, and the next particle of that type drawn on screen crashes the game.
:::
