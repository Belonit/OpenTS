---
key: SurvivorDivisor
summary: The divisor applied to a structure's cost when its number of survivors is worked out.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "100"
---

`SurvivorDivisor` works as a price per survivor. A structure yields one survivor for every `SurvivorDivisor` credits of the part of its cost that [`SurvivorRate`](/keys/survivorrate/) keeps, rounded down. That part must reach five times the divisor to yield the maximum of five survivors. A part smaller than the divisor still yields one.

```ini title="rules.ini"
[General]
SurvivorRate=.4
SurvivorDivisor=200  ; a 1,000-credit structure yields two survivors
```

A structure that has [changed hands](/systems/capture/#what-changes-hands) uses twice the divisor for the rest of the match, which roughly halves its survivors. The divisor doubles only once, however many times the structure changes hands.

`SurvivorDivisor=0` gives every structure no survivors.
