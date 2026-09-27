---
key: TreeTargeting
summary: Whether the attack cursor appears over terrain objects such as trees without the force-fire modifier held.
see_also: ["LegalTarget"]
when_omitted:
  kind: value
  value: "no"
---

With `TreeTargeting=yes`, a player's selected armed object shows the attack cursor over any terrain object, and a click orders the attack, without the force-fire modifier. With `no`, it does so only while the modifier is held, or over a terrain type that sets [`LegalTarget=yes`](/keys/legaltarget/) or [`IsVeinhole=yes`](/keys/isveinhole/).

The setting affects only the player's cursor and click. It does not make terrain objects targets for automatic target scans or for a computer-controlled house.
