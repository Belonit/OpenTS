---
key: Landable
summary: Keeps an aircraft under the player's control instead of letting it enter as an unselectable loaner that may leave the map.
see_also: ["Selectable", "Carryall", "Camera"]
when_omitted:
  kind: value
  value: "no"
---

`Landable=no` makes every aircraft of this type a loaner when it enters the map. A loaner is an aircraft the scenario lends to its owner. [`Selectable=no`](/keys/selectable/#scope-aircrafttype) and a [`Camera=yes`](/keys/camera/) primary weapon make an aircraft a loaner in the same way, and any one of the three is enough.

## What a loaner does

Its owner cannot select it while it is able to move. A stunned loaner, such as one hit by an [EMP pulse](/systems/emp-pulse/), can be taken by a [band box](/systems/band-selection/) or clicked while another object is selected, unless `Selectable=no` made it a loaner. Clicking a loaner with nothing selected never selects it.

A loaner may leave the map. Other aircraft may not, unless they belong to a team that is leaving the map and have no target.

Once a loaner has been inside the playable area, it is deleted as soon as it is outside it with no target and no team.

In a campaign, the player's loaners may fly into shrouded cells. The player's other aircraft may not.

An aircraft that runs out of ammunition during an attack drops its target if it is a loaner or belongs to a human player. A computer player's aircraft that is not a loaner keeps its target.

## When a loaner is idle

An idle loaner with no team never settles into guard. What it does depends on its load, its weapon and whether it is on the ground:

| Loaner | Idle behavior |
| --- | --- |
| Carrying passengers | Unloads them, first flying to a landing zone if it is in the air |
| Empty, on the ground | Takes the Retreat mission |
| Empty, in the air, armed, with ammunition | Hunts |
| Empty, in the air, armed, out of ammunition | Takes the Retreat mission |
| Empty, in the air, unarmed | Flies to a landing zone, then takes the Retreat mission once down |

A loaner in a team leaves the team in three cases, and then behaves as the table shows:

- it is armed, in the air and out of ammunition;
- it belongs to a human player, is empty and in the air, and its team has entered the map;
- it belongs to a computer player, its type sets [`Ammo=0`](/keys/ammo/), it is empty and in the air, and its team has entered the map. A computer player's aircraft that is not a loaner leaves its team in this case too.

The Retreat mission does nothing for an aircraft. A loaner on it picks no map edge and flies nowhere. Leaving the map, and the deletion outside the playable area, happen only when some other order takes it there.

## Aircraft the player keeps

With `Landable=yes`, the aircraft can be selected and may not leave the map, unless `Selectable=no` or a camera weapon makes it a loaner anyway. It may still leave the map with a team that is leaving it. Outside the playable area it is then deleted once it has no target.

When it goes idle on the ground, it guards. When it goes idle in the air, the first matching case applies:

1. An aircraft carrying passengers flies to a nearby landing zone.
2. An armed aircraft that is attacking a target with ammunition left, or has an attack order waiting, attacks.
3. An armed aircraft with [`Dock`](/keys/dock/) buildings looks for a free bay at one of them and enters it. When no bay is free, it flies to a nearby landing zone. This case needs the aircraft to have no move or enter order under way, and to have entered the map or have no team.
4. Any other armed aircraft guards.
5. An unarmed aircraft flies to a nearby landing zone, unless it belongs to a team.

## Reinforcement transports

A [reinforcement](/mapping/actions/taction-reinforcements/) delivered by a trigger can create a loaner whatever this key says. When the team's script includes an [Unload](/mapping/missions/tmission-unload/) mission, the aircraft transport that carries the rest of the team is marked a loaner as it is created.
