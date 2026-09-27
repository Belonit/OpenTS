---
key: Cyborg
summary: Lets a standing soldier survive a killing hit and crawl on, and exposes it to EM pulses.
see_also: [Strength, BerzerkAllowed, ConditionRedSparkingProbability, CollateralDamageCoefficient, "system:emp-pulse"]
when_omitted:
  kind: value
  value: "no"
---

## Surviving a killing hit

A standing cyborg is not killed by damage that would take it to zero strength. Instead:

- its strength is set to a quarter of its [`Strength`](/keys/strength/), and never below `1`;
- [`InfantryExplode`](/keys/infantryexplode/) plays at its position;
- it drops prone and starts to crawl.

The hit counts as a drop into condition red, not as a kill, so nothing that reacts to a destruction sees one.

A prone cyborg gets no reprieve. The next killing hit plays `InfantryExplode` and removes the soldier at once, with no death animation and no corpse. The exception is a cyborg knocked off a height that dies just above water, which leaves a splash instead. [`InfantryExplode`](/keys/infantryexplode/) lists the order of these cases.

Forced damage, such as Tiberium damage to a soldier standing in it, skips the reprieve even for a standing cyborg. The soldier is removed at once and leaves no corpse. A warhead with [`InfDeath`](/keys/infdeath/) `3`, `4` or `5` still plays its death animation, and a laser fence kill plays the electrocution animation. `InfantryExplode` also plays if the soldier was falling.

## Getting up again

A human player's prone infantry normally stands and runs when ordered twice to the same destination. A cyborg does not, so it crawls the whole way. A [`Fraidycat=yes`](/keys/fraidycat/) soldier is excluded the same way.

A cyborg stands up again only as its fear wears off. A type that sets [`Fearless=yes`](/keys/fearless/) never gains fear, so after the reprieve it crawls until it dies. A cyborg type without `Fearless=yes` gains fear from hits like other infantry. Fear can drop it prone, and a killing hit on it then gets no reprieve. It stands up once its fear falls low enough, and a standing cyborg can survive another killing hit.

## Other effects

With [`BerzerkAllowed=yes`](/keys/berzerkallowed/) in `[CombatDamage]`, a cyborg can go berserk once, on a hit that takes it below half strength, and then switches to Area Guard. `BerzerkAllowed` covers which hits count. A berserk soldier [ignores allegiance](/systems/target-selection/#why-a-candidate-is-rejected) when it picks targets.

A cyborg is the only infantry an [EM pulse](/systems/emp-pulse/#what-a-pulse-reaches) stuns.

`Cyborg=yes` is the only way to give an InfantryType [damage sparks](/keys/conditionredsparkingprobability/).

It also selects a lower starting [`CollateralDamageCoefficient`](/keys/collateraldamagecoefficient/) for the type, except on the first rules layer that names the section. That key's page gives both values. A section that writes `CollateralDamageCoefficient` gets that value only on that rules layer, so repeat the key in every rules file that names the section.
