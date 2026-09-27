---
key: IsMeteor
scope: voxelanimtype
label: Voxel meteor flight
see_also: ["MinZVel", "MaxZVel", "MaxXYVel", "Spawns", "SpawnCount", "CraterLevel", "Duration"]
when_omitted:
  kind: value
  value: "no"
---

A meteor flies in to the coordinate it is created for. Ordinary debris is thrown up from that coordinate instead.

When a meteor is created, its velocity is drawn and its lifetime is shortened by a random 0 to 19 frames. The meteor then starts as far back from its target as that velocity would carry it over the shortened lifetime. [`Duration`](/keys/duration/) therefore sets the length of the approach.

A meteor's velocity differs from ordinary debris in three ways:

- Its vertical speed is [`MinZVel`](/keys/minzvel/#scope-voxelanimtype) minus a fixed 1.4 leptons per frame for gravity. [`MaxZVel`](/keys/maxzvel/) is ignored. With `MinZVel=-10`, for example, the meteor falls 11.4 leptons per frame.
- Its two horizontal speeds are drawn from the [`MaxXYVel`](/keys/maxxyvel/#scope-voxelanimtype) range, then both are reversed if the result would carry the meteor up the screen. Its horizontal motion therefore always runs down or across the screen.
- Its vertical speed stays the same until it strikes something, so it flies in a straight line where other debris arcs.

The starting point leaves out the 1.4 leptons per frame for gravity. A meteor falling onto level ground therefore lands before its lifetime runs out and short of its target. With `MinZVel=-10`, it lands after about 88 percent of its shortened lifetime, 88 percent of the way to its target. It then rebounds as [`Elasticity`](/keys/elasticity/#scope-voxelanimtype) describes, and its lifetime ends wherever the rebound has carried it.

A `MinZVel` of 0 or above starts the meteor at or below the height of its target. A meteor aimed at level ground with such a setting starts under the surface and strikes it on its first frame.

When a meteor's life ends anywhere except low over water, it has two effects that ordinary debris never has:

- [`Spawns`](/keys/spawns/#scope-voxelanimtype) breaks it into new pieces of debris.
- The terrain around the impact cell is deformed according to [`CraterLevel`](/keys/craterlevel/), unless the meteor ends at bridge-deck height or above.

Low over water, as [`ExpireAnim`](/keys/expireanim/#scope-voxelanimtype) defines it, a meteor plays the last animation in [`SplashList`](/keys/splashlist/) in place of the wake and splash other debris makes.
