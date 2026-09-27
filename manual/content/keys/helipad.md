---
key: Helipad
summary: Lets a BuildingType accept an aircraft as a docking target.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "no"
---

An allied aircraft may dock with a `Helipad=yes` structure. The pad refuses any other kind of object. Like every docking structure, it refuses while it is being built or sold, switched off, or already serving another object. On a structure that also sets [`UnitRepair=yes`](/keys/unitrepair/), the repair bay's docking rules decide instead.

A plain pad neither repairs a docked aircraft nor restores its ammunition. Repair comes from `UnitRepair=`, and ammunition from [`UnitReload=`](/keys/unitreload/). The stock pads set `UnitReload=yes`.

A player's aircraft ordered onto a pad docks there only while the pad is free, meaning it is in radio contact with nothing and carries no cargo. An aircraft heading for a pad that is already taken looks for another free structure of a type its [`Dock=`](/keys/dock/) lists. If it finds none, it lands at a clear landing spot instead. An empty carryall ordered into a pad lands at ground level.

A [`FreeUnit=`](/keys/freeunit/) aircraft handed out by a pad stays docked on it.

While [the base plan is assembled](/systems/ai-base-building/#building-the-plan), a computer house adds a type with this flag one to three extra times, so its plan holds two to four of that pad.
