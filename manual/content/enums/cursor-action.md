---
enum_id: ActionType
slug: cursor-action
title: Cursor action
summary: Named cursor and click actions accepted by action-valued INI settings.
representation: token
bindings:
  key_value_types: [actiontype]
  scripting_parameter_types: []
source_files: [code/action.hh, code/ccini.cpp]
values:
  - { constant: ACTION_NONE, value: 0, input: "None", meaning: "No available action." }
  - { constant: ACTION_MOVE, value: 1, input: "Move", meaning: "Move to the cell under the cursor." }
  - { constant: ACTION_NOMOVE, value: 2, input: "NoMove", meaning: "Movement to the cell under the cursor is not allowed." }
  - { constant: ACTION_ENTER, value: 3, input: "Enter", meaning: "Enter the transport, facility, or building under the cursor." }
  - { constant: ACTION_SELF, value: 4, input: "Self", meaning: "Act on the selected object itself." }
  - { constant: ACTION_ATTACK, value: 5, input: "Attack", meaning: "Attack the target under the cursor." }
  - { constant: ACTION_HARVEST, value: 6, input: "Harvest", meaning: "Harvest the resource cell under the cursor." }
  - { constant: ACTION_SELECT, value: 7, input: "Select", meaning: "Replace the current selection." }
  - { constant: ACTION_TOGGLE_SELECT, value: 8, input: "ToggleSelect", meaning: "Toggle the target's selection state." }
  - { constant: ACTION_CAPTURE, value: 9, input: "Capture", meaning: "Capture the building or vehicle under the cursor." }
  - { constant: ACTION_REPAIR, value: 10, input: "Repair", meaning: "Repair the object under the cursor." }
  - { constant: ACTION_SELL, value: 11, input: "Sell", meaning: "Sell the structure or wall under the cursor." }
  - { constant: ACTION_SELL_UNIT, value: 12, input: "SellUnit", meaning: "Sell the vehicle or aircraft under the cursor." }
  - { constant: ACTION_NO_SELL, value: 13, input: "NoSell", meaning: "Indicate that selling is unavailable." }
  - { constant: ACTION_NO_REPAIR, value: 14, input: "NoRepair", meaning: "Indicate that repair is unavailable." }
  - { constant: ACTION_SABOTAGE, value: 15, input: "Sabotage", meaning: "Enter and sabotage the object under the cursor." }
  - { constant: ACTION_TOTE, value: 16, input: "Tote", meaning: "Send an empty carryall to pick up the allied vehicle under the cursor." }
  - { constant: ACTION_PARA_INFANTRY, value: 17, input: "DontUse2", meaning: "Legacy parachute-infantry action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_PARA_SABOTEUR, value: 18, input: "DontUse3", meaning: "Legacy parachute-saboteur action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_NUKE_BOMB, value: 19, input: "Nuke", meaning: "Target a nuclear or multi-missile strike." }
  - { constant: ACTION_AIR_STRIKE, value: 20, input: "DontUse4", meaning: "Legacy air-strike action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_CHRONOSPHERE, value: 21, input: "DontUse5", meaning: "Legacy chronosphere source action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_CHRONO2, value: 22, input: "DontUse6", meaning: "Legacy chronosphere destination action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_IRON_CURTAIN, value: 23, input: "DontUse7", meaning: "Legacy invulnerability action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_SPY_MISSION, value: 24, input: "DontUse8", meaning: "Legacy reconnaissance action.", note: "No ordinary order produces this action; only a superweapon can use it." }
  - { constant: ACTION_GUARD_AREA, value: 25, input: "GuardArea", meaning: "Guard the location or object under the cursor." }
  - { constant: ACTION_HEAL, value: 26, input: "Heal", meaning: "Heal the damaged allied infantry under the cursor." }
  - { constant: ACTION_DAMAGE, value: 27, input: "Damage", meaning: "Enter and damage the building under the cursor." }
  - { constant: ACTION_GREPAIR, value: 28, input: "GRepair", meaning: "Repair the damaged ally under the cursor, or repair a bridge through its repair hut." }
  - { constant: ACTION_NO_DEPLOY, value: 29, input: "NoDeploy", meaning: "Indicate that deployment is unavailable." }
  - { constant: ACTION_NO_ENTER, value: 30, input: "NoEnter", meaning: "Indicate that entry is unavailable." }
  - { constant: ACTION_NO_GREPAIR, value: 31, input: "NoGRepair", meaning: "Indicate that the allied building under the cursor needs no repair, or that a repair hut's bridge cannot be repaired." }
  - { constant: ACTION_TOGGLE_POWER, value: 32, input: "TogglePower", meaning: "Toggle a building's power state." }
  - { constant: ACTION_NO_TOGGLE_POWER, value: 33, input: "NoTogglePower", meaning: "Indicate that power toggling is unavailable." }
  - { constant: ACTION_ENTER_TUNNEL, value: 34, input: "EnterTunnel", meaning: "Enter a tunnel." }
  - { constant: ACTION_NO_ENTER_TUNNEL, value: 35, input: "NoEnterTunnel", meaning: "Indicate that tunnel entry is unavailable." }
  - { constant: ACTION_EMPULSE, value: 36, input: "EMPulse", meaning: "Target an EMPulse superweapon." }
  - { constant: ACTION_ION_CANNON, value: 37, input: "IonCannon", meaning: "Target an ion-cannon strike." }
  - { constant: ACTION_EMPULSE_RANGE, value: 38, input: "EMPulseRange", meaning: "Refuse the target: the player has no powered EM pulse cannon, or the nearest one cannot reach the target." }
  - { constant: ACTION_CHEM_BOMB, value: 39, input: "ChemBomb", meaning: "Target a chemical missile strike." }
  - { constant: ACTION_PLACE_WAYPOINT, value: 40, input: "PlaceWaypoint", meaning: "Place a waypoint." }
  - { constant: ACTION_NO_PLACE_WAYPOINT, value: 41, input: "NoPlaceWaypoint", meaning: "Indicate that a waypoint cannot be placed." }
  - { constant: ACTION_ENTER_WAYPOINT_MODE, value: 42, input: "EnterWaypointMode", meaning: "Enter waypoint planning mode." }
  - { constant: ACTION_FOLLOW_WAYPOINT, value: 43, input: "FollowWaypoint", meaning: "Cursor for a move order given over one of the player's waypoints." }
  - { constant: ACTION_SELECT_WAYPOINT, value: 44, input: "SelectWaypoint", meaning: "Select the path of the waypoint under the cursor and pick that waypoint up to drag it." }
  - { constant: ACTION_LOOP_WAYPOINT_PATH, value: 45, input: "LoopWaypointPath", meaning: "Loop the selected path back to the waypoint under the cursor." }
  - { constant: ACTION_DRAG_WAYPOINT, value: 46, input: "DragWaypoint", meaning: "Drag an existing waypoint." }
  - { constant: ACTION_ATTACK_WAYPOINT, value: 47, input: "AttackWaypoint", meaning: "Cursor for an attack or harvest order given over one of the player's waypoints." }
  - { constant: ACTION_ENTER_WAYPOINT, value: 48, input: "EnterWaypoint", meaning: "Cursor for an enter or capture order given over one of the player's waypoints." }
  - { constant: ACTION_PATROL_WAYPOINT, value: 49, input: "PatrolWaypoint", meaning: "Patrol a waypoint path." }
  - { constant: ACTION_DROP_POD, value: 50, input: "DropPod", meaning: "Target a drop-pod delivery." }
  - { constant: ACTION_RALLY_TO_POINT, value: 51, input: "Rally To Point", meaning: "Set a rally point." }
  - { constant: ACTION_ATTACK_SUPPORT, value: 52, input: "Attack Support", meaning: "Put an object whose first weapon slot has negative damage on Guard Area, and any other object on Guard." }
---

These are the actions a left click on the map can carry. The action under the cursor picks the mouse shape and decides what a click does. The trigger actions that a map's triggers run are a separate list.

A SuperWeaponType's [`Action`](/keys/action/#scope-superweapontype) is the only rules setting that takes one of these names, matched without regard to case. It decides whether clicking the weapon's charged cameo fires the weapon at once or starts targeting, and which action a click on the map must carry to fire it. The key page covers both, including what happens when two weapons name the same action.

A superweapon that names one of the `DontUse` actions shows the ordinary arrow as its targeting cursor, and a click on the map fires it.
