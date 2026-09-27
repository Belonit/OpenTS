---
key: BuildTime
scope: housetype
label: Country build-time multiplier
when_omitted:
  kind: value
  value: "1.0"
---

Every object a house of this country produces has its build time multiplied by this value, so a value above 1 builds more slowly and one below 1 builds faster.

```ini title="rules.ini"
[NOD]
BuildTime=1.2 ; example: NOD objects take 20% longer to build
```

Outside a campaign game, the house multiplies this value by [the difficulty section's `BuildTime=`](/keys/buildtime/#scope-difficulty-settings) and [`GameSpeedBias`](/keys/gamespeedbias/) once, [when it is given its difficulty slot](/systems/difficulty/#how-the-figures-are-combined). A campaign game leaves the country's value out and keeps the other two.
