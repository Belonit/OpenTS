---
key: SpecialThreatValue
summary: A per-type figure that TargetSpecialThreatCoefficient scales into a candidate's threat score.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "0"
---

When an object picks a target, each candidate's `SpecialThreatValue` is multiplied by the chooser's [`TargetSpecialThreatCoefficient`](/keys/targetspecialthreatcoefficient/) and added to that candidate's threat score. The value has no other effect in the game. Raising it makes objects with a positive coefficient prefer this type, and objects with a negative coefficient avoid it.

```ini title="rules.ini"
[MYPRIZE] ; example UnitType worth hunting
SpecialThreatValue=50
```

The five threat coefficients fall back to defaults in `[General]`, but this value has no such fallback. A type that does not set it adds nothing to any chooser's score, whatever the chooser's coefficient.
