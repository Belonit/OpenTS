---
key: BridgeRepairHut
summary: Turns the structure into the one an engineer walks into to rebuild a destroyed bridge.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

An engineer that walks into a hut [repairs the bridge beside it](/systems/capture/#repairing-a-bridge) and is used up. That replaces the engineer's usual effects: the hut is never restored and never changes hands. Neither the hut's owner nor its strength changes the outcome.

A player's engineer gets the repair cursor over a hut while a bridge within two cells of it can be repaired, and the refusal cursor otherwise. Over a hut whose bridge is intact, the engineer gets only the refusal cursor. Over a visible hut this cursor needs [`Repairable=yes`](/keys/repairable/), which is the default. Over a hut seen only as a fogged record, the cursor appears whatever `Repairable` says.

Infantry and vehicles treat a non-allied hut's cell as impassable. They never plan a route through it by destroying the hut, as armed ones would through another enemy structure.

A hut that also sets [`Immune=yes`](/keys/immune/#scope-aircrafttype) takes no damage at all. That includes the forced damage that ordinarily gets past `Immune=yes`.
