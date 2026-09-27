---
key: DropPodAngle
summary: Drop-pod descent angle in radians, clamped to 22.5-67.5 degrees when rules load.
see_also: [DropPodHeight, DropPodSpeed, "system:drop-pods"]
---

`DropPodAngle` is the angle of a pod's fall above the horizontal, in radians. A larger angle gives a steeper, shorter fall that starts closer to the landing cell. A smaller angle gives a flatter, longer approach.

The angle also sets how far to the side the pod starts, as [Approach selection](/systems/drop-pods/#approach-selection) describes.

The engine clamps the value to `pi/8` through `3*pi/8` radians (22.5 to 67.5 degrees) whenever it reads a `[General]` section. Leaving the key unset therefore gives a 67.5-degree fall.

```ini title="rules.ini"
[General]
DropPodAngle=0.785398   ; 45 degrees
```
