---
key: Cost
scope: difficulty-settings
label: Difficulty price multiplier
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section without this key restores 1 rather than keeping the earlier value.
---

`[Easy]`, `[Normal]` and `[Difficult]` each set a price multiplier for the houses in [their difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). A house pays about each object's [`Cost=`](/keys/cost/#scope-aircrafttype) times this multiplier, so a value above 1 makes everything it buys more expensive. The price of [a structure that comes with a unit or aircraft](/keys/cost/#what-a-structure-gives-away) is multiplied in parts and can differ from that product. A factory charges that multiplied price over the production steps, and a computer house compares it with its credits when it decides what it can afford to build.

```ini title="rules.ini"
[Difficult]
Cost=1.2
```

The multiplier does not change build time. [`BuildTime=`](/keys/buildtime/#scope-difficulty-settings) in the same section sets that.

Outside a campaign, the house also applies its [country's multiplier](/keys/cost/#scope-housetype). [What a house pays](/keys/cost/#what-a-house-pays) shows how the two combine.
