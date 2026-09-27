---
key: Scatter
scope: mission-behavior
label: Mission allows scattering
see_also: [Paralyzed, Zombie, PlayerScatter]
when_omitted:
  kind: value
  value: "yes"
---

`Scatter=no` in a mission's section makes aircraft on that mission refuse every scatter request. Vehicles and infantry on the mission refuse only requests that are not forced. The mission that counts is the one the object is on when a scatter request reaches it. [`PlayerScatter`](/keys/playerscatter/) covers the separate decisions that lead to a request.

```ini title="rules.ini"
[Harvest]
Scatter=no
```

A soldier that is already walking treats every request as unforced, so it refuses a forced one too.

Most requests are forced, so for vehicles and infantry this setting stops few scatters. Forced requests include the player's [Scatter](/commands/scatterobject/) order, a team's scatter mission, passengers and survivors leaving a destroyed vehicle or structure, and every warning that a threat is heading for the object's cell.

One forced request still obeys this setting. An object that has just been damaged and is not allowed to fire back scatters only when its mission allows it, as [Scattering after damage](/systems/target-selection/#scattering-after-damage) describes.

A vehicle on the `Sleep`, `Sticky` or `Unload` mission never scatters, and neither does a vehicle whose type sets [`IsTrain=yes`](/keys/istrain/). This holds whatever the mission's `Scatter` value and whether or not the request is forced.
