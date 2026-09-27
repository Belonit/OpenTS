---
key: Width
scope: smudgetype
label: Smudge width
see_also: ["Height", "Crater", "Burn"]
when_omitted:
  kind: value
  value: "1"
---

`Width` is the number of cell columns the smudge covers. [`Height`](/keys/height/#scope-smudgetype) sets its rows and describes the block the two sizes form: where it fits, how its artwork is drawn, and which requests prefer it.

```ini title="rules.ini"
[MYCRATER]     ; example two-by-two crater
Crater=yes
Width=2
Height=2
```

Keep `Width` at `1` or more. A smaller value makes a type that can still be picked but leaves no mark, as [`Height`](/keys/height/#scope-smudgetype) explains.
