---
key: MaximumBaseDefenseValue
summary: Caps each of the three defense values computed for a base defense BuildingType.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "60"
---

A base defense's anti-air, anti-armor and anti-infantry values are each held at or below this figure. The computer uses those values to decide which part of its base needs a defense, which kind of defense to add, and where to place it. [Defense values](/systems/ai-base-building/#defense-values) shows how each value is computed from the type's primary weapon.

Set it to at least `1`. At `0` or below, no structure has a defense value in any category, so the computer has no candidate defenses and builds no base defenses.

The values also weight the random draw between candidate defenses, together with cost. When several types reach the cap in a category, their values there are equal, so only their costs make their chances differ. A cheaper type is more likely to be picked, but not certain to be.
