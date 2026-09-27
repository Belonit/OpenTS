---
key: HunterSeeker
scope: aircrafttype
label: Hunter-seeker drone flag
see_also: ["system:ion-storms"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYDRONE] ; example UnitType registered in [VehicleTypes]
Locomotor={4A582746-9839-11d1-B709-00A024DDAFD1} ; the flying locomotor
HunterSeeker=yes
Primary=SuicideBomb ; a WeaponType; the drone detonates with it
```

Makes the type a hunter-seeker drone. The drone chooses its own target, flies at it and detonates on arrival. The stock drones are vehicles on the flying locomotor, and a side's [hunter-seeker superweapon](/keys/hunterseeker/#scope-side) launches one.

The drone never fires its weapons, however it is armed. Its first weapon slot supplies the damage and warhead of its detonation, which [`HunterSeekerDetonateProximity`](/keys/hunterseekerdetonateproximity/) describes.

A drone with no target picks one at random from the objects on the map that meet **all of** these conditions:

- It belongs to a house that the drone's house is not allied with. Outside a campaign, a computer house with a declared enemy picks only that enemy's objects.
- It is alive and on the map, and its type is [`LegalTarget=yes`](/keys/legaltarget/#scope-aircrafttype) and not [`Invisible=yes`](/keys/invisible/).
- It is not a [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle while the [harvester truce](/keys/harvesterimmune/) is on.

In a multiplayer or skirmish game, a human player's drone prefers objects of houses that are not [`MultiplayPassive=yes`](/keys/multiplaypassive/). It picks an object of a passive house only when no other candidate exists.

A drone keeps looking for a target while it has none. When it finds one, it abandons any landing and attacks. It flies straight at the target's current position, or at the tunnel entrance the target went in by. [`HunterSeekerDescendProximity`](/keys/hunterseekerdescendproximity/) covers how it clears high ground and dives.

Only an object on the flying locomotor chooses its own target, flies at it and detonates. On any other locomotor the object does none of these, but the flag still stops it firing.

When a hunter-seeker vehicle that is not in a team leaves the playable area while it has a target, the vehicle is removed and the target takes the damage and warhead of the vehicle's first-slot weapon. This holds on any locomotor.

:::note[Hunter seekers fly through ion storms]
An object on the flying locomotor with this flag set neither loses power nor crashes when [a storm breaks](/systems/ion-storms/#the-storm-breaks).
:::
