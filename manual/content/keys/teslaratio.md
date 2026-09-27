---
key: TeslaRatio
summary: Parsed Tesla coil share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", TeslaLimit]
when_omitted:
  kind: value
  value: ".16"
---

The engine has no Tesla coil category of structure. A structure charges before it fires when its primary weapon sets [`Charges=yes`](/keys/charges/). [The defense planner](/systems/ai-base-building/#base-defenses) picks a computer house's defenses from each type's [defense values](/systems/ai-base-building/#defense-values).
