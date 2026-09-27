---
key: RechargeVoice
summary: The EVA line spoken as the superweapon finishes charging.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

The line plays for the local player's weapon on the frame its countdown reaches zero and the weapon becomes ready.

Two kinds of weapon become ready without it. A [`UseChargeDrain=yes`](/keys/usechargedrain/) weapon never plays it. A one-time weapon from a trigger action or a crate arrives fully charged, and its grant is silent. An unrecognized speech name gives the weapon no line.
