---
key: MultiplayerAICM
summary: The percentage of its starting money added to each computer house outside a campaign, one entry per difficulty.
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty and the difficulty slot is used to index it anyway, reading storage that was never allocated.
---

Outside a campaign, each computer house gets extra credits as the scenario finishes loading. The house's credits plus the value of its stored Tiberium are multiplied by its entry as a percentage, and the result is added to what it already has. An entry of `100` doubles the house's starting money, and `0` adds nothing.

Houses whose type sets [`MultiplayPassive=yes`](/keys/multiplaypassive/) get nothing.

Each computer house reads the entry for its [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). Entry 0 is used at the Hard setting and entry 2 at Easy. [`CompEasyBonus`](/keys/compeasybonus/) and a [launch file's](/formats/spawn-ini/#who-is-playing) handicaps can move a house to another slot.

:::caution[Give the list three entries]
A computer house whose slot has no entry reads past the end of the list and receives an unpredictable amount, or the game crashes when the list is empty.
:::
