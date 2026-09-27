---
key: ShareSource
summary: The object type a voxel animation borrows its voxel model from.
see_also: ["ShareBodyData", "ShareTurretData", "ShareBarrelData", "VoxelIndex"]
when_omitted:
  kind: value
  value: none
---

`ShareSource` names the object type whose voxel model the animation draws. It is read only when [`ShareBodyData`](/keys/sharebodydata/), [`ShareTurretData`](/keys/shareturretdata/) or [`ShareBarrelData`](/keys/sharebarreldata/) is set, and that flag chooses which of the type's models is used. With none of the flags set, the animation loads the `.VXL` file named by its [`Image`](/keys/image/#scope-aircrafttype) and ignores this key.

The value is an ObjectType ID. The engine looks for it among the InfantryTypes, then the VehicleTypes, AircraftTypes and BuildingTypes, and takes the first match. The animation draws that type's model directly, not a copy.

```ini title="rules.ini"
[VoxelAnims]
20=MYTURRETDEBRIS ; a VoxelAnimType, registered here so the rules create it

[MYTURRETDEBRIS]
ShareTurretData=yes
ShareSource=MYTANK ; a VehicleType registered in [VehicleTypes]
VoxelIndex=0
MinAngularVelocity=10.0
MaxAngularVelocity=14.0
```

The animation has no model when the name matches no type, or when the named type holds no model for the part the flag asks for. An infantry type drawn from shapes has no body model, and a vehicle without a turret has no turret or barrel model. A piece without a model is still created, bounces, damages what it lands on and expires, but it is never drawn.

:::danger[Declare the borrowing again wherever the lender or the flag changes]
A borrowed model belongs to the type it came from. Two kinds of later declaration leave the animation pointing at freed memory:

- A later rules or map file that declares the animation's section without its sharing flag turns the borrowing off. The animation frees the borrowed model and loads a `.VXL` file for itself. The lending type is then drawn from freed memory, and the game frees the same memory twice when the next mission loads or the game exits.
- A later rules or map file that declares the lending type's section makes a lender with voxel artwork load its models again and free the old ones. The animation keeps drawing the freed model unless the same file also declares the animation's section with its sharing flag.
:::

:::caution[Borrowed models are lost in a loaded game]
Loading a saved game does not restore a borrowed model. Each borrowing animation looks for a `.VXL` and `.HVA` pair named by its [`Image`](/keys/image/#scope-aircrafttype) instead. If the pair exists, the animation draws that model; otherwise its pieces are invisible for the rest of the game.
:::
