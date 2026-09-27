---
key: MinimumRange
summary: How close a target may come before the weapon refuses to fire at it, in cells.
see_also: ["Range", "ProjectileRange"]
when_omitted:
  kind: value
  value: "0"
---

The weapon refuses a target closer than this distance. The value is in cells, and a fraction is accepted. The distance runs from the firer's center to the target's center and includes the height difference. A firer in the air is measured as though it were at the target's height, so for it only the horizontal distance counts.

```ini title="rules.ini"
[MyArtillery] ; example WeaponType
Range=12
MinimumRange=4 ; nothing closer than four cells may be shot
```

A target refused this way counts as out of range. An object on the [`Sticky`](/reference/enums/mission/) mission drops the target. Any other object that can move looks for a cell to fire from, starting near its full [`Range=`](/keys/range/) and working inward. It takes the first cell that has the target within both limits, lies inside the playable map and is clear for it to enter. An object that moves on the ground also needs a walking route of reasonable length, either to that cell or from it to the target. A vehicle with a target inside its minimum range therefore backs off to a cell it can reach.

When no cell qualifies, the object gives up the target and moves to a free cell nearby. A hunter-seeker or a vehicle thief heads straight for the target instead.

The limit also applies to an [`Arcing=yes`](/keys/arcing/) projectile, which skips the `Range=` distance comparison. Unlike `Range=`, the value is compared as written, with no third of a cell taken off.

`0` turns the limit off, and so does any negative value except `-1`. `-1` counts as not set, so it keeps whatever an earlier rules file set.
