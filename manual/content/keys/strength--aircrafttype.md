---
key: Strength
scope: aircrafttype
label: Maximum strength
when_omitted:
  kind: context-dependent
  note: Most object types start at 0. A TerrainType whose section omits it takes TreeStrength from the General section instead.
---

`Strength` is the maximum strength of an object of this type: its hit points when undamaged. A newly built or produced aircraft, structure, infantry unit or vehicle starts at this value, and so does every terrain object. Damage lowers an object's strength, and repair and healing never raise it above this maximum.

Other objects can start below this value:

- An object the map places starts at the health the map gives it.
- A structure deployed from a vehicle, or a vehicle that undeploys from a structure, keeps the health ratio of the object it came from.
- Infantry that escape a destroyed vehicle or structure start at a random strength.

```ini title="rules.ini"
[ORCA]
Strength=200
```

A projectile does not use this key. Its strength is the damage it carries from the weapon that fired it.

Keep `Strength` at or above [`RepairStep`](/keys/repairstep/) on any structure, vehicle or aircraft that can be repaired. A lower `Strength` crashes the game when the [cost of a repair step](/systems/repair/#the-cost-of-one-step) is worked out.
