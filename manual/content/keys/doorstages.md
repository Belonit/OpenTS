---
key: DoorStages
summary: The number of frames the factory door animation steps through.
see_also: ["DoorAnim", "DamagedDoor", "DeployTime", "GateStages", "system:production"]
when_omitted:
  kind: value
  value: "0"
---

`DoorStages` is the number of healthy frames in the [`DoorAnim`](/keys/dooranim/) animation. While the door opens over [`DeployTime`](/keys/deploytime/), it steps evenly through frames `0` to `DoorStages - 1`. A closing door runs the same frames in reverse, and a shut door shows frame `0`. With `DoorStages=9`, the door's travel shows frames `0` through `8`.

```ini title="art.ini"
[MYWEAP] ; example war factory, drawn from its own Image ID
DoorAnim=GAWEAP_D
DoorStages=9
```

At `0`, the door animation stays on frame `0` throughout.

A [`DamagedDoor=yes`](/keys/damageddoor/) structure whose health is at or below [`ConditionYellow`](/keys/conditionyellow/) shows the damaged frames instead. They follow the healthy block: frames `DoorStages` through `2 × DoorStages - 1`. The door artwork must then hold both blocks, healthy first.
