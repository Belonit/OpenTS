---
key: SuspendVoice
summary: The EVA line spoken when the cameo of a superweapon whose timer is stopped is clicked.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

The line plays when the local player clicks the cameo of a weapon that cannot be fired and whose countdown is stopped. That covers a [suspended](/systems/power/#superweapons) weapon, and a [`ManualControl=yes`](/keys/manualcontrol/) weapon waiting for its next start. A weapon whose countdown is still running plays [`ImpatientVoice=`](/keys/impatientvoice/) instead.

The line only answers a click. Nothing plays it at the moment a weapon is suspended. An unrecognized speech name gives the weapon no line.
