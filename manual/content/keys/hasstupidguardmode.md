---
key: HasStupidGuardMode
summary: Makes an unarmed building do nothing while on its Guard mission, skipping its idle handling.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "yes"
---

The setting affects only a building with no weapon, which means no [`Primary=`](/keys/primary/) on the type and none on any upgrade plugged into it. An armed building on guard scans for targets instead and never reads it, so the setting cannot change what a defensive structure does.

At `yes`, an unarmed building on guard does nothing and checks again every 100 frames.

At `no`, it runs its idle handling on guard:

- A repair bay or reload bay ([`UnitRepair=yes`](/keys/unitrepair/) or [`UnitReload=yes`](/keys/unitreload/)) starts servicing the object in radio contact with it once that object, still under orders to enter, has stopped within a quarter of a cell of the bay.
- A reload bay also starts servicing the object in radio contact with it once that object has stopped or has no destination, unless it is an aircraft ready to leave. An aircraft is ready to leave when it has no target and is either landed with full ammunition or airborne with some ammunition left.
- A [`WeaponsFactory=yes`](/keys/weaponsfactory/) structure also clears its exit cell while idle. When something stands on that cell, that object and anything in the cells around it are told to move away. The structure clears the cell the same way before each new vehicle drives out, whatever this key says.
