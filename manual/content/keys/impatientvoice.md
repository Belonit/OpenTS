---
key: ImpatientVoice
summary: The EVA line spoken when the cameo of a still-charging superweapon is clicked.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

The line plays when the local player clicks the cameo of a weapon whose countdown is still running toward a full charge.

A weapon that cannot be fired and whose countdown is stopped plays [`SuspendVoice=`](/keys/suspendvoice/) instead, whatever this key says. That covers a suspended weapon, and a [`ManualControl=yes`](/keys/manualcontrol/) weapon waiting for its next start. An unrecognized speech name gives the weapon no line.
