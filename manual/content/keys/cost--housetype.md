---
key: Cost
scope: housetype
label: Country price multiplier
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1.0"
---

A house of this country pays [each object's `Cost=`](/keys/cost/#scope-aircrafttype) multiplied by this value, so a value above 1 makes everything it builds more expensive. Build times do not change, because they come from the unmultiplied `Cost=`.

```ini title="rules.ini"
[NOD]
Cost=1.25 ; example: NOD pays 25% more for everything it builds
```

The multiplied price also applies where the game values an object the house owns:

- Selling refunds the multiplied price, reduced by [`RefundPercent=`](/keys/refundpercent/) when a human plays the house. A captured object is valued at its new owner's multiplier.
- A house that destroys or captures one of its objects adds the multiplied price to its score.
- A structure's [survivor count](/keys/survivordivisor/) is worked out from the multiplied price, so a higher value gives more survivors, still no more than 5.

Repairs do not use the multiplier.

Outside a campaign game, the house multiplies this value by [the difficulty section's `Cost=`](/keys/cost/#scope-difficulty-settings) once, [when it is given its difficulty slot](/systems/difficulty/#how-the-figures-are-combined). A campaign game leaves the country's value out, so it affects skirmish and multiplayer games only.
