---
key: Burn
summary: Smudge type that belongs to the pool a scorch mark is chosen from.
see_also: [Crater, Width, Height, Scorch, Scorches]
when_omitted:
  kind: value
  value: "no"
---

`Burn=yes` makes the smudge type a candidate whenever the ground is scorched. No other setting adds a type to the scorch pool. Listing it in [`Scorches`](/keys/scorches/) has no effect.

Each scorch is picked at random from the `Burn=yes` types that fit the spot. [`Height`](/keys/height/#scope-smudgetype) describes the fit test and which sizes each kind of request prefers.

```ini title="rules.ini"
[MYSCORCH]     ; example single-cell scorch mark
Burn=yes
```

Two things scorch the ground:

- An animation with [`Scorch=yes`](/keys/scorch/). If it also sets [`Crater=yes`](/keys/crater/#scope-animtype), each occurrence leaves a scorch or a crater with even odds.
- A destroyed structure. Each mark it lays is a scorch or a crater with even odds. [A structure](/systems/destruction-and-debris/#a-structure) describes when the marks are laid.

`Burn` and [`Crater`](/keys/crater/#scope-smudgetype) are independent. A type with both can be picked as a scorch or as a crater. A type with neither is never picked for either, but a map can still place it through its `[Smudge]` section.
