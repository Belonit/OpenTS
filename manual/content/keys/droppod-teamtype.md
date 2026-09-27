---
key: Droppod
summary: Makes an infantry-only TeamType arrive by drop pod.
see_also: [DropPod, "system:drop-pods"]
when_omitted:
  kind: value
  value: "no"
---

`Droppod=yes` makes a reinforcement team of infantry arrive by drop pod, landing near its waypoint instead of arriving the ordinary way. [Drop pods](/systems/drop-pods/#droppod-teamtype) describes where each member lands and what can destroy it on landing.

```ini title="ai.ini or map file"
[MyDropTeam] ; example TeamType
Droppod=yes
TaskForce=MyInfantryTaskForce ; defined under [TaskForces]
```

The pods are used only under **all of:**

- the team is delivered by the [Reinforcement (team)](/mapping/actions/taction-reinforcements/) or [Reinforcement (team) at waypoint](/mapping/actions/taction-reinforcements-special/) trigger action;
- every member of the team's TaskForce is an InfantryType.

Teams the AI creates and fills by recruiting never arrive by pod.

:::caution[One non-infantry member cancels the pods]
If any TaskForce member is a vehicle, aircraft or other non-infantry type, the whole team arrives as an ordinary reinforcement. Its infantry do not drop.
:::

The `[AudioVisual]` animation list is a different key, spelled [`DropPod`](/keys/droppod-global-rules/) with an uppercase second `P`.
