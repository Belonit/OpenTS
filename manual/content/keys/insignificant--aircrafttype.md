---
key: Insignificant
scope: aircrafttype
label: Bookkeeping exemption
see_also: ["system:capture", "system:destruction-and-debris"]
when_omitted:
  kind: context-dependent
  note: An AircraftType, BuildingType, InfantryType, ParticleType, ParticleSystemType or UnitType section starts at no. A BulletType, OverlayType, SmudgeType, TerrainType or VoxelAnimType section starts at yes.
---

`Insignificant=yes` keeps an object out of its house's object counts, loss records and responses to attack. It affects only objects a house owns: aircraft, structures, infantry and vehicles. On any other type the value has no effect.

```ini title="rules.ini"
[MYBARREL]     ; an example BuildingType
Insignificant=yes
```

An `Insignificant=yes` object is treated as follows:

- **It is left out of its house's object counts.** These counts decide:
  - A positive [`BuildLimit`](/keys/buildlimit/), which then limits only how many vehicles, infantry or aircraft of the type are queued at once, and does not limit a structure type at all. A negative `BuildLimit` counts every object produced and still applies.
  - Defeat in a skirmish or multiplayer game, so a house left with only `Insignificant=yes` objects is defeated.
  - Trigger events that check what a house still owns, such as [Destroyed, All...](/mapping/events/tevent-all-destroyed/) and [Building exists...](/mapping/events/tevent-building-exists/).

  A captured one [changes hands](/systems/capture/#what-changes-hands) without moving between the two houses' counts. A structure still satisfies prerequisites, which use a separate count.
- **A structure is left out of the loss and kill records.** Its destruction does not count as a structure lost for its owner or a structure destroyed for the attacker, and it is left out of the [multiplayer statistics](/systems/multiplayer-score-screen/). A vehicle, aircraft or infantry soldier still counts as a unit lost and a unit killed.
- **It dies without a loss announcement.** When a vehicle, aircraft or infantry soldier owned by the local player dies, EVA does not [announce the loss](/systems/destruction-and-debris/#the-loss-announcement) and the [Goto Radar Event](/commands/centeronradarevent/) cell does not move. Structures never make this announcement.
- **Damage to a structure raises no warning.** Its owner gets no base-under-attack line or radar event, a local player allied to the owner hears no ally-attacked line, and trigger tags attached to the owner get no [Attacked](/mapping/events/tevent-attacked/) event. [What the house announces](/systems/base-attacked/#what-the-house-announces) describes these responses. A trigger tag attached to the structure itself still springs Attacked.
- **A computer house sends no defenders.** Attacking the object does not make its computer owner [call defenders back](/systems/base-attacked/#calling-defenders-back).

The setting has no other effect. The object can still be targeted, ordered and captured as usual.
