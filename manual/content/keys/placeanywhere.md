---
key: PlaceAnywhere
summary: Passes every placement legality test without examining a single cell.
see_also: [Buildable, DeploysInto, "system:base-adjacency"]
when_omitted:
  kind: value
  value: "no"
---

A `PlaceAnywhere=yes` BuildingType passes its legality test at any location. The test normally checks each cell of the structure's foundation. For an ordinary structure, a cell passes under **All of:**

- nothing already occupies it;
- it lies inside the playable area;
- no blocking overlay lies on it;
- it is not on a bridge, under a bridge or on a ramp;
- its land type is [`Buildable=yes`](/keys/buildable/).

Walls, gates, laser fences, [`WaterBound=yes`](/keys/waterbound/#scope-buildingtype) structures and structures that pave the ground they cover apply variations of these rules. A paving structure needs only one clear cell; every other structure needs all of them.

With the flag set, none of these cells is checked.

These placements use the test:

- Putting the structure on the map by any route, including building, deploying and trigger actions. A structure that fails the test is not placed; a flagged one is placed wherever it was sent.
- The deploy cursor on a vehicle whose [`DeploysInto`](/keys/deploysinto/) names the type.
- The deploy order on that vehicle.
- The search a vehicle runs for a nearby spot it could deploy on.
- The [Deploy](/mapping/missions/tmission-deploy/) team mission. A member that fails the test clears the cell and waits; a flagged one deploys where it stands.
- The computer's search for a spot in its base. That search still applies its own spacing, height and adjacency conditions.
- The random map generator's search for spots to put `GALITE` light posts.

:::caution[The placement cursor does not read the flag]
The cursor shown while a player holds a pending structure checks each covered cell directly and ignores this flag. A flagged structure keeps showing the blocked cursor over ground it could not otherwise take. The click itself is refused only for [adjacency](/systems/base-adjacency/) or shroud, so the placement then succeeds.
:::
