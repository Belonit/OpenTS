---
key: High
scope: overlaytype
label: High obstacle
see_also: ["system:walls-and-gates"]
when_omitted:
  kind: value
  value: "no"
---

A projectile explodes as soon as it reaches a cell holding this overlay, if it is flying less than 100 leptons (just under one height level) above the ground. It explodes in that cell even if its target lies beyond it. A projectile whose type sets [`High=yes`](/keys/high/#scope-bullettype) flies on. This is what stops a flat-firing weapon from shooting through a wall. A projectile with [`Inviso=yes`](/keys/inviso/) appears at its target without crossing the cells between, so this overlay does not stop it.

The test reads only this key. It does not depend on [`Wall=yes`](/keys/wall/#scope-overlaytype), on how damaged the overlay is, or on who owns the cell, so a friendly wall stops friendly fire just as an enemy wall does.
