---
key: DropPodPuff
summary: Parsed animation reference that drop-pod logic never uses.
no_effect: true
see_also: [DropPod, DropPodWeapon, "system:drop-pods"]
when_omitted:
  kind: value
  value: none
---

No game effect creates this animation. A falling pod's smoke trail is the fixed `SMOKEY` animation, which appears only while [`DropPodWeapon`](/keys/droppodweapon/) is set. The landing animation comes from [`DropPod`](/keys/droppod-global-rules/).
