---
key: AutoCrush
scope: global-rules
label: IQ threshold
see_also: ["IQ", "Crusher"]
when_omitted:
  kind: value
  value: "2"
---

A computer house whose [`IQ`](/keys/iq/) is at or above this value lets its vehicles answer being shot by driving over the attacker instead of returning fire. A vehicle does so only when all of these hold, in the order the engine tests them:

- the vehicle is on no team;
- the vehicle is not leaving a transport or factory and is not docked at a building;
- the vehicle's house is not allied to the attacker;
- the vehicle has [`Crusher=yes`](/keys/crusher/) or has earned the crusher ability;
- the attacker has [`Crushable=yes`](/keys/crushable/#scope-aircrafttype);
- the attacker is no farther away than [`Crush`](/keys/crush/);
- the house is not in difficulty slot 2, the `[Difficult]` section;
- the house's IQ is at or above this value;
- the attacker is not infantry whose type has [`Disguised=yes`](/keys/disguised/).

:::caution[The `[Difficult]` slot never crushes in answer to fire]
A computer house in [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot) 2 never answers fire by driving over the attacker, whatever its IQ. With the menu's settings, computer houses take that slot when the player chooses Easy, so on the easiest setting no computer vehicle answers fire this way. Outside a campaign, [`CompEasyBonus=yes`](/keys/compeasybonus/) moves each computer house down to slot 1, the `[Normal]` section, when the session has more than one human player, and those houses crush again.
:::
