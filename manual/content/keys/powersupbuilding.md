---
key: PowersUpBuilding
summary: The ObjectType ID of the structure this type plugs into as an upgrade.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: none
---

A type that names a host is a plug: it is placed onto an existing structure instead of onto the ground. The placement is accepted under **All of:**

- the target cell holds a structure whose type is the named host, matched without regard to letter case;
- that structure belongs to the same house as the plug;
- the host has room for the plug, as [`PowersUpToLevel`](/keys/powersuptolevel/) describes.

An accepted plug is absorbed. Its own structure is deleted, the host records it in an [upgrade slot](/keys/upgrades/), and the host is repaired to full strength.

The plug's positive [`Power=`](/keys/power/#scope-buildingtype) is added to the host's output, and the host's health scales the sum. If the host is later damaged to half strength, the plug's output halves with it. A plug's drain is added to the host's drain unscaled.

:::danger[Give the host at least one upgrade slot]
Set [`Upgrades=1`](/keys/upgrades/) or more on every host type except the one [`WallTower`](/keys/walltower/) names. A host whose type leaves `Upgrades` at `0` accepts every plug placed on it. Each plug is deleted and the host repaired, but the host gains no slot, so the plug adds no power, weapon or superweapon. Each plug also corrupts the host's animation data, which can crash the game.

The `WallTower` structure is exempt, because it gains a slot for each plug whatever its `Upgrades`.
:::

:::caution[Installing a plug rewrites the host type's animation slot]
The plug's art name is copied into the host BuildingType's animation entry for the slot being filled, replacing any `PowerUp<n>Anim=` set for it. The entry belongs to the type, not to the structure, so every later host of that type shows the art of whichever plug was installed last.
:::
