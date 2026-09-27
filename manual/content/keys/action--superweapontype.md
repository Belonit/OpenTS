---
key: Action
scope: superweapontype
label: Superweapon cursor action
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: "None"
---

`Action=` decides what clicking the weapon's charged cameo does, and which click on the map fires the weapon.

- With `None`, clicking the charged cameo fires the weapon at once at cell 0,0, with no targeting step. The stock firestorm defense and hunter seeker are fired this way.
- Any other value arms targeting mode. The cursor over the map shows this action in place of the usual one, and releasing the left button fires the weapon at the cell under the pointer.

[Aiming and the click](/systems/superweapons/#aiming-and-the-click) covers targeting mode in full.

`Nuke`, `IonCannon`, `DropPod`, `ChemBomb`, `EMPulse` and `EMPulseRange` are the actions with superweapon cursors. `EMPulse` and `EMPulseRange` are the EM pulse's in-range and out-of-range cursors.

[`Type=`](/keys/type/#scope-superweapontype) alone decides what the weapon does when it fires; `Action=` changes only the cursor and the click. A `Type=EMPulse` weapon is the exception. Once its targeting mode is armed, its cursor is always one of the [EM pulse](/systems/emp-pulse/#em-pulse-cannon-superweapon) cursors, and an in-range click fires the first section with `Action=EMPulse`. Give a `Type=EMPulse` section `Action=EMPulse`.

The [missile crate](/systems/superweapons/#one-shot-at-a-time) also picks its weapon by this key. When some section has `Type=MultiMissile`, the crate grants the first section with `Action=Nuke`.

:::caution[An unrecognized value reads as `None`]
A misspelled value is not rejected. It becomes `None`, so clicking the charged cameo fires the weapon at cell 0,0 with no way to choose where the effect lands.
:::

:::caution[Give each section a distinct value]
Use a value that no other section and no ordinary order uses. Two sections that share a value always fire the earlier one, and a charged weapon whose value is an order such as `Attack` or `Move` fires on the player's next such order. [Aiming and the click](/systems/superweapons/#aiming-and-the-click) explains how a map click picks the weapon.
:::
