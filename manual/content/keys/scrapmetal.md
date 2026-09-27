---
key: ScrapMetal
summary: Whether wrecks leave the scrap animations their types name instead of their ordinary ones.
see_also: [ScrapExplosion, Explosion, "system:destruction-and-debris"]
when_omitted:
  kind: value
  value: "no"
  note: A campaign mission that omits the key plays with scrap wreckage off.
---

With scrap wreckage on, wherever a destroyed vehicle, aircraft or structure would play an animation from its type's [`Explosion`](/keys/explosion/) list, it plays one from its [`ScrapExplosion`](/keys/scrapexplosion/) list instead. A type with no `ScrapExplosion` animations keeps its `Explosion` animations, so a ruleset can give scrap animations to only some of its types.

Where the setting comes from depends on the kind of game:

- In a skirmish or a game against other machines, the [launch file's `ScrapMetal` option](/formats/spawn-ini/#the-options-every-house-plays-under) decides it, and scrap wreckage is off in a game started without one. The map's `ScrapMetal` entry is ignored.
- In a campaign mission, the map's `ScrapMetal` entry in `[SpecialFlags]` decides it. A [campaign mission started from a launch file](/formats/spawn-ini/#a-campaign-mission) does not take the option from the file.
- A saved game keeps the setting it was saved with.

The wreck animation is picked with the random numbers every machine in a match shares, so every machine in a game against other machines must use the same `ScrapMetal` option. A machine whose launch file disagrees goes out of step with the others.
