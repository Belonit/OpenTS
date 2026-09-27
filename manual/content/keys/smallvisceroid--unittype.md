---
key: SmallVisceroid
scope: unittype
label: Small visceroid behavior
see_also: ["LargeVisceroid", "AltImage", "NonVehicle", "system:tiberium"]
when_omitted:
  kind: value
  value: "no"
---

`SmallVisceroid=yes` makes the vehicle behave as a small visceroid. It wanders on its own, heads for Tiberium when hurt, and merges with other small visceroids into a large one.

It wanders when it stands still with no destination and no target, on a guard mission or no mission at all. It picks one of the eight directions and moves one cell that way if it can enter the cell. It keeps its last direction two times in three.

Below [`ConditionYellow`](/keys/conditionyellow/) health, a visceroid standing off Tiberium heads for Tiberium within 16 cells instead. While it is hurt and standing on Tiberium, it wanders only onto other Tiberium cells. This steering heals nothing by itself. The visceroid heals on Tiberium only with [`TiberiumHeal=yes`](/keys/tiberiumheal/#scope-aircrafttype), as the shipped `VISC_SML` sets, or with the `TIBERIUM_HEAL` ability from [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/).

Merging is what separates it from a [`LargeVisceroid=yes`](/keys/largevisceroid/#scope-unittype) type:

1. A small visceroid standing still checks the eight cells around it, starting north and going clockwise, and stops at the first that holds another small visceroid.
2. If that neighbor has no destination and no target, it is sent to the first visceroid's cell. Either way, finding a neighbor ends that frame's check, so the visceroid neither wanders nor heads for Tiberium.
3. Small visceroids never block each other's cells, so the neighbor drives onto the first one.
4. On arrival, the visceroid that stayed becomes the type named by the global [`LargeVisceroid`](/keys/largevisceroid/#scope-global-rules) at that type's maximum strength. The one that arrived is removed.

Both visceroid flags give the type the same exemptions:

- [`NonVehicle`](/keys/nonvehicle/) is forced on after this key is read, whatever the section says.
- An EM pulse does not stun it.
- It can fire while immobilized, which no other object can.
- It does not need to face its target before it fires.
- A [`Jellyfish=yes`](/keys/jellyfish/) unit never stings it.
- It is drawn without a shadow.

It is drawn from its ordinary artwork except during an attack, which plays five frames of its [`AltImage`](/keys/altimage/) artwork.
