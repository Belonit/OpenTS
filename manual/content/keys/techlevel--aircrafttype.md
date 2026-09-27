---
key: TechLevel
scope: aircrafttype
label: Object tech level
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "255"
---

A house may build the type only while [the house's tech level](/keys/techlevel/#scope-house-per-scenario) is at least this value. This is the first of the [build-list gates](/systems/production/#what-a-house-may-build), and the only one a computer house also faces. The default of `255` is far above any level a house is normally given, so a type that never sets the key stays off every build list.

`TechLevel=-1` keeps the type off every house's build list, whatever level the house holds. Use it for a type that must exist in the rules but never be built. A `-1` member of a TaskForce sets the [AI trigger's tech level requirement](/systems/ai-team-production/#which-triggers-are-eligible) to `11`, even when an earlier member needed more. A later member that needs more than `11` raises it again.

Three selections compare the numbers directly, so `-1` counts as within every house's level there:

- A type allowed by [`AllowedToStartInMultiplayer`](/keys/allowedtostartinmultiplayer/) can still be handed out among the [starting forces](/systems/starting-forces/).
- A BuildingType with [`AIBuildThis=yes`](/keys/aibuildthis/) can still enter a computer house's [base plan](/systems/ai-base-building/).
- A BuildingType with an anti-air, anti-armor or anti-infantry value can still be picked as one of a computer house's [base defenses](/systems/ai-base-building/#base-defenses).
