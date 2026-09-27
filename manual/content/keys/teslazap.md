---
key: TeslaZap
summary: Parsed sound that no structure plays when a charged weapon fires.
no_effect: true
see_also: [TeslaCharge, Charges, IsLaser]
when_omitted:
  kind: value
  value: none
---

No structure plays this sound when it fires. The shot that follows a charge makes only the sounds its own weapon names.

The companion sound [`TeslaCharge`](/keys/teslacharge/) does play, as a structure with a [`Charges=yes`](/keys/charges/) primary weapon starts charging.
