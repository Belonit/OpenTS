---
key: LegalTarget
scope: aircrafttype
label: Object targetability
see_also: ["system:target-selection"]
when_omitted:
  kind: context-dependent
  note: Most object types start targetable. A BulletType, SmudgeType, TerrainType or VoxelAnimType starts untargetable instead, and a TerrainType is forced back to targetable when its section sets IsVeinhole=yes.
---

With `LegalTarget=no`, no automatic target scan picks an object of this type, and pointing at one does not offer the attack cursor. On an OverlayType, pointing at the overlay's cell does not offer the attack cursor.

```ini title="rules.ini"
[MYPROP] ; example BuildingType used as scenery
LegalTarget=no
```

The flag is checked only when a scan picks candidates and when the cursor is chosen, so it does not stop every attack:

- A player can still order an attack by holding the force-fire key, left Ctrl by default.
- An object that already has one of these objects as its target keeps attacking it.
- [Retaliation](/systems/target-selection/#retaliation) does not scan, so an object damaged by one of these objects can still fire back at it.

With [`TreeTargeting=yes`](/keys/treetargeting/) in `[CombatDamage]`, pointing at a TerrainType offers the attack cursor whatever this key says.
