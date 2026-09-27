---
key: RepairSell
summary: The IQ a house needs before it repairs its damaged structures by itself or sells them when money runs short.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "3"
---

A house needs an [`IQ`](/keys/iq/) at or above this value before it repairs its damaged structures by itself, or sells damaged ones when its money runs short. It is the first test in [the computer's repair decision](/systems/repair/#when-the-computer-repairs), and the sale rules use the same test.

Outside campaign games, every computer player has the maximum IQ, so the test passes for it whenever `RepairSell` is at or below [`MaxIQLevels`](/keys/maxiqlevels/). This includes a house taken over after its player leaves. Houses the map defines keep the IQ the map gives them, `0` when unset. That covers every house in a campaign, and houses such as Neutral in other games.

A computer house repairs only structures that were captured or flagged for repair, but a human-controlled house skips that test. When a map gives the player's house an `IQ` at or above this value, that house repairs every damaged structure it owns without a click, while it has the money.

The same `IQ` lets [the sale rules](/systems/repair/#when-the-computer-repairs) sell the player's damaged structures when money runs short.
