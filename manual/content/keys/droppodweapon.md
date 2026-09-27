---
key: DropPodWeapon
summary: Selects the WeaponType used by airborne drop-pod effects.
see_also: ["system:drop-pods"]
when_omitted:
  kind: value
  value: none
---

The weapon gives a falling pod two effects: a `SMOKEY` smoke trail, and repeated shots at its landing cell. Without a weapon, the pod leaves no trail and fires nothing, and the rest of its fall and landing is unchanged. [Descent and airborne effects](/systems/drop-pods/#descent-and-airborne-effects) describes the shots.

Give the weapon a nonzero `Damage` and a warhead that lists at least one `AnimList` animation. Otherwise the game crashes on the pod's first shot.

:::danger[Register this weapon to keep weapon numbers stable]
A weapon missing from the rules [`[Weapons]` list](/formats/rules-registries/) is numbered where it is first named, and `[General]` is read before any object type names its weapons. Adding, removing or renaming an unlisted weapon here therefore shifts the weapon numbers stored in [Do Explosion At](/mapping/actions/taction-do-explosion/) trigger actions. Listing the weapon in `[Weapons]` fixes its number.
:::
