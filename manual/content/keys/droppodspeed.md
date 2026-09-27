---
key: DropPodSpeed
summary: Minimum per-frame movement speed for a descending drop pod.
see_also: [DropPodAngle, DropPodHeight, "system:drop-pods"]
---

A falling pod never moves less than `DropPodSpeed` leptons per frame. High above the ground it moves faster, and it slows as it descends until this value takes over. [Descent and airborne effects](/systems/drop-pods/#descent-and-airborne-effects) gives the formula.

The speed is measured along the pod's slanted line of fall, not straight down. [`DropPodAngle`](/keys/droppodangle/) splits it between horizontal and vertical movement.
