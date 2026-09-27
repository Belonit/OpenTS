---
key: Scorches
summary: Parsed smudge list that the engine never uses.
no_effect: true
see_also: ["Burn", "Scorches1", "Craters"]
when_omitted:
  kind: value
  value: ""
---

The game does not choose scorch marks from this list. Wherever an animation or a destroyed structure scorches the ground, the game gathers every smudge type with [`Burn=yes`](/keys/burn/) that fits the spot. It prefers the marks whose size suits the blast and picks one of them at random. If none suits the blast, it picks from all the marks that fit the spot. A smudge type joins that pool through `Burn=yes` alone, whether or not this list names it.

The section holds five of these lists: this one and [`Scorches1`](/keys/scorches1/) through [`Scorches4`](/keys/scorches4/). None of them is used.

Naming a smudge type the game does not know yet, in any of the five lists, still registers a smudge type of that name. The list never places it.
