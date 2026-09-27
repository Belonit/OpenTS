---
key: Nominal
summary: Shows the type's real name to a player it is not allied with, instead of a generic label.
see_also: [Technician, Crewed, Invisible]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYPRISON] ; a BuildingType registered in [BuildingTypes]
Nominal=yes
```

Holding the cursor over an object shows its name. That is normally the type's [`Name=`](/keys/name/), though a technician (below) and a [disguised](/keys/disguise/) soldier can show another name. The player sees the name on objects that the player or an ally owns, and an [observer](/systems/observers/) sees it on every object. Any other object normally shows a generic label instead: "Enemy Soldier" for infantry, "Enemy Vehicle" for a vehicle or aircraft, and "Enemy Structure" for a structure. `Nominal=yes` exempts the type, so a civilian or story structure shows its real name to every player.

A structure placed by a map can carry the same exemption on that one building, whatever its type sets.

On an InfantryType, the key has a second, unrelated effect. A structure's [survivor](/systems/capture/#survivors) of this type can be marked as a technician. A technician is named "Technician", does not count toward its house's infantry total, and cannot be picked up as a civilian evacuee. [`Technician`](/keys/technician/) lists when a sold or destroyed structure marks its survivors.
