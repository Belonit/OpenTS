---
key: RefundPercent
summary: The fraction of an object's price handed back when a human player's house sells it.
see_also: ["system:repair", "system:production"]
when_omitted:
  kind: value
  value: ".5"
---

```ini title="rules.ini"
[General]
RefundPercent=.75   ; a human player's sale returns three quarters of the price
```

A human player's house receives this fraction of an object's price when it sells the object. The price is what the house would pay for the type, [multipliers included](/keys/cost/#what-a-house-pays), and the refund is truncated to whole credits. Damage does not reduce it, so a structure one point from destruction sells for as much as an undamaged one.

Computer houses always receive the full price. In a campaign, the fraction applies to every house the local player controls: the player's house and any house the scenario marks [`PlayerControl=yes`](/keys/playercontrol/). In other games, it applies to every house a human plays.

The fraction applies to four payments:

- selling a structure;
- [selling a vehicle or aircraft parked at a service depot](/systems/repair/#selling-at-the-pad);
- selling a structure's upgrade. A sell order on a structure with an upgrade removes and refunds its newest upgrade, and the structure stays;
- the compensation paid when a structure undeploys and the vehicle it becomes cannot be created or placed. The payment is based on the structure's price.

Canceling something still under construction is different: it [refunds everything paid so far](/systems/production/#paying-for-it).
