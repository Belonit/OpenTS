---
key: IsMeteor
scope: animtype
label: Animation meteor flight
see_also: ["Bouncer", "MinZVel", "MaxXYVel", "CraterLevel", "IsTiberium", "Spawns"]
when_omitted:
  kind: value
  value: "no"
---

`IsMeteor=yes` flies the animation in along a straight line from a distance, aimed just below the point where it was created. Like [`Bouncer=yes`](/keys/bouncer/), it puts the animation under bounce physics, and where both are set this key decides the flight. A bouncing animation starts at its creation point and is thrown up from there. A meteor instead starts 51 to 70 frames of travel away and flies until it strikes the ground, a structure or a wall.

A meteor's velocity is chosen differently from a bouncing animation's:

- Each frame it drops 1.4 leptons more than [`MinZVel`](/keys/minzvel/#scope-animtype) sets, with no random part. This speed does not build up as it falls, so it flies in a straight line where a bouncing animation arcs.
- A negative `MinZVel` brings the meteor down onto its target from above. A zero or positive value starts it level with or below its target, so a meteor aimed at the ground strikes the ground on its first frame, at its starting point away from the target.
- Its two horizontal speeds are drawn from the [`MaxXYVel`](/keys/maxxyvel/#scope-animtype) range. If the resulting direction would point up the screen, both are reversed, so a meteor always travels down or across the screen and never comes in from below its target.

The starting point is placed as though the meteor dropped by `MinZVel` alone. The extra 1.4 leptons per frame take its path 71 to 98 leptons below the creation point by the end of its travel time. A meteor aimed at the ground therefore lands short of the creation point, on the side it came from. The slower it descends, the shorter it lands: with `MinZVel=-1` it lands before covering half its path.

When a meteor lands on ground, the terrain around the impact cell caves in as [`CraterLevel`](/keys/craterlevel/) sets. It makes no crater when it ends four height levels (416 leptons) or more above the ground, which is where a bridge deck sits.

When a meteor lands in water, it plays the last animation in the rules' [`SplashList`](/keys/splashlist/). Other thrown animations play a wake and the first splash instead.

:::caution[Keep the meteor animating until it lands]
A meteor keeps stepping through its frames while it flies. If it plays its last pass before it lands, it is removed in mid-air and never arrives. Set [`LoopCount=-1`](/keys/loopcount/) so it loops until it lands.
:::
