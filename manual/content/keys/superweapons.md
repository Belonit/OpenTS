---
key: SuperWeapons
summary: The house intelligence level at which a computer house begins firing its superweapons in a campaign.
see_also: [IQ, "system:superweapons"]
when_omitted:
  kind: value
  value: "4"
---

In a campaign, a computer house fires its ready superweapons only while its [`IQ`](/keys/iq/) is at least this value. A campaign house takes `IQ=` from its section in the scenario. It has 0 when the section sets none, and 1 when the value is above [`MaxIQLevels`](/keys/maxiqlevels/). Outside a campaign, the check is skipped, and every computer house fires its superweapons whatever its `IQ`.

The threshold does not affect charging. A campaign house whose `IQ` is below it still charges its superweapons but never fires them. [The computer's use](/systems/superweapons/#the-computers-use) covers when and where a computer house fires each one.
