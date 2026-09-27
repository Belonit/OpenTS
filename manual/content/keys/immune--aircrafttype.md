---
key: Immune
scope: aircrafttype
label: Damage immunity
when_omitted:
  kind: context-dependent
  note: A BulletType, SmudgeType or VoxelAnimType section starts at yes. Every other type starts at no.
---

An object of an immune type ignores damage unless the damage is [forced](/keys/c4warhead/). A shot still lands on it, but the object keeps its current strength. A healing weapon cannot restore its strength either.

Forced damage includes, for example, Tiberium poisoning an infantryman and a demolition charge destroying a structure when its countdown ends.

Two kinds of object ignore forced damage too when their type is immune:

- A TerrainType can be damaged only by a warhead marked [`Wood=yes`](/keys/wood/), and an immune one takes no damage at all. A vehicle armed with a `Wood=yes` warhead normally plans to shoot a TerrainType out of its path, but treats an immune one as impassable.
- A [`BridgeRepairHut=yes`](/keys/bridgerepairhut/) structure takes no damage at all.

The [low-power damage tick](/systems/power/#the-structure-damage-tick) is not forced, so `Immune=yes` keeps a structure that draws power from being worn down while its house is short of power.
