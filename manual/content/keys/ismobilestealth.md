---
key: IsMobileStealth
summary: Marks a deployed structure as a mobile stealth generator, one of the kinds treated as a deployed vehicle.
see_also: [DeploysInto, UndeploysInto, CloakGenerator]
when_omitted:
  kind: value
  value: "no"
---

The flag makes the structure one of the eight [deployed-vehicle kinds](/keys/deploysinto/), which deploy and [pack up](/keys/undeploysinto/) on the vehicle's own cell.

When [an EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) stuns the structure, sparks appear on it.

Unlike the other kinds, this one adds no facing, gun handling or cloaking of its own. The field a mobile stealth generator projects comes from [`CloakGenerator=yes`](/keys/cloakgenerator/), which any structure may set.
