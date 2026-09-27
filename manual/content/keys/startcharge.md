---
key: StartCharge
summary: The charge a vehicle is created with, which only a mobile EMP vehicle spends.
see_also: ["system:emp-pulse"]
when_omitted:
  kind: value
  value: "0"
---

The value sets a vehicle's charge only when the vehicle is created. From there the charge rises toward [`MaxCharge`](/keys/maxcharge/). An [`IsMobileEMP=yes`](/keys/ismobileemp/) vehicle's pulse resets its charge to `0`, so this value affects only its first pulse.

Set it to `MaxCharge` or above to let a mobile EMP vehicle discharge as soon as it is created.
