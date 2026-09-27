---
key: DropPodHeight
summary: Initial drop-pod altitude above the landing cell, measured in leptons.
see_also: [DropPodAngle, DropPodSpeed, "system:drop-pods"]
---

A pod starts its fall this many leptons above the ground at its landing cell. Together with [`DropPodAngle`](/keys/droppodangle/), the height also sets how far to the side the pod starts. [Approach selection](/systems/drop-pods/#approach-selection) gives that distance and how the start point picks the approach direction.

A larger value gives a longer fall. It also makes the pod start faster once the height is above about `10 * (DropPodSpeed - 2)` leptons. From a lower height the pod starts at [`DropPodSpeed`](/keys/droppodspeed/). [Descent and airborne effects](/systems/drop-pods/#descent-and-airborne-effects) gives the speed formula.

```ini title="rules.ini"
[General]
DropPodHeight=2000   ; example value
```
