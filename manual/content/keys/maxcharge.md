---
key: MaxCharge
summary: The charge a mobile EMP vehicle must reach before it may discharge.
see_also: ["system:emp-pulse"]
when_omitted:
  kind: value
  value: "0"
---

The vehicle gains one point of charge each game frame it is not immobilized, and stops gaining at this value. It may discharge once its charge reaches this value, and a pulse empties the charge. After a pulse, the vehicle therefore needs this many game frames before it can fire again, not counting frames spent immobilized.

With [`PipScale=Charge`](/keys/pipscale/), the pip bar shows how much of this value the charge has reached.

:::caution[Keep `MaxCharge` above `0`]
At `0` the vehicle may discharge from the moment it appears, and again right after every pulse.
:::
