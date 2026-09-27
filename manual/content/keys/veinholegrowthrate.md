---
key: VeinholeGrowthRate
summary: Game frames between one veinhole monster's growth steps.
see_also: ["system:veins", "VeinholeShrinkRate", "MaxVeinholeGrowth"]
when_omitted:
  kind: value
  value: "100"
---

A veinhole monster takes its first growth step this many frames after it is created. Each later step comes this many frames after the previous one, plus a random extra of up to half as many. Steps therefore come 1 to 1.5 times this interval apart.

```ini title="rules.ini"
[General]
VeinholeGrowthRate=300  ; a step every 300 to 450 frames, or 20 to 30 seconds
```

Each step takes 1 to 5 cells from the monster's growth queue, and [Growth](/systems/veins/#growth) decides which of them mature. A shorter interval spreads a field faster only while the monster is under its [`MaxVeinholeGrowth`](/keys/maxveinholegrowth/) limits and has neighboring ground that accepts veins. While the scenario's [`VeinGrowthEnabled`](/keys/veingrowthenabled/) switch is off, steps still come due but grow nothing.
