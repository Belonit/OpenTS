---
key: IsTiberium
scope: animtype
label: Animation Tiberium seeding
see_also: ["system:tiberium", "TiberiumSpawnType", "TiberiumSpreadRadius", "Bouncer"]
when_omitted:
  kind: value
  value: "no"
---

`IsTiberium=yes` plants Tiberium around the point where a thrown animation lands. [`TiberiumSpawnType`](/keys/tiberiumspawntype/) names the Tiberium, and nothing is planted without it. [`TiberiumSpreadRadius`](/keys/tiberiumspreadradius/) selects which of the cells around the landing cell can take it. Each cell that takes Tiberium starts at one of the first three growth stages, chosen at random.

The flag works only on an animation thrown by [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype). On any other animation it has no effect.

Nothing is planted when the animation lands in water, or when it ends four height levels (416 leptons) or more above the ground, which is where a bridge deck sits.

A cell takes Tiberium only when it meets **All of:**

- it is inside the playable area;
- it is not under a bridge and never was;
- no living, visible building stands on it;
- no Tiberium-spawning terrain object stands on it;
- its land type is one that can be built on;
- it holds no overlay of any kind;
- it is flat or on one of the four simple slopes;
- its terrain tile allows Tiberium.

Cells that fail any condition are skipped.
