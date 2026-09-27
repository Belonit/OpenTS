---
key: ImmuneToVeins
summary: Exempts the object type from vein damage.
see_also: ["system:veins", "VeinDamage", "VeinAttack"]
when_omitted:
  kind: value
  value: "no"
---

[Vein attacks](/systems/veins/#standing-in-veins) leave an object of an exempt type alone. It does not start an attack by standing in flat, mature veins, and it takes no damage from an attack that another object in the same cell started.

The `VEIN_PROOF` [veteran ability](/systems/veterancy/#abilities) gives the same exemption to a single object whose type does not set this key.
