---
key: TargetEffectivenessCoefficientDefault
summary: The TargetEffectivenessCoefficient that vehicle, infantry, aircraft and structure types fall back on.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "0"
---

Every vehicle, infantry, aircraft and structure type that does not set [`TargetEffectivenessCoefficient`](/keys/targeteffectivenesscoefficient/) uses this value. No stock type sets its own, so in the stock rules this value applies to every type. `[General]` is read before the types in every rules layer, so one line in `rules.ini` also reaches the types that the expansion rules add.

Setting this key again in a later rules layer, such as the expansion rules or the map, reaches fewer types. A type that already holds a nonzero value from an earlier layer keeps it. The new value reaches only the types that layer reads for the first time and the types still at `0` whose section it contains. Every stock type holds the stock `-200` once `rules.ini` is read, so a map that sets this key changes none of them.

A type that writes `TargetEffectivenessCoefficient=0` keeps `0` only until a later rules layer, such as the expansion rules or the map, contains the type's section without the key. That layer replaces the `0` with this value. [Where the coefficients come from](/systems/target-selection/#where-the-coefficients-come-from) covers the layering.

The term this coefficient scales is the [`Verses`](/keys/verses/) value of the warhead the candidate would use against the choosing object, for that object's armor. The weapon's damage does not enter it. A candidate with no weapon adds nothing to it. A positive value makes every affected type prefer dangerous candidates, and a negative value, such as the stock `-200`, makes them avoid dangerous ones. The sign reverses for a candidate that is already targeting the choosing object.
