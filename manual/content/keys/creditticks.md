---
key: CreditTicks
summary: The two sounds the credit readout plays as it counts, the first while it rises and the second while it falls.
see_also: ["system:sidebar"]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty, and the game crashes the first time the credit readout counts.
---

During play the credit readout counts toward the house's money in steps and plays one of these sounds at half volume on every step, so a single payment is heard as a run of ticks. The first sound plays while the figure rises and the second while it falls. [The credit readout](/systems/sidebar/#the-credit-readout) covers how large each step is and how often one is taken.

A name that matches no registered sound is dropped from the list, and the names after it move up one position.

:::danger[Give the list two valid sounds]
Only the first two positions are read, and the list is not checked for length. With no entries, the game crashes the first time the player's money changes. With one entry, the falling sound is read from a position the list never filled, which can play the wrong sound or crash the game. Omitting the key leaves the list empty, so every rules tree needs two valid sound names here.
:::
