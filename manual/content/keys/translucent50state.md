---
key: Translucent50State
summary: The animation state at which a flame particle thins to half faded.
see_also: ["Translucent25State", "Translucency", "EndStateAI", "StartStateAI"]
when_omitted:
  kind: value
  value: "-1"
---

A [`Fire`](/keys/behaveslike/#scope-particletype) particle becomes half faded when its animation state reaches this number. It follows the same rules as [`Translucent25State`](/keys/translucent25state/), which lists the states that can be matched and explains the default `-1`. If both settings name the same state, this one wins, because it is applied second.

The two settings need not be in order. If this state comes before the quarter-fade state, the flame turns half faded first and then back to a quarter faded, because each state sets the level it names.
