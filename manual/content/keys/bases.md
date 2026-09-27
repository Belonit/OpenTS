---
key: Bases
summary: Starting state of the bases option for a multiplayer or skirmish match.
see_also: [BaseUnit, UnitCount, "system:crates", "system:starting-forces"]
when_omitted:
  kind: value
  value: "yes"
---

`Bases` sets the bases option when the game starts. The skirmish setup screen, the network lobby or the spawn settings then replace it for each match, so the value decides only how the option starts out.

With the option on and [`BaseUnit`](/keys/baseunit/) naming at least one type, every house starts with one base unit at its start position, and its [`UnitCount`](/keys/unitcount/) budget counts one unit fewer to pay for it. A house whose country sets [`MultiplayPassive`](/keys/multiplaypassive/) and an observer's house get neither the base unit nor starting forces. With the option off, each house gets only its random starting forces. [Starting forces](/systems/starting-forces/) covers where both are placed.

The option also changes two crate results. A crate gives [a house that has lost its base](/systems/crates/#money-and-free-units) a replacement base unit only while bases are on. While bases are off, the random vehicle result never gives a base unit.
