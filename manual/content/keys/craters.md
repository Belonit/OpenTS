---
key: Craters
summary: Parsed smudge list that the engine never uses.
no_effect: true
see_also: ["Crater", "Scorches"]
when_omitted:
  kind: value
  value: ""
---

Listing a smudge type here does not make it a crater, and leaving it out does not stop it from being one. A crater is picked at random from every registered smudge type with [`Crater=yes`](/keys/crater/#scope-smudgetype) that fits the spot, as that key's page describes.

An entry that names a smudge type the game does not already know still registers a smudge type of that name. Being on this list never causes that type to be placed.
