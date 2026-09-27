---
key: WallTower
summary: The BuildingType that joins a brick or sandbag wall run from any direction.
see_also: ["system:walls-and-gates", "system:ai-base-building"]
when_omitted:
  kind: value
  value: none
---

The BuildingType this key names is the wall tower. No flag on the type gives it the role, and only one type can hold it. [Wall towers](/systems/walls-and-gates/#wall-towers) describes the behavior in full.

While it stands, the tower counts as a continuation of a brick or sandbag wall from all four directions, so a wall run can turn a corner or meet another run through it. Nod walls never connect to it. [Connection frames](/systems/walls-and-gates/#connection-frames) covers how runs join.

The tower can be placed on a brick or sandbag wall cell its house owns, even an undamaged one; an ordinary wall piece can only replace a damaged segment. For a house a human is playing, a sellable segment under the tower is removed first, without refund. A computer house's tower stands on top of the segment and can only be placed this way on a brick wall.

The tower also takes plugged-in upgrades differently from other structures. [`PowersUpToLevel`](/keys/powersuptolevel/) and [`TurretAnim`](/keys/turretanim/#wall-towers) cover the difference.

:::caution[Removing a tower damages the wall around it]
When the tower is taken off the map, each of the four adjacent cells that holds an undamaged wall takes a 200-damage hit. A wall whose [`Strength`](/keys/strength/#scope-overlaytype) is 200 or less always loses a stage. A stronger wall loses one with a chance of about 200 in its `Strength`. Either loss can start the [cascade](/systems/walls-and-gates/#stepping-through-the-stages) along the run.
:::

## Computer bases

Each rules file that sets `WallTower` also replaces the first side's [`AIWallTowers`](/keys/aiwalltowers/) list with the named type, which is how the computer's GDI bases get their towers. An `AIWallTowers=` in that side's own section of the same file overrides it. The towers a computer house plans come from its side's `AIWallTowers`, not from this key.

When the computer places the tower this key names, the next base defense in its plan moves onto the tower's cell. Other types on an `AIWallTowers` list do not move it.

When a player's base passes to the computer, each tower of this type holding at least one upgrade fills the next unfilled base-defense placeholder in the computer's plan, and its last upgrade is written in after it. The house's side does not matter, but two conditions do:

- A placeholder must remain. Once the plan has none left, no further tower is written.
- One of the house's factories must be able to build the tower type under the normal build rules.

A tower of this type without an upgrade is left out, and so is a tower of any other type unless it is [`IsBaseDefense=yes`](/keys/isbasedefense/#scope-buildingtype).

:::caution[Leave IsBaseDefense off the tower type]
A tower type with `IsBaseDefense=yes` is not left out when it has no upgrade. When a base holding such a tower passes to the computer, the game reads an upgrade the tower does not have, which can crash it.
:::
