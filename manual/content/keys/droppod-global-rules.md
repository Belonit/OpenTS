---
key: DropPod
summary: The marks a drop pod leaves on the ground where it touches down.
see_also: [Droppod, AtmosphereEntry, DropPodPuff, "system:drop-pods"]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
DropPod=MYPOD_NE,MYPOD_NW,MYPOD_SE,MYPOD_SW ; AnimTypes registered in [Animations]
```

When a pod lands and its passenger is placed, one animation from this list plays at the landing point. The approach direction picks the entry, wrapping to the start of a list shorter than four, as [Approach selection](/systems/drop-pods/#approach-selection) shows. A passenger that cannot be placed is destroyed instead, and no animation from this list plays; [Touchdown](/systems/drop-pods/#touchdown) covers that case.

Give the list at least one entry. An empty list, including `DropPod=none`, crashes the game the first time a passenger is placed at touchdown.

A name that the [`[Animations]` list](/formats/rules-registries/) does not register is accepted and becomes a new animation type. The retail `DropPod` value ends with two such names, `DROPPODY` and `DROPPODY2`, so the SE and SW landing animations exist only because this key names them.

This is not the TeamType flag. [`Droppod`](/keys/droppod-teamtype/) with a lowercase second `p` is a separate key.
