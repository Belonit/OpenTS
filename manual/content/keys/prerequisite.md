---
key: Prerequisite
summary: The structures a house must own before the type appears on its build list.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ""
---

A human house can build the type only while every entry in the list is satisfied.

An entry naming a BuildingType requires the house to own at least one structure of exactly that type on the map. A structure counts from the moment it is placed, before its buildup finishes, and it still counts while switched off.

Seven reserved names stand for a group instead: `POWER`, `FACTORY`, `BARRACKS`, `RADAR`, `TECH`, `GDIFACTORY` and `NODFACTORY`. Owning any structure on the matching rules list satisfies the group. [Prerequisites](/systems/production/#what-a-house-may-build) maps each name to its list and covers the different rule for an entry that names an upgrade.

```ini title="rules.ini"
[MYTANK] ; example UnitType
Prerequisite=FACTORY,MYRADAR
; FACTORY: any structure on the PrerequisiteFactory list
; MYRADAR: an example radar BuildingType, named by its ID
```

Names are matched without regard to case. An entry that is neither a group name nor a BuildingType ID is dropped from the list.

A computer house skips this test when it produces. When it [plans its base](/systems/ai-base-building/#building-the-plan), it tests the list against the structures it plans to own, and some entries count differently there. `POWER`, for example, always counts as met.
