---
key: VeinholeShrinkRate
summary: Game frames between the withering steps of a destroyed monster's field.
see_also: ["system:veins", "VeinholeGrowthRate"]
when_omitted:
  kind: value
  value: "100"
---

After a veinhole monster is [destroyed](/systems/veins/#destruction), its field withers in steps this many frames apart, plus a random extra of up to half as many. The first withering step comes when the monster's next growth step would have come.

Each step withers 1 to 4 of the monster's mature cells, farthest from the veinhole first. The monster is removed once no mature cell is left. Withering continues while [`VeinGrowthEnabled`](/keys/veingrowthenabled/) is off, so this value decides how long a destroyed field lingers.
