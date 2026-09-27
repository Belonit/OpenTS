---
key: Disguised
summary: Hides the soldier behind another type's name, artwork and color, and keeps automatic fire off it.
see_also: [Disguise, DetectDisguise, AIDetectDisguise, "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

Every soldier of a `Disguised=yes` type is disguised for its whole life. The disguise belongs to the type, so nothing can add it to one soldier or take it away.

## What other players see

A disguised soldier shows the name and artwork of the InfantryType that [`Disguise`](/keys/disguise/) names in `[General]`. That key's page gives the ownership test for each.

The soldier is also drawn in the local player's color whenever the local player does not own it. On the radar it is always plotted in the local player's color, whoever owns it.

## Automatic targeting

[Target selection](/systems/target-selection/#why-a-candidate-is-rejected) rejects a disguised soldier as a candidate, whichever house the scanning object belongs to. It is still considered when **any of** these holds:

- the scanning object's type sets [`DetectDisguise=yes`](/keys/detectdisguise/);
- the scanning object belongs to a computer house and [`AIDetectDisguise=yes`](/keys/aidetectdisguise/) is set.

Only the automatic scan is affected. A player's attack order, retaliation against a shot the soldier fired, and area damage all still reach it.

## Movement around it

Two more effects ignore the detection settings:

- A computer-owned vehicle outside a team that is shot by a disguised soldier never tries to run it over in reply.
- An armed infantry routing past a disguised soldier it is not allied with treats that soldier's cell as temporarily blocked. An enemy soldier without a disguise does not block the cell this way.
