---
key: Invisible
summary: Hides the object from every player except its owner, and keeps it off the radar.
see_also: [InvisibleInGame, "system:cloaking"]
when_omitted:
  kind: value
  value: "no"
---

An `Invisible=yes` object is visible only to the player who owns it. On that player's machine it is drawn normally, cloaked or not. On every other machine, including an ally's, it is not drawn at all, and the tooltip, the cursor and click-selection ignore it.

No machine plots the object on the radar, not even its owner's.

A [hunter-seeker drone](/keys/hunterseeker/#scope-aircrafttype) never chooses it as a target.

A BuildingType with [`InvisibleInGame=yes`](/keys/invisibleingame/) has this key turned on, even when its section sets `Invisible=no`.

:::danger[Firing decisions differ between machines]
Do not set `Invisible=yes` on a type that another player's objects can attack in a multiplayer game; otherwise the game desyncs. Each machine decides whether an attack is allowed by whether its own player can see the target. The attack on an `Invisible=yes` object therefore goes ahead on its owner's machine and is refused on every other. A sensor of the attacking house that covers the object's cell makes the attack allowed on every machine.
:::
