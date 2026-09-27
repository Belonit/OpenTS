---
key: SellBack
summary: The tech level a house must have reached before the computer will sell a building it cannot afford to repair.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "2"
---

A computer house sells a badly damaged building it cannot afford to repair only if its tech level is at or above this value. The comparison is with the house's tech level, not its [`IQ`](/keys/iq/).

The same tech level also sets how soon the sale happens. On each frame that the other conditions hold, a random number from `0` through `50` must come out below the tech level. At tech level 5 that happens on about one frame in ten, and above tech level 50 it happens every time. Because the draw repeats, a low tech level delays the sale but does not prevent it. A house at tech level `0` never passes the draw.

The other conditions include money below [`CreditReserve`](/keys/creditreserve/), damage from a house that is not an ally, no trigger tag on the building, and health below [`ConditionRed`](/keys/conditionred/). [When the computer repairs](/systems/repair/#when-the-computer-repairs) lists all of them in order.
