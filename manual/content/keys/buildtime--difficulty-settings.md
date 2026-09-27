---
key: BuildTime
scope: difficulty-settings
label: Difficulty build-time multiplier
when_omitted:
  kind: value
  value: "1"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section without this key restores 1 rather than keeping the earlier value.
---

`[Easy]`, `[Normal]` and `[Difficult]` each set their own multiplier, and a house takes the one for [its difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). Every object that house produces has its build time multiplied by it, so a value above 1 builds more slowly and one below 1 builds faster.

```ini title="rules.ini"
[Difficult]
BuildTime=0.8 ; example: objects on this difficulty take 20% less time to build
```

[When the house is given its slot](/systems/difficulty/#how-the-figures-are-combined), it multiplies this value by [`GameSpeedBias`](/keys/gamespeedbias/) and, outside a campaign game, by [its country's `BuildTime=`](/keys/buildtime/#scope-housetype). [How long it takes](/systems/production/#how-long-it-takes) places the result among the other build-time factors.
