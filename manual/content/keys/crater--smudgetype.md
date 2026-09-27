---
key: Crater
scope: smudgetype
label: Crater smudge
see_also: ["Burn", "Width", "Height", "Craters"]
when_omitted:
  kind: value
  value: "no"
---

`Crater=yes` makes the smudge type a candidate whenever the ground is cratered. No other setting adds a type to the crater pool. Listing it in [`Craters`](/keys/craters/) has no effect.

Each crater is picked at random from the `Crater=yes` types that fit the spot. [`Height`](/keys/height/#scope-smudgetype) describes the fit test and which sizes each kind of request prefers.

```ini title="rules.ini"
[MYCRATER]     ; example two-by-two crater
Crater=yes
Width=2
Height=2
```

Two things crater the ground:

- An animation with [`Crater=yes`](/keys/crater/#scope-animtype). If it also sets [`Scorch=yes`](/keys/scorch/), each occurrence leaves a scorch or a crater with even odds.
- A destroyed structure. Each mark it lays is a scorch or a crater with even odds. [A structure](/systems/destruction-and-debris/#a-structure) describes when the marks are laid.

`Crater` and [`Burn`](/keys/burn/) are independent. A type with both can be picked as a crater or as a scorch. A type with neither is never picked for either, but a map can still place it through its `[Smudge]` section.
