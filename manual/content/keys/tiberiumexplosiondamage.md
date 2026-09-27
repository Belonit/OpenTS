---
key: TiberiumExplosionDamage
summary: Damage a Tiberium chain-reaction animation deals where it stands.
see_also: ["system:tiberium", "Debris"]
when_omitted:
  kind: value
  value: "100"
---

An animation with [`TiberiumChainReaction=yes`](/keys/tiberiumchainreaction/) that starts on a Tiberium cell removes all the Tiberium from the cell. It then deals this much damage at its position through [`C4Warhead`](/keys/c4warhead/). An animation that a trigger action plays does neither. The damage is fixed: the Tiberium type, the amount removed and the animation's settings do not change it.

The blast has no attacker, so no house is credited with its kills.
