---
key: BaseUnit
summary: The UnitTypes handed out at a multiplayer start, one per house, and counted as a base of their own.
see_also: ["system:crates", "system:starting-forces", DeploysInto]
when_omitted:
  kind: value
  value: none
---

The listed vehicle types are base units. Each house may start with one, and several rules count a base unit the way they count a structure. No setting on the vehicle type itself gives it this role.

When a house is given a base unit, it gets the first listed type that the country it [acts as](/keys/actslike/) may own. If that country may own none of them, it gets the first entry. List one MCV per country to give each faction its own.

- **Match start.** With [`Bases`](/keys/bases/) on, each house that is neither passive nor an observer gets its base unit at its start position. If that cell is taken, the [placement search](/systems/starting-forces/#where-an-object-lands) tries the nearest cells out to thirty-one cells away. In capture the flag, the house's flag is attached to this unit. When the list names anything, the house's starting-force budget also counts one unit fewer to pay for it.
- **Random starting forces.** The [`AllowedToStartInMultiplayer=yes`](/keys/allowedtostartinmultiplayer/) types drawn for starting forces never include a listed type. Listed types are also left out of the [average price](/systems/starting-forces/#the-budget) that decides how many units are drawn.
- **Short game.** A house that holds no structures and no vehicle of a listed type is defeated. A structure with an [`UndeploysInto`](/keys/undeploysinto/) type does not count as a structure here, unless it is also `ConstructionYard=yes`.
- **Crates.** While bases are on, a house that has no structures, no vehicle of a listed type and more than 1500 credits can [receive its base unit from a crate](/systems/crates/#money-and-free-units). With bases off, the random vehicle crate result never gives a listed type.
- **Center Base.** The [Center Base](/commands/centerbase/) command looks for a [`BuildConst`](/keys/buildconst/) structure. When the player has no building at all, it centers on a vehicle of a listed type instead.

An empty list is valid. No house gets a base unit, the unit count is not reduced, and in a short game a house loses when its last structure is gone.
